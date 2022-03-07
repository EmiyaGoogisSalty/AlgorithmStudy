//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;

/*
	트리 순회(traversal)
		- 정해진 순서에 의해 트리의 모든 노드를 한번씩 방문하는 작업


	#전형적인 트리 순회 방법

	-	전위 순회
	-	중위 순회
	-	후위 순회
	--------------------- 깊이 우선 탐색들
	-	레벨 순서 순회
	--------------------- 너비 우선 탐색


	*전위 순회(preorder traversal)
	현재노드 (상위 노드) -> 왼쪽 서브트리 -> 오른쪽 서브트리 
		A -> B -> D -> H -> I -> E
		C -> F -> J -> G 
	
	- 재귀알고리즘으로 적용가능 


	*중위 순회(inorder traversal)
	왼쪽 서브트리 -> 현재노드(상위노드) -> 오른쪽 서브트리
	 H->D->I->B->E->A->J->F->C->G

	 *후위 순회(postorder traversal)
	 왼쪽서브트리 -> 오른쪽 서브트리 -> 상위노드
	 H->I->D->E->B->J->F->G->C->A


	 *레벨 순서 순회(level order traversal)
	 낮은 레벨에 있는 노드를 모두 방문한 후 큰레벨로 이동하여 방문을 반독
	 큐를 사용하여 구현
	 A->B->C->D->E->F->G->H->I->J

	 서로 연결되어있지않은 노드들이 차례대로 방문된다는게 특별함
*/

//struct Node
//{
//
//	char data;
//	Node* left;
//	Node* right;
//
//	Node(char d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//void preorder(Node* node)
//{
//	if (node)
//	{
//		std::cout << node->data << ", ";
//		preorder(node->left);
//		preorder(node->right);
//	}
//}
//
//void inorder(Node* node)
//{
//	if (node)
//	{
//		inorder(node->left);
//		std::cout << node->data << ", ";
//		inorder(node->right);
//	}
//}
//
//void postorder(Node* node)
//{
//	if (node)
//	{
//		postorder(node->left);
//		postorder(node->right);
//
//		std::cout << node->data << ", ";
//	}
//}
//
//void levelorder(Node* node) //root노드의 포인터를 전달해야함
//{
//	std::queue<Node*> q;
//	q.push(node);
//
//	while (!q.empty())
//	{
//		//auto는 노드포인터타입으로 오토지정
//		auto curr = q.front();
//		q.pop();
//
//		cout << curr->data << ", ";
//		if (curr->left) q.push(curr->left);
//		if (curr->right) q.push(curr->right);
//	} //그림그리면서 생각해보기 어렵지않음
//}
//
//void delete_tree(Node* node)
//{
//	if (node)
//	{
//		delete_tree(node->left);
//		delete_tree(node->right);
//
//		delete node;
//	}
//}
// 
//int main()
//{
//	/*
//			A
//		B		C
//	  D	 E		 F
//
//	*/
//	Node* root = nullptr;
//
//	root = new Node('A');
//	root->left = new Node('B');
//	root->right = new Node('C');
//	root->left->left = new Node('D');
//	root->left->right = new Node('E');
//	root->right->right = new Node('F');
//
//	preorder(root);
//	cout << endl;
//
//	inorder(root);
//	cout << endl;
//
//	postorder(root);
//	cout << endl;
//
//	levelorder(root);
//	cout << endl;
//
//	delete_tree(root); //메모리 해제중
//}

/*
	이진트리 삭제하기 
		각각의 노드에서 왼쪽자식 노드와 오른쪽자식노드를 먼저 삭제하고 
		자기 자신을 삭제하는 코드를 제거하는 함수 생성하면됨
*/