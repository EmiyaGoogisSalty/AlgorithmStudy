//#include <algorithm>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
///*
//	선형 탐색(linear search)
//	전체자료를 첨부터 마지막까지 순서대로 탐색하는 방법. 순차 탐색.
//
//	find(10)
//
//	5	13	10	1	19	3	2	15	7
//	^
//	f	f	t
//
//	시간복잡도 O(n) 
//
//	장점: 상당히 간단. 직관적. 정렬되지않은 데이터에도 적용가능
//	단점: 비효율적(최악의경우 배열 전체를 탐색해야함)
//
//
//*/
//
//bool linear_search(int data[], int n, int target)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (data[i] == target)
//		{
//			return true;
//		}
//
//		return false;
//	}
//}

//int main()
//{
//	int data[] = { 1,2,3,4,5,6,7,8,10,15,18,23,25,27,29,30,33 };
//	int target = 23;
//
//	bool res1 = linear_search(data, std::size(data), target);
//}