#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

class HeapSort {
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

	//返回堆的数组表示中，一个索引所表示的元素的父亲节点的索引
	int getFather(int i) {
		return (i - 1) / 2;
	}

	//返回堆的数组表示中，一个索引所表示的元素的左孩子节点的索引
	int getLeftChind(int i) {
		return 2 * i + 1;
	}

	//交换两个元素的位置
	void swap(int i, int j) {
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	//对data[0,n)所形成的最大堆中，索引index的元素，执行siftDown
	void SiftDown(int index, int n) {
		while (getLeftChind(index) < n) {
			int l = getLeftChind(index);
			if (l + 1 < n && arr[l + 1] > arr[l]) {
				l++;//右孩子的索引为左孩子索引加1
			}
			//此时data[l]是leftChild和rightChild中的最大值

			if (arr[l] <= arr[index]) break;
			else {
				swap(index, l);
				index = l;
			}
		}
	}


	//堆排序
	void heapsort() {
		for (int i = getFather(arr.size() - 1); i >= 0; i--) {//从第一个非叶子节点开始
			SiftDown(i, arr.size());
		}

		for (int i = arr.size() - 1; i >= 0; i--) {
			swap(0, i);
			SiftDown(0, i);
		}
	}

public:
	HeapSort(int file_num) {
		this->file_num = file_num;
	}

	//堆排序
	void sort()
	{
		read();
		int start_time = clock();

		heapsort();

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "堆排序所用时间为:" << total_time << "ms" << endl;
	}

};
