//#include <vector>
//#include <iostream>
//#include <queue>
//
//using namespace std;

/*
	너비 우선 탐색 (BFS)

	현재 정점에서 인접한 정점을 방문 후, 다시 이들 정점과 인접한 모든 정점을 찾아 방문하는 방식

	시작 정점으로부터 가까운 정점을 먼저 방문, 멀리 떨어져 있는 정점을 나중에 방문

	보통 큐로 구현한다.

	0 -> 1 -> 3 -> 4 -> 2 -> 5
	(DFS그래프와 똑같은 구조예)

*/

//vector<int> bfs(const vector<vector<int>>& adj_list, int s)
//{
//	vector<bool> visited(adj_list.size(), false);
//	vector<int> visit_order;
//	queue<int> q;
//
//	q.push(s); // 0삽입
//
//	while (!q.empty())
//	{
//		int v = q.front();
//		q.pop();
//
//		if (visited[v]) //트루형태이면
//		{
//			continue;
//		}
//
//		visited[v] = true;
//		visit_order.push_back(v);
//
//		for (int a : adj_list[v])
//		{
//			if (!visited[a])
//			{
//				q.push(a);
//			}
//		}
//	}
//
//	return visit_order;
//}