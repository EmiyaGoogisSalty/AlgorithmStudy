//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;

/*
	이진 탐색 트리

		효율적인 자료의 탐색을 위한 이진 트리 기반의 자료구조
		자료의 계층적인 구조를 표현하기 위해 사용하는 것이 아니라, 
		자료의 효율적인 관리를 위해 트리 구조를 사용
		(폴더관리같은..)


		모든 노드 N에 대해, 왼쪽 서브트리에 있는 모든 노드의 키값은 
		노드 N의 키 값보다 작고, 오른쪽 서브트리에 있는 모든 노드 키값은
		N의 키 값보다 큼.

							9
					4				15
				2		6		13		18
			1		 5


	이진탐색 특징

		자료의 탐색, 삽입, 삭제가 모두 O(log n) 시간 복잡도로 동작함 (효율적)
		이진 탐색트리를 중위순회하면 오름차순으로 정렬된 값을 얻을 수 있음


	[자료구조]	[탐색]	[삽입]	[삭제]
	배열			O(n)	O(1)	O(1)
	연결리스트	O(n)	O(1)	O(1)
	정렬된배열	O(logn) O(n)	O(n)
	이진탐색트리 O(logn)	O(logn)	O(logn) *효율적

	*탐색시 O(h) (h는 이진트리의 높이) -> log2n -> O(logn)
	

	이진탐색트리에서 탐색

	1. 노드 루트 키값을 기준으로 타겟값을 비교 
	2. 루트키보다 작으면 왼쪽 크면 오른쪽으로 내려감
	3. 내려간 서브트리에서 또 비교 
	4. 반복

	이진탐색트리에서 삽입
	1. 노드 루트 키값을 기준으로 타겟값 비교
	2. 루트키보다 작으면 왼, 크면 오
	3. 내려간 서브트리에 어딘가에 삽입해야함
	4. 내려간 서브트리와 비교 
	5. 리프까지 계속 비교 하고 리프쪽에 연결시켜주면됨 
	

	이진탐색트리에서 삭제
		이진 탐색 트리에서 자료의 삭제는 해당 노드를 삭제 한 후, 
		BST속성을 만족할 수 있는 다른 적절한 노드를 찾아 해당 노드로 대체해야함

	case1. 자식 노드가 없는경우 -> 
			해당노드를 삭제하고 부모노드 링크를 제거

	case2. 자식 노드가 하나만 있는경우 -> 
			해당노드를 삭제하고, 부모노드 포인터가 해당 노드의 자식 노드를 가리키도록 설정

	case3. 자식 노드가 두개 있는경우 ->
			후속 노드의 값을 현재 노드로 복사하고, 후속 노드를 삭제 
			 *후계자 노드 (successor): 현재 노드 다음으로 큰 숫자를 가진 노드
									(현재 노드의 오른쪽 서브트리에서 가장 작은 값의 노드,
									 후속노드는 자식이 없거나 오른쪽 자식만 있음. )


	이진 탐색 트리의 문제점
		원소의 삽입 순서에 따라 이진 탐색 트리가 한쪽으로 치우친 형태로 구성될 수 있음.
		트리가 한쪽으로 치우칠 경우, 트리의 높이가 h = n-1 형태로 구성되므로, 
		탐색, 삽입, 삭제 연산의 시간 복잡도가 O(n)으로 결정됨.

	이진 탐색트리의 문제점 해결방법
		한쪽으로 치우친 트리의 구성을변경하여 균형잡힌 트리 형태로 변경 할 수 있음.
		트리회전하여 트리의 계층을 맞춰준다. 

						7										5
				5				9						3				7
			3		6				 =>	트리회전		2		4		6		9
		  2  4


	균형잡힌 트리의 예
		AVL트리, 레드블랙트리 , B트리, 스플레이 트리


*/

//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//class BinarySearchTree
//{
//private:
//	Node* root = nullptr;
//
//public:
//	~BinarySearchTree()
//	{
//		delete_tree(root);
//	}
//
//	void insert(int value)
//	{
//		if (!root)
//		{
//			root = new Node(value);
//		}
//		else
//		{
//			insert_impl(root, value); 
//		}
//	}
//
//	Node* find(int value)
//	{
//		return find_impl(root, value);
//	}
//
//	void inorder() //중위순위
//	{
//		inorder_impl(root);
//	}
//
//	void erase(int value) // 노드 삭제 함수
//	{
//		root = erase_impl(root, value);
//	}
//
//private:
//	void insert_impl(Node* curr, int value) //implimantation
//	{
//		if (value < curr->data)
//		{
//			if (!curr->left)
//			{
//				curr->left = new Node(value);
//			}//만약 왼쪽포인터가 가리키는게 널이라면
//			 //새로운 노드를 만들어서 밸류를 넣어줌
//			else
//			{
//				insert_impl(curr->left, value); //재귀적으로 다시호출하면서 비교
//			}
//		}
//		else
//		{
//			if (!curr->right)
//			{
//				curr->right = new Node(value);
//			}
//			else
//			{
//				insert_impl(curr->right, value);
//			}
//		}
//	}
//
//	Node* find_impl(Node* curr, int value)
//	{
//		if (curr == nullptr)
//		{
//			return nullptr;
//		}
//
//		if (value == curr->data)
//		{
//			return curr;
//		}
//		else
//		{
//			if (value < curr->data)
//			{
//				return find_impl(curr->left, value);
//			}
//			else
//			{
//				return find_impl(curr->right, value);
//			}
//		}
//	}
//
//	void inorder_impl(Node* curr)
//	{
//		if (curr != nullptr)
//		{
//			inorder_impl(curr->left);
//			cout << curr->data << ", ";
//			inorder_impl(curr->right);
//		}
//	}
//
//	void delete_tree(Node* node)
//	{
//		if (node)
//		{
//			delete_tree(node->left);
//			delete_tree(node->right);
//
//			delete node;
//		}
//	}
//
//	//노드 삭제 후, 부모 노드 포인터가 가리켜야 할 노드의 주소를 반환
//	Node* erase_impl(Node* curr, int value)
//	{
//		if (!curr) //노드가 널인경우
//		{
//			return nullptr;
//		}
//
//		if (value < curr->data)
//		{
//			curr->left = erase_impl(curr->left, value);
//		}
//		else if (value > curr->data)
//		{
//			curr->right = erase_impl(curr->right, value);
//		}
//		else
//		{
//			if (curr->left && curr->right) //자식 노드가 둘 다 있는 경우
//			{
//				auto succ = successor(curr);
//				curr->data = succ->data;
//				curr->right = erase_impl(curr->right, curr->data);
//			}
//			else //자식 노드가 전혀 없거나, 한쪽 자식만 있는경우
//			{
//				auto tmp = curr->left ? curr->left : curr->right;
//				//둘다 없으면 널값
//				delete curr;
//				return tmp;
//			}
//		}
//
//		return curr;
//	}
//
//	Node* successor(Node* curr) // 후속 노드 찾기
//	{
//		auto node = curr->right;
//		
//		while (node && node->left)
//		{
//			node = node->left;
//			
//		}
//
//		return node;
//	}
//};
//
//int main()
//{
//	BinarySearchTree bst;
//
//	bst.insert(10);		bst.insert(14);
//	bst.insert(5);		bst.insert(7);
//	bst.insert(18);		bst.insert(4);
//	bst.insert(6);		bst.insert(20);
//	bst.insert(16);
//	bst.inorder();
//	cout << endl;
//
//	if (bst.find(7))
//	{
//		cout << "7 is found" << endl;
//	}
//	else
//	{
//		cout << "7 is not found" << endl;
//	}
//
//	if (bst.find(15))
//		cout << "15 is found" << endl;
//	else
//		cout << "15 is not found" << endl;
//
//	bst.insert(9);
//	bst.insert(12);
//
//	bst.inorder(); 
//	cout << endl;
//	
//
//	bst.erase(4);
//	bst.erase(5);
//	bst.erase(14);
//	bst.inorder();
//	cout << endl;
//
//	bst.insert(15);
//	bst.erase(10);
//	bst.inorder();
//	cout << endl;
//}