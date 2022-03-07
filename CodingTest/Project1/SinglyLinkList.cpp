/*
	리스트(List)
	-	순서를 가진 데이터 (ex. todo리스트, 요일.. 목록
	-	데이터와 링크로 구성된 노드가 연결되어있는 자료 구조
		- 데이터: 정수, 문자열, 복합자료형...등
		- 링크,넥스트: 다음번 노드를 가리키는 포인터
		- 노드: 데이터와 링크로 이루어진 연결리스트 구성단위

		[head] -> ( data: 10 | next* ) -> ( data: 20 | next* ) -@ NULL
						Node		  Link				맨마지막에 위치한 노드

	struct Node
	{
		int data; 저장할 데이터
		Node* next; 노드의 포인터
	};

	리스트의 주요 연산
	-	원소의 참조, 삽입, 삭제, 검색 ...

	대표적인 리스트 구현방법
	배열 : 연속된 메모리공간, 원소의삽입삭제가 비효율적, 구현이 쉬움]
	연결리스트:	임의의 메모리공간, 원소의 삽입삭제가 효율적, 구현이 어려움

	연결리스트 장점
		- 임의의 위치에 원소의 삽입&삭제가 효율적 O(1)
		- 크기 제한이 없음

	연결리스트의 단점
		- 임의의 원소접근이 비효율적: O(N) 차례대로 다 접근해야하기 떄문에..
		- 링크를 위한 여분의 공간 사용
		- 구현이 복잡
	

	단순 연결 리스트
		- 다음 노드에 대한 링크만 가지고 있는 연결리스트 (next만 있는..)
		- 한쪽 방향으로만 순회 가능 (단방향 연결리스트)

	이중 연결 리스트
		- 이전노드와 다음노드에 대한 링크를 가지고 있는 연결 리스트
		- 양방향 순회가 가능(양방향 연결리스트)

	원형 연결 리스트
		- 일반적인 연결 리스트의 마지막 노드 링크가 처음노드를 가리키도록
		  구성된 자료구조
		
		- 처음 노드가 다시 나타나면 순회를 멈춤
*/ 

//struct Node
//{
//	int data;
//	Node* next;
//};
//
//class LinkedList
//{
//private:
//	Node* head; //노드의 머리부분
//
//public:
//	LinkedList() : head(nullptr) {}
//
//	~LinkedList() //연결리스트 제거
//	{
//		while (!empty())
//		{
//			pop_front();
//		}
//	}
//
//	void push_front(int val)
//	{
//		Node* new_node = new Node{ val, nullptr };
//
//		if (head != nullptr)
//		{
//			new_node->next = head;
//		}
//
//		head = new_node;
//	}
//	void pop_front()
//	{
//		if (head == nullptr) //노드가 없을경우
//			return;
//
//		Node* first = head; //임시 포인터변수 생성 temp같은 존재
//		head = head->next; //헤드가 가리키고있는 노드의 다음
//
//		// [head] -> [10 | *] -> [20 | *] ..
//		//             ^    Next
//		//			 [*first]
//
//		delete first; //퍼스트가 가리키고있는 노드를 지운다.
//	}
//
//	void print_all()
//	{
//		Node* curr = head;
//
//		while (curr != nullptr)
//		{
//			cout << curr->data << ", ";
//			curr = curr->next;
//		}
//	}
//
//	bool empty()
//	{
//		return head == nullptr;
//	}
//};
//
//int main()
//{
//	LinkedList ll;
//	ll.push_front(10);
//	ll.push_front(20);
//	ll.push_front(30);
//	
//	ll.print_all();
//
//	ll.pop_front();
//	ll.print_all();
//
//	ll.push_front(40);
//	ll.print_all();
//}