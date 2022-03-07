//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void MergeSort(int data[], int left, int right);
//void Merge(int data[], int left,int mid, int right);
//
//int main()
//{
//	int arr[100];
//
//	int num;
//	cin >> num;
//
//	int left = 0;
//	int right = num - 1;
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> arr[i];
//	}
//
//	MergeSort(arr, left, right);
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//
//}
//
//void MergeSort(int data[], int left, int right) 
//					//인자는 배열, 배열의왼쪽, 배열의오른쪽
//{
//	if (left < right) //만약 같으면 배열길이가 1이기 때문에 이프문을 타지않음
//	{
//		int mid = (left + right) / 2; //반갈죽
//		
//		MergeSort(data, left, mid); //자기자신을 다시호출에 반갈죽에 또반갈죽..연속
//		MergeSort(data, mid + 1, right); //오른쪽도 반갈에반갈을 해주자 
//
//		Merge(data, left, mid, right); //병합 부분
//	}
//}
//
//void Merge(int data[], int left, int mid, int right)
//{
//	int i = left;
//	int j = mid + 1;			
//	int k = left;
//
//	int merge[100] = {};
//
//	/*
//		
//		2	4	6	7	|	1	3	5	8
//		^i			mid		^j
//
//		0	0	0	0	0	0	0	0	0
//		^k
//
//	*/
//
//	while (i <= mid && j <= right)
//	{
//		if (data[i] <= data[j])
//		{
//			merge[k++] = data[i++];
//		}
//		else
//		{
//			merge[k++] = data[j++];
//		}
//	}
//
//	while (i <= mid)
//	{
//		merge[k++] = data[i++];
//	}
//	while (j <= right)
//	{
//		merge[k++] = data[j++];
//	}
//
//	for (int x = left; x <= right; x++)
//	{
//		data[x] = merge[x];
//	}
//}


/*
	병합정렬 :	분할정복에 의한 정렬 알고리즘의 하나
				분할 분할해서 각 부분의 배열원소가 하나가 될대ㄸ까지 쪼갬
				그 부분의 배열을 다시 병합 이때 병합된 배열의 원소가 
				정해진 정렬 순서에 부합하도록 순서를 조정


	2	6	7	4	1	8	5	3 시작


	2	6	7	4	|	1	8	5	3 반갈		

	2	6 | 7	4		1	8 |	5	3 반갈의반갈
	
	2 | 6 | 7 | 4		1 | 8 | 5 | 3  하나가 될때까지 반갈

	----------------------------------- 여기까지 분할
										여기부터 병합

	2	6 |	7	4		1	8 |	3	5 병합

	2	4	6	7	|	1	3	5	8 병합의 병합


	 1	2	3	4	5	6	7	8 완성
	 (이과정은 머지배열을 임시로 두고 데이타배열에 다시 대입해주는 방식으로 진행됨)


	 * 시간복잡도 : O(n log n)

	 특징 : 안정된 정렬이며 데이터의 초기순서에 영향을 크게 받지 않음 (좋은성능을 보여줌)
			
			실제 정렬이 이루어지는 시점은 두개의 부분 배열이 병합하는 단계임

			병합 과정에서 임시 배열을 필요로함 공간복잡도 :O(n)

*/