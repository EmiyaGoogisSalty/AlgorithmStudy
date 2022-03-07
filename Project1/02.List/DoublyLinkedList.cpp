/*
	이중연결 리스트의 구조

	@-[ | | ] <-> [ p | data | n ] <-> [ p | data | n ] <->[ | | ]-@
	   header		    node								trailer
	
	이중연결 리스트는 헤더와 트레일러를 가지고있음 (너미노드) 통일성을 갖추기위해..

	이중연결리스트 장점
		- 링크가 양방향이므로 양방향검색이 가능

	이중연결리스트 단점
		- 이전노드링크를 위한 여분의 공간 사용
		- 데이터의 삽입과 삭제구현이 더 복잡

	추가할 기능
		- 반복자 지원
		- 데이터 검색 가능
		- 범용 데이터 저장을 위한 클래스 탬플릿 작성
*/

#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
};

template <typename T>
class DoublyLinkedList
{
	int count; //현재연결리스트에 들어가있는 노드의 개수
	Node<T>* header;
	Node<T>* trailer;

public:
	class iterator
	{
	private:
		Node<T>* ptr;

	public: //2개 생성자 
		iterator() :ptr(nullptr) {}
		iterator(Node<T>* p) : ptr(p) {}

		T& operator*() { return ptr->data; } //*연산자 데이터를 참조형태를 반환

		iterator& operator++() //++it
		{
			ptr = ptr->next;
			return *this;
		}

		iterator& operator--() //--it
		{
			ptr = ptr->prev;
			return *this;
		}

		bool operator == (const iterator& it) const
		{
			return ptr == it.ptr;
		}

		bool operator != (const iterator& it) const
		{
			return ptr != it.ptr;
		}

		friend class DoublyLinkedList;
	};

	DoublyLinkedList()
	{
		count = 0;
		header = new Node<T> { T(), nullptr, nullptr }; //t()는 템플릿 t의 초기화문임
		trailer = new Node<T> { T(), nullptr, nullptr };

		header->next = trailer;
		trailer->prev = header;

		// @- [ p | 0 | n ] <-> [ p | 0 | n ] -@ 
	}
	~DoublyLinkedList()
	{
		while (!empty())
		{
			pop_front();
		}

		delete header; //생성자에서 동적생성한 헤더와 트레일러 해제
		delete trailer;
	}

	void insert(const iterator& pos, const T& val) //특정노드의 포인터, 데이터
	{
		Node<T>* p = pos.ptr;
		Node<T>* new_node = new Node<T> { val, p->prev, p }; 
		//데이터를 넣고, 프리브의 값을 특정노드 p가 가리키고있는 prev위치를 받고, 넥스트는 p를 가리킴 
		new_node->prev->next = new_node;
		// 뉴노드가 가리키고있는 prev값을 넥스트가 가리키고 그 넥스트가 새로추가한 노드를 가리키게 하기 
		new_node->next->prev = new_node;

		count++; //노드가 추가되었다는 카운트++
	}

	void push_front(const  T& val)
	{
		insert(begin(), val);
	}

	void push_back(const  T& val)
	{
		insert(end(), val);
	}

	void erase(const iterator& pos)
	{
		Node<T>* p = pos.ptr;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		delete p;
		count--;
	}

	void pop_front()
	{
		if (!empty())
			erase(begin());
	}

	void pop_back()
	{
		if (!empty())
			erase(--end());
	}

	void print_all()
	{
		Node<T>* curr = header->next;

		while (curr != trailer)
		{
			cout << curr->data << ", ";
			curr = curr->next;
		}
	}

	void print_reserve()
	{
		Node<T>* curr = trailer->prev;

		while (curr != header)
		{
			cout << curr->data << ", ";
			curr = curr->prev;
		}
	}

	bool empty()
	{
		return count == 0;
	}

	int size()
	{
		return count;
	}

	iterator begin() const
	{
		return iterator(header->next);
	}

	iterator end() const
	{
		return iterator(trailer);
	}

	iterator find(const T& val)
	{
		Node<T>* curr = header->next;

		while (curr->data != val && curr != trailer)
			curr = curr->next;

		return iterator(curr);
	}
};

int main()
{
	DoublyLinkedList<int> ll;

	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);

	auto it = ll.find(20);

	if (it != ll.end())
		ll.insert(it, 50);

	for (auto n : ll)
		cout << n << ", ";

	cout << endl;
}