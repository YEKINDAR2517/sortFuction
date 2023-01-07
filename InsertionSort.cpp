#include<iostream>
using namespace std;
#include<vector>

vector<int>arr;
int length = arr.size();//数组长度

//交换数组中两个元素
void swap(vector<int>&arr, int i, int j)
{
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

//插入排序
void InsertionSort(vector<int>&arr)
{
	for (int i = 1; i < length; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
			}
		}
	}
}
