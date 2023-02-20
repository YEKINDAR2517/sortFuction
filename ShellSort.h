#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

//希尔排序
class ShellSort {
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

public:
	ShellSort(int file_num) {
		this->file_num = file_num;
	}

	void shell_sort() {
		int h = 1;
		while (h < arr.size() / 3) h = h * 3 + 1;

		while (h >= 1) {

			//对data[h,n)进行插入排序
			for (int i = h; i < arr.size(); i++) {
				int t = arr[i];//暂时存储当前数据
				int j;
				for (j = i; j - h >= 0 && arr[j - h] > t; j -= h) {
					arr[j] = arr[j - h];
				}
				arr[j] = t;
			}

			h /= 3;
		}
	}

	//将数组进行希尔排序
	void sort() {
		read();

		int start_time = clock();

		shell_sort();

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "希尔排序所用时间为:" << total_time << "ms" << endl;
	}
};
