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

//选择排序 
void SelectionSort(vector<int>&arr)
{
	int temp, max;//temp记录最大值位置 
	for (int i = length - 1; i > 0; i--) {
		max = arr[0];
		temp = 0;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > max) {
				max = arr[j];
				temp = j;
			}
		}
		swap(arr, i, temp);
	}
}
