//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void BubbleSort(int data[], int n);
//
//int main()
//{
//	int arr[1000];
//
//	int num; //사람수
//	cin >> num;
//
//	int time = 0; //필요한시간의 최솟값
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> arr[i];
//	}
//
//	BubbleSort(arr, num);
//
//	for (int i = 0; i < num; i++)
//	{
//		//1 1
//		//1+2 3
//		//1+2+3 6
//		//1+2+3+3 9
//		//1+2+3+3+4 13
//
//		for (int j = 0; j < i+1; j++)
//		{
//			time += arr[j];
//		}
//		
//	}
//
//	cout << time;
//}
//
//void BubbleSort(int data[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = n - 1; j > i; j--)
//		{
//			if (data[j] < data[j - 1])
//			{
//				swap(data[j], data[j - 1]);
//			}
//		}
//	}
//}