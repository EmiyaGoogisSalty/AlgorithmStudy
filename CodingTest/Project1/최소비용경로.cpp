/*
	최소비용경로
	- 2차원 행렬의 각 셀에 정수 값 비용이 적혀있을 때, 행렬의 좌상단에서 우하단까지
	  이동하기 위한 최소비용을 계산하는 문제. 최소경로 합

	- 이동은 오른쪽 또는 아래쪽 방향으로만 가능
*/

//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(vector<vector<int>> m)
//{
//	int rows = (int)m.size();
//	int cols = (int)m[0].size();
//
//	vector<vector<int>> dp(rows, vector<int>(cols, 0));
//
//	for (int y = 0; y < rows; y++)
//	{
//		for (int x = 0; x < cols; x++)
//		{
//			if (x == 0 && y == 0)
//				dp[y][x] = m[y][x];
//
//			else if (x == 0)
//				dp[y][x] = dp[y - 1][x] + m[y][x];
//
//			else if (y == 0)
//				dp[y][x] = dp[y][x - 1] + m[y][x];
//
//			else
//				dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]) + m[y][x];
//		}
//	}
//
//	return dp[rows - 1][cols - 1];
//}
//
//int main()
//{
//	vector<vector<int>> m = {
//		{2, 7, 5, 4},
//		{5, 3, 6, 8},
//		{7, 8, 7, 4},
//		{8, 1, 9, 5}
//	};
//
//	cout << solution(m) << endl;
//}