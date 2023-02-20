#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

class HeapSort {
	vector<int>arr;//��������
	int file_num;//��Ҫ����������ļ���

	//���ļ��е����ݶ�ȡ��������
	void read() {
		ifstream ifs;
		string File_Name = "0.txt";//�ļ���
		File_Name[0] = '0' + (file_num - 1);

		ifs.open(File_Name, ios::in);//���ļ�
		if (!ifs.is_open()) {//�ж��ļ��Ƿ�򿪳ɹ�
			cout << "�ļ���ʧ��" << endl;
			return;
		}

		int a;
		while (ifs >> a) {
			arr.push_back(a);
		}

		ifs.close();
	}

	//���ضѵ������ʾ�У�һ����������ʾ��Ԫ�صĸ��׽ڵ������
	int getFather(int i) {
		return (i - 1) / 2;
	}

	//���ضѵ������ʾ�У�һ����������ʾ��Ԫ�ص����ӽڵ������
	int getLeftChind(int i) {
		return 2 * i + 1;
	}

	//��������Ԫ�ص�λ��
	void swap(int i, int j) {
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	//��data[0,n)���γɵ������У�����index��Ԫ�أ�ִ��siftDown
	void SiftDown(int index, int n) {
		while (getLeftChind(index) < n) {
			int l = getLeftChind(index);
			if (l + 1 < n && arr[l + 1] > arr[l]) {
				l++;//�Һ��ӵ�����Ϊ����������1
			}
			//��ʱdata[l]��leftChild��rightChild�е����ֵ

			if (arr[l] <= arr[index]) break;
			else {
				swap(index, l);
				index = l;
			}
		}
	}


	//������
	void heapsort() {
		for (int i = getFather(arr.size() - 1); i >= 0; i--) {//�ӵ�һ����Ҷ�ӽڵ㿪ʼ
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

	//������
	void sort()
	{
		read();
		int start_time = clock();

		heapsort();

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "����������ʱ��Ϊ:" << total_time << "ms" << endl;
	}

};
