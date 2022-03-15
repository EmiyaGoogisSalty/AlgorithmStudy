// /*
// 	���߿��� ����Ʈ�� ����

// 	@-[ | | ] <-> [ p | data | n ] <-> [ p | data | n ] <->[ | | ]-@
// 	   header		    node								trailer

// 	���߿��� ����Ʈ�� ����� Ʈ���Ϸ��� ���������� (�ʹ̳��) ���ϼ��� ���߱�����..

// 	���߿��Ḯ��Ʈ ����
// 		- ��ũ�� ������̹Ƿ� �����˻��� ����

// 	���߿��Ḯ��Ʈ ����
// 		- ������帵ũ�� ���� ������ ���� ���
// 		- �������� ���԰� ���������� �� ����

// 	�߰��� ���
// 		- �ݺ��� ����
// 		- ������ �˻� ����
// 		- ���� ������ ������ ���� Ŭ���� ���ø� �ۼ�
// */

// #include <iostream>

// using namespace std;

// template<typename T>
// struct Node
// {
// 	T data;
// 	Node* prev;
// 	Node* next;
// };

// template <typename T>
// class DoublyLinkedList
// {
// 	int count; //���翬�Ḯ��Ʈ�� ���ִ� ����� ����
// 	Node<T>* header;
// 	Node<T>* trailer;

// public:
// 	class iterator
// 	{
// 	private:
// 		Node<T>* ptr;

// 	public: //2�� ������
// 		iterator() :ptr(nullptr) {}
// 		iterator(Node<T>* p) : ptr(p) {}

// 		T& operator*() { return ptr->data; } //*������ �����͸� �������¸� ��ȯ

// 		iterator& operator++() //++it
// 		{
// 			ptr = ptr->next;
// 			return *this;
// 		}

// 		iterator& operator--() //--it
// 		{
// 			ptr = ptr->prev;
// 			return *this;
// 		}

// 		bool operator == (const iterator& it) const
// 		{
// 			return ptr == it.ptr;
// 		}

// 		bool operator != (const iterator& it) const
// 		{
// 			return ptr != it.ptr;
// 		}

// 		friend class DoublyLinkedList;
// 	};

// 	DoublyLinkedList()
// 	{
// 		count = 0;
// 		header = new Node<T> { T(), nullptr, nullptr }; //t()�� ���ø� t�� �ʱ�ȭ����
// 		trailer = new Node<T> { T(), nullptr, nullptr };

// 		header->next = trailer;
// 		trailer->prev = header;

// 		// @- [ p | 0 | n ] <-> [ p | 0 | n ] -@
// 	}
// 	~DoublyLinkedList()
// 	{
// 		while (!empty())
// 		{
// 			pop_front();
// 		}

// 		delete header; //�����ڿ��� ���������� ����� Ʈ���Ϸ� ����
// 		delete trailer;
// 	}

// 	void insert(const iterator& pos, const T& val) //Ư������� ������, ������
// 	{
// 		Node<T>* p = pos.ptr;
// 		Node<T>* new_node = new Node<T> { val, p->prev, p };
// 		//�����͸� �ְ�, �������� ���� Ư����� p�� ����Ű���ִ� prev��ġ�� �ް�, �ؽ�Ʈ�� p�� ����Ŵ
// 		new_node->prev->next = new_node;
// 		// ����尡 ����Ű���ִ� prev���� �ؽ�Ʈ�� ����Ű�� �� �ؽ�Ʈ�� �����߰��� ��带 ����Ű�� �ϱ�
// 		new_node->next->prev = new_node;

// 		count++; //��尡 �߰��Ǿ��ٴ� ī��Ʈ++
// 	}

// 	void push_front(const  T& val)
// 	{
// 		insert(begin(), val);
// 	}

// 	void push_back(const  T& val)
// 	{
// 		insert(end(), val);
// 	}

// 	void erase(const iterator& pos)
// 	{
// 		Node<T>* p = pos.ptr;

// 		p->prev->next = p->next;
// 		p->next->prev = p->prev;

// 		delete p;
// 		count--;
// 	}

// 	void pop_front()
// 	{
// 		if (!empty())
// 			erase(begin());
// 	}

// 	void pop_back()
// 	{
// 		if (!empty())
// 			erase(--end());
// 	}

// 	void print_all()
// 	{
// 		Node<T>* curr = header->next;

// 		while (curr != trailer)
// 		{
// 			cout << curr->data << ", ";
// 			curr = curr->next;
// 		}
// 	}

// 	void print_reserve()
// 	{
// 		Node<T>* curr = trailer->prev;

// 		while (curr != header)
// 		{
// 			cout << curr->data << ", ";
// 			curr = curr->prev;
// 		}
// 	}

// 	bool empty()
// 	{
// 		return count == 0;
// 	}

// 	int size()
// 	{
// 		return count;
// 	}

// 	iterator begin() const
// 	{
// 		return iterator(header->next);
// 	}

// 	iterator end() const
// 	{
// 		return iterator(trailer);
// 	}

// 	iterator find(const T& val)
// 	{
// 		Node<T>* curr = header->next;

// 		while (curr->data != val && curr != trailer)
// 			curr = curr->next;

// 		return iterator(curr);
// 	}
// };

// int main()
// {
// 	DoublyLinkedList<int> ll;

// 	ll.push_back(10);
// 	ll.push_back(20);
// 	ll.push_back(30);

// 	auto it = ll.find(20);

// 	if (it != ll.end())
// 		ll.insert(it, 50);

// 	for (auto n : ll)
// 		cout << n << ", ";

// 	cout << endl;
// }