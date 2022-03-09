

/*
    선택정렬 (selection sort)
        -    정렬되지 않은 원소들 중에서 최소값을 찾아 맨 왼쪽 원소와 교환
             시간복잡도는 O(n2)이다

		4  2  3  5  1
		*           * swap (최소값을 찾아 왼쪽과 교환)
		1  2  3  5  4
		   *		  자기 자신과 스왑 
		1  2  3  5  4
			  *       자기자신 스왑
		1  2  3  4  5
		         *  *  서로 스왑 
		1  2  3  4  5
		            *  마지막은 자기가 젤 크니까 선택정렬알고리즘을 안타도됨
					
*/

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void SelectionSort(int data[], int num);
//
//int main()
//{
//	int arr[100] = {};
//	int n = 0;
//
//	cin >> n; //배열크기 정하기 
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	SelectionSort(arr, n); //내가 설정한 arr과 n들고 함수로 가기
//	
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//}
//

//void SelectionSort(int data[], int num)
//{
//	for (int i = 0; i < num - 1; i++)
//	{
//		int idx = i;
//
//		// 최소값을 갖는 인덱스(idx)를 알아내자
//		for (int j = i + 1; j < num; j++)
//		{
//			if (data[j] < data[idx])
//			{
//				idx = j;
//			}
//
//		}
//
//		swap(data[i], data[idx]);
//	}
//}