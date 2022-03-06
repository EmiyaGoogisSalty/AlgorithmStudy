//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void bubblesort(int data[], int num);
//
//int main()
//{
//	
//	int n = 0;
//	cin >> n;
//
//	int arr[1000] = { 0 };
//
//	for (int i = 0; i < n ; i++)
//	{
//		cin >> arr[i];
//	}
//
//	bubblesort(arr, n);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	
//}
//
//void bubblesort(int data[], int num)//정수값 배열, 정수값 배열크기
//{
//	for (int i = 0; i < num - 1; i++)
//		//뒤에어 샆으로 이동하면서 만약에 작은값이 뒤에있으면 스왑
//	{
//		for (int j = num - 1; j > i; j--)
//			//역순으로 진행하면서 num과 num-1을 비교
//		{
//			if (data[j] < data[j - 1])
//			{
//				swap(data[j], data[j - 1]);
//			}
//		}
//	}
//}

//포 반복문 내부문장 실행 횟수 => O(n2) 1/2n(n-1)

/*
*		동작방식
* 
		4 2 3 5 1			먼저 num번과 num-1번과 비교 
		4 2 3 1 5			num이크면 스왑 아니면 컨티뉴 노스왑 
		4 2 1 3 5 
		4 1 2 3 5
		1 4 2 3 5 ... 

		마지막까지 바뀌었다면 data[0]에서 다음으로 넘어가기
		계속계속 진행

*/

