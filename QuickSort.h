#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

//快速排序
class QuickSort {
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

	void sort(int l, int r) {
		if (l >= r) return;

		int p = partition(l, r);
		sort(l, p - 1);
		sort(p + 1, r);
	}

public:
	QuickSort(int file_num) {
		this->file_num = file_num;
	}

	//将数组中两个元素交换
	void swap(int i, int j) {
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	//返回中心点位置(左边为小于等于该值的数，右边为大于等于该值的数)
	int partition(int l, int r) {
		//生成[l,r]之间的随机索引
		int p = l + (rand() % (r - l + 1));
		swap(l, p);

		//arr[l+1...i-1]<=v,arr[j+1...r]>=v
		int i = l + 1, j = r;
		while (1) {
			while (i <= j && arr[i] < arr[l]) i++;
			while (i <= j && arr[j] > arr[l]) j--;

			if (i >= j) break;

			swap(i, j);
			i++;
			j--;
		}
		swap(l, j);

		return j;
	}

	//快速排序
	void sort()
	{
		read();
		int start_time = clock();
		//进行快速排序
		sort(0, arr.size() - 1);

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "快速排序所用时间为:" << total_time << "ms" << endl;
	}
};

