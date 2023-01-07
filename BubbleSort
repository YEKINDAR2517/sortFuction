#include<iostream>
#include<vector>
using namespace std;

vector<int>arr;
int length = arr.size();//数组长度 

//冒泡排序
void BubbleSort(vector<int>&arr) 
{
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//优化的冒泡排序 
void BubbleSort2(vector<int>&arr)
{
	for (int i = length - 1; i > 0; i--) {
		bool isSwapped = 0;   //是否进行过交换

		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;

				isSwapped = 1;
			}
		}

		if (isSwapped == 0) break;
	}
}

//进一步优化的冒泡排序 
void BubbleSort3(vector<int>&arr)
{
	for (int i = 0; i < length - 1;) {
		int lastSwappedIndex = 0;    //最后一次做交换的索引

		for (int j = 0; j < length - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;

				lastSwappedIndex = j + 1;
			}
		}
		i = length - lastSwappedIndex;
	}
}
