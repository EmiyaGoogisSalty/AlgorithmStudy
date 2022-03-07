//#include <vector>
//#include <iostream>
//#include <stack>
//
//using namespace std;

/*
	깊이 우선 탐색(Depth First Search)

	현재 정점과 인접한 정점 중 하나를 선택해서 이동하는 과정을 반복.
	더이상 이동정점이 없을 때 (막다른 길 일때) 뒤 쪽으로 백 트래킹(back tracking) 하여
	다시 이동할 경로를 선택!

	start정점으로부터 거리가 멀어지는(거리 == 깊이) 방식

	보통 재귀나 스택으로 구현한다. 

	0 - 1 - 2
	| \ |	|
	3 - 4 - 5  

	0 -> 1 -> 2 -> 5(백) -> 2(백) -> 1 -> 4 -> 3

	0 -> 1 -> 2 -> 5 -> 4 -> 3
*/

// 재귀 형태 
//const int N = 6; //정점 수
//bool gVisited[N] = {};
//
//void dfs_recursion(const vector<vector<int>>& adj_list, int s) //s는 시작 정점
//{
//	if (gVisited[s]) //gvisited [0]이 트루이면 리턴 (백트래킹 || 재귀 탈출 목적)
//	{
//		return;
//	}
//
//	gVisited[s] = true; // 펄스면 트루로 리턴해주고
//	cout << s << ", "; // 0을 프린트 이위치에 필요한 코드 작성
//
//	for (int v : adj_list[s]) // adj_list [0]의 인트값 {1,3,4}를 돌면서 재귀호출
//	{
//		dfs_recursion(adj_list, v); // 1 호출 ...반복
//	}
//}
//
//int main()
//{
//	vector<vector<int>> adj_list = {
//		{1,3,4}, //0
//		{0,2,4}, //1
//		{1,5},   //2
//		{0,4},   //3
//		{0,1,3}, //4
//		{2}      //5
//	};
//
//	dfs_recursion(adj_list, 0);
//	cout << endl;
//}

//vector<int> dfs(const vector<vector<int>>& adj_list, int s)
//{
//	vector<bool> visited(adj_list.size(), false);
//	vector<int> visit_order;
//	stack<int> stk;
//
//	stk.push(s); //0 삽입
//
//	while (!stk.empty())
//	{
//		int v = stk.top();
//		stk.pop();
//
//		if (visited[v]) continue;
//
//		visited[v] = true;
//		visit_order.push_back(v);
//		//이 위치에 필요한 코드 작성
//
//		for (int a : adj_list[v])
//		{
//			if (!visited[a])
//			{
//				stk.push(a);
//			}
//		}
//	}
//
//	return visit_order;
//}