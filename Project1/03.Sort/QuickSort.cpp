//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void QuickSort(int data[], int left, int right);
//int partition(int data[], int left, int right);
//
//int main()
//{
//	int arr[] = { 5,6,7,3,1,9,2,4,8 };
//
//	
//	QuickSort(arr, 0, size(arr) - 1);
//
//	for (auto n : arr)
//	{
//		cout << n << ", ";
//	}
//
//	
//}
//
//void QuickSort(int data[], int left, int right)
//{
//	if (left < right)
//	{
//		int p = partition(data, left, right); // 첫번재원소를 피봇을 설정하고 피봇을 중간으로 재배치하는 역할
//
//		QuickSort(data, left, p - 1);		// 반씩 나눠서 재귀로 정렬
//		QuickSort(data, p + 1, right);		// 반씩 나눠서 재귀로 정렬
//	}
//	// left와 right가 같으면 배열 하나로 구성되어있는 것이기 떄문에
//	// 이미 정렬된걸로 간주
//}
//
//int partition(int data[], int left, int right)
//{
//	int pivot = data[left];
//	int i = left + 1; //피봇위치 다음
//	int j = right;
//
//	while (true)
//	{
//		while (data[i] <= pivot && i <= right)
//			i++;
//		
//		while (data[j] > pivot && j > left)
//			j--;
//		
//		if (i < j)
//			swap(data[i], data[j]);
//		else
//			break;
//	}
//
//	swap(data[left], data[j]);
//
//	return j;
//}


/*
	퀵 정렬 :	병합 정렬과 마찬가지로 분할 정복 정렬 알고리즘. 제일 널리  쓰는 방법.
				특정 원소를 피봇이라고 선택하고, 주어진 배열을 피봇보다 작은 부분과 큰 부분으로 분할
				분할된 부분 배열에 대해 재귀적으로 퀵 정렬 분할 작업을 반복한다. 

				5	6	7	3	1	9	2	4	8
				^	^							^
				p	i							j

				- i를 증가시키면서 피봇보다 큰 data[i]를 선택
				- 지금위치가 피봇보다 크면 멈추고 j를 감소시킴
				- j를 감소시키면서 피봇보다 작은 data[i]를 선택
				- 감소시키다가 피봇보다 작은 값을 만났을때 i와 j를 맞바꿈
				- 다시 첨부터 반복 (재귀적)
				- 반복하다가 만약 i가 j보다 커진상태 (i>j)가 되면 피봇과 data[j]를 맞바꿈


				1	4	2	3	5	9	7	6	8
								^
							<<	p  >>
				{피봇보다 작은애}	{피봇보다 큰애들}
						

				1	4	2	3		5		9	7	6	8
				^					*		^
				p					p

				- 두 개의 부분 배열에 대해 재귀적으로 퀵정렬 반복


	
	**	퀵정렬은 캐시메모리의 활용도가 높기때문에 
		실제구현에서는 병합정렬보다 퀵정렬이 더빠르게 작용됨

		시간복잡도 : (최선의 경우) O(n log n) (항상 절반으로 분할되는 경우)
					(최악의 경우) O(n2) (한쪽은 1개, 다른쪽은 n-1개로 분할되는 경우)

		안정되지 않은 정렬임.
		
		평균적으로 가장 빠른 정렬 알고리즘 -> c/c++라이브러리 기본제공되는 정렬알고리즘
		std :: sort()
*/

