#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

class RadixSort {
	vector<int>arr;//储存数据
	int file_num;//需要进行排序的文件名

	//将文件中的数据读取到数组中
	void read() {
		ifstream ifs;
		string File_Name = "0.txt";//文件名
		File_Name[0] = '0' + (file_num - 1);

		ifs.open(File_Name, ios::in);//打开文件
		if (!ifs.is_open()) {//判断文件是否打开成功
			cout << "文件打开失败" << endl;
			return;
		}

		int a;
		while (ifs >> a) {
			arr.push_back(a);
		}

		ifs.close();
	}

	void radixsort() {
		int max = arr[0];
		for (int a : arr) {
			if (a > max) max = a;
		}

		int base = 1;
		int* temp = new int[arr.size()];
		while (max / base > 0) {
			int bucket[10] = { 0 };//桶

			for (int i = 0; i < arr.size(); i++) {
				bucket[arr[i] / base % 10]++;
			}
			for (int i = 1; i < 10; i++) {
				bucket[i] += bucket[i - 1];
			}
			for (int i = arr.size() - 1; i >= 0; i--) {
				temp[bucket[arr[i] / base % 10] - 1] = arr[i];
				bucket[arr[i] / base % 10]--;
			}
			for (int i = 0; i < arr.size(); i++) {
				arr[i] = temp[i];
			}

			base *= 10;
		}
	}

public:
	RadixSort(int file_num) {
		this->file_num = file_num;
	}

	//基数排序
	void sort()
	{
		read();
		int start_time = clock();

		radixsort();

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "基数排序所用时间为:" << total_time << "ms" << endl;
	}
};
