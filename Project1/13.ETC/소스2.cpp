////#include <string>
////#include <vector>
////#include <iostream>
////#include <queue>
////
////using namespace std;
////
//int solution(int n, vector<vector<int>> computers)
//{
//	vector<bool> visited(n, false);
//	int check = 0; //네트워크 개수
//
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i])
//			continue;
//
//		queue<int> q; //큐생성
//		q.push(i); //큐에 i값 집어넣기
//
//		while (!q.empty())
//		{
//			int v = q.front();
//			q.pop();
//
//			if (visited[v])
//				continue;
//
//			visited[v] = true;
//
//			for (int j = 0; j < n; j++)
//			{
//				if (v != j && computers[v][j] == 1 && !visited[j])
//				{
//					q.push(j);
//				}
//			}
//		}
//
//		check++;
//	}
//
//	return check;
//}
//
//int main()
//{
//	cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} }) << endl;
//	cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} }) << endl;
//}

		//네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다.
		//예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 
		//컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다.
		//따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

		//컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 
		//네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

//int solution(int n, vector<vector<int>> computers)
//{
//	vector<bool>visited(n, false);
//	int check = 0; //네트워크 개수
//
//	for (int i = 0; i < n; i++)
//	{
//		queue<int> q;
//		q.push(i);
//
//		while (!q.empty())
//		{
//			int v = q.front();
//			q.pop();
//
//			if (visited[v])
//				continue; //무시하고 다음포문으로 넘어가기
//
//			visited[v] = true;
//
//			for (int j = 0; j < n; j++)
//			{
//				if (v != j && computers[v][j] == 1 && visited[j] == false)
//				{
//					q.push(j);
//				}
//			}
//		}
//
//		check++;
//	}
//	
//	return check;
//}