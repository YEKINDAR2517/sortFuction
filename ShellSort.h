#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

//ϣ������
class ShellSort {
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

public:
	ShellSort(int file_num) {
		this->file_num = file_num;
	}

	void shell_sort() {
		int h = 1;
		while (h < arr.size() / 3) h = h * 3 + 1;

		while (h >= 1) {

			//��data[h,n)���в�������
			for (int i = h; i < arr.size(); i++) {
				int t = arr[i];//��ʱ�洢��ǰ����
				int j;
				for (j = i; j - h >= 0 && arr[j - h] > t; j -= h) {
					arr[j] = arr[j - h];
				}
				arr[j] = t;
			}

			h /= 3;
		}
	}

	//���������ϣ������
	void sort() {
		read();

		int start_time = clock();

		shell_sort();

		int end_time = clock();
		int total_time = end_time - start_time;
		cout << "ϣ����������ʱ��Ϊ:" << total_time << "ms" << endl;
	}
};
