//
//
///*
//	힙 속성
//
//	자료구조에서 힙은 완전 이진트리 한 형태로서 힙 속성을 만족하는 자료구조.
//
//	- 최대 힙 속성 : 부모노드 키 값은 항상 자식 노드의 키 값보다 크거나 같음. 
//	- 최소 힙 속성 : 부모노드 키 값은 항상 자식 노드의 키 값보다 작거나 같다. 
//
//	힙의 특징
//	
//	- 루트노드는 항상 최댓값 또는 최소값을 가지고 있음. 
//	- 부모 자식 사이의 크기관계만 있지 왼쪽자식 오른쪽자식 사이의 크기 관계는 없다. 
//	- 완전 이진트리이기 때문에 트리의 높이는 h = [log2n]
//	- 힙의 응용분야 : 힙정렬, 우선순위 큐, 다익스트라 알고리즘 ..
//
//	힙 연산의 시간 복잡도
//	
//	- 최댓값 또는 최솟값 참조할땐 O(1)
//	- 원소 삽입시 O(log N)
//	- 원소 삭제시 O(log N)
//
//	힙과 이진탐색트리 차이점
//
//						[힙]					[이진탐색트리]
//
//	트리형태:		완전 이진트리			이진 트리
//	원소 중복여부:	중복 가능				중복되지 않음
//	원소 정렬여부:	정렬되지 않음			정렬됨(중위탐색)
//	빠른원소탐색:	미지원(순차탐색,O(n))	지원(이진탐색,O(log n))
//					자식간의크기관계는없기에..
//	원소삽입/삭제:	O(log n)				O(log n) / 최악트리구조: O(n)
//	최댓값/최솟값참조:	O(1)				O(log n) / 최악트리구조: O(n)
//
//	*최악의 트리구조 == 한쪽으로 치우쳐져 있는 트리 형태
//	
//
//
//	힙 구현하기
//		힙은 완전 이진트리이므로 각 노드에 인덱스를 붙이고, 배열을 이용하여 
//		쉽게 표현할 수 있음.
//
//		구현의 편의상 루트 노드의 인덱스를 1부터 시작 (배열의 0변 인덱스는 무시)
//
//	*최대 힙속성 예시*
//
//									15(1)
//	L = 0	---------------------------------------------------
//						8(2)					14(3)
//	L = 1	---------------------------------------------------
//					7(4)	4(5)			9(6)	10(7)
//	L = 2	---------------------------------------------------
//				  5  2    3
//	L = 3		(8) (9)  (10)
//			---------------------------------------------------
//
//	배열구현
//		==>	 |	-	|	15	|	8	|	14	|	7	|	4	|	9	|	10	|	5	|	2	|	3	|
//		arr		0		1		2		3		4		5		6		7		8		9		10
//	
//	루트 노드 인덱스 : 1
//	
//	인덱스가 m인 노드에 대해서
//		- 부모 노드 인덱스 : m / 2
//		- 왼쪽 자식 인덱스 : m * 2
//		- 오른쪽 자식 인덱스: m * 2 + 1
//
//
//	힙에서 원소 삭제
//		1. 힙의 맨 마지막 노드 값을 루트 노드로 복사하고, 맨 마지막 노드를 삭제한다.
//		2. 루트 노드와 두 자식노드를 비교하여 힙 속성을 만족하지 않으면 두 자식 노드중에서
//			더 큰(최대 힙) 노드와 서로 교환한다. 그리고 교환한 자식 노드에서 이 작업을 반복한다.
//			(heapify_down)
//
//
//
//*/
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class MaxHeap //최대 힙속성
//{
//private:
//	vector <int> vec;
//
//public:
//	MaxHeap() : vec(1) {}
//
//	void push(int value)
//	{
//		vec.push_back(value);
//		heapify_up(vec.size() - 1);
//
//	}
//
//	void pop()
//	{
//		vec[1] = vec.back();
//		vec.pop_back();
//		heapify_down(1);
//	}
//	int top() const { return vec[1]; }
//	int size() { return vec.size() - 1; }
//	bool empty() { return vec.size() == 1; }
//	
//
//private:
//	int parent(int i) { return i / 2; }
//	int left(int i) { return 2 * i; }
//	int right(int i) { return 2 * 1 + 1; }
//
//	void heapify_up(int i)
//	{
//		if (i > 1 && vec[i] > vec[parent(i)])
//		{
//			swap(vec[i], vec[parent(i)]);
//			heapify_up(parent(i));
//		}
//	}
//
//	void heapify_down(int i)
//	{
//		int largest = i;
//
//		if (left(i) < vec.size() && vec[left(i)] > vec[largest])
//		{
//			largest = left(i);
//		}
//
//		if (right(i) < vec.size() && vec[right(i)] > vec[largest])
//		{
//			largest = right(i);
//		}
//
//		if (largest != i)
//		{
//			swap(vec[i], vec[largest]);
//			heapify_down(largest);
//		}
//	}
//};
//
//int main()
//{
//	MaxHeap heap;
//
//	heap.push(10);	heap.push(5);
//	heap.push(15);	heap.push(7);
//	heap.push(3);	heap.push(9);
//	heap.push(14);	heap.push(8);
//	heap.push(2);	heap.push(4);
//
//	while (!heap.empty())
//	{
//		cout << heap.top() << ", ";
//		heap.pop();
//	}
//	cout << endl;
//}
//
