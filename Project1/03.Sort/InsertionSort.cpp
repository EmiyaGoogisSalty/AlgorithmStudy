//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
// 
//void Insertion_Sort(int data[], int n);
//int main()
//{
//	int arr[100];
//
//	int num;
//	cin >> num;
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> arr[i];
//	}
//
//	Insertion_Sort(arr, num);
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//}
//
//void Insertion_Sort(int data[], int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int key = data[i];
//
//		int j = i - 1;
//
//		while (j >= 0 && data[j] > key)
//		{
//			data[j + 1] = data[j];
//			j--;
//		}
//
//		data[j + 1] = key;
//	}
//}
//
//
///*
//
//삽입정렬(intsertion sort)
//정렬되지 않은 부분의 첫 번째 원소를 정렬된 부분의 알맞은 위치에
//삽입하는 과정을 반복
//
//
//		4/	2	3	5	1
//		*	^				0번째원소를 정렬된 곳으로 지정,
//							1번째원소와 비교하는데 1번째원소는 2. 2는 4보다 작기에 스왑
//
//		4	2/	3	5	1	
//		*	*	^			2번째원소는 3. 정렬된 2, 4 에 3을 삽입해야함 
//							2 < 3 <4 이기에 삽입
//
//		2	3	4/	5	1
//		*	*	*	^		3번째원소는 5. 정렬된 2,3,4,와 비교했을때 제일 크기에 그대로둔다.
//		
//
//		2	3	4	5/	1
//		*	*	*	*	^	마지막원소는 1. 정렬된 2,3,4,5보다 작기에 맨 첫줄에 삽입해야함. 
//							이과정에서 value 1은 임시변수에 저장을 하고, 나머지 2345를 다 옆으로 복사한다
//
//		2	3	4	5	5
//
//		2	3	4	4	5
//
//		2	3	3	4	5
//		
//		2	2	3	4	5
//		^					이자리에 임시변수에저장한 1이 삽입됨.
//		
//		1	2	3	4	5	완성.
//
//*/
