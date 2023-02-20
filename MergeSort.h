#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

class MergeSort {
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

	//�ϲ��������������arr[l,mid]��arr[mid+1,r]
	void merge(int l, int mid, int r) {
		//��arr[l,r]���Ƶ�temp
		int* temp = new int[r + 1 - l];
		for (int i = l; i <= r; i++) {
			temp[i - l] = arr[i];
		}

		int i = l, j = mid + 1;
		//ÿ��ѭ��Ϊarr[k]��ֵ
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

	//Ϊ����arr[l,r]����
	void mergesort(int l, int r) {
		if (l >= r) return;//���������޻���ֻ��һ��Ԫ��
		int mid = l + (r - l) / 2;

		//��arr[l,mid]����
		mergesort(l, mid);
		//��arr[mid+1,r]����
		mergesort(mid + 1, r);
		//��������������ϲ�
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
		cout << "�鲢��������ʱ��Ϊ:" << total_time << "ms" << endl;
	}
};
