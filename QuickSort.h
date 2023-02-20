#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

//��������
class QuickSort {
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

	//������������Ԫ�ؽ���
	void swap(int i, int j) {
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	//�������ĵ�λ��(���ΪС�ڵ��ڸ�ֵ�������ұ�Ϊ���ڵ��ڸ�ֵ����)
	int partition(int l, int r) {
		//����[l,r]֮����������
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

	//��������
	void sort()
	{
		read();
		int start_time = clock();
		//���п�������
		sort(0, arr.size() - 1);

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "������������ʱ��Ϊ:" << total_time << "ms" << endl;
	}
};

