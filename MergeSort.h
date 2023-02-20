#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

class MergeSort {
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

	//合并两个有序的区间arr[l,mid]和arr[mid+1,r]
	void merge(int l, int mid, int r) {
		//将arr[l,r]复制到temp
		int* temp = new int[r + 1 - l];
		for (int i = l; i <= r; i++) {
			temp[i - l] = arr[i];
		}

		int i = l, j = mid + 1;
		//每次循环为arr[k]赋值
		for (int k = l; k <= r; k++) {
			if (i > mid) {
				arr[k] = temp[j - l];
				j++;
			}
			else if (j > r) {
				arr[k] = temp[i - l];
				i++;
			}
			else if (temp[i - l] <= temp[j - l]) {
				arr[k] = temp[i - l];
				i++;
			}
			else {
				arr[k] = temp[j - l];
				j++;
			}
		}

		delete[] temp;
	}

	//为区间arr[l,r]排序
	void mergesort(int l, int r) {
		if (l >= r) return;//该区间内无或者只有一个元素
		int mid = l + (r - l) / 2;

		//给arr[l,mid]排序
		mergesort(l, mid);
		//给arr[mid+1,r]排序
		mergesort(mid + 1, r);
		//将两个有序区间合并
		merge(l, mid, r);
	}

public:
	MergeSort(int file_num) {
		this->file_num = file_num;
	}

	void sort() {
		read();
		int start_time = clock();

		mergesort(0, arr.size() - 1);

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "归并排序所用时间为:" << total_time << "ms" << endl;
	}
};
