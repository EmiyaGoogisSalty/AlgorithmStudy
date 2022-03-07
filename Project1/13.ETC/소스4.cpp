//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int h, int w, int n, vector<string> board) {
//	vector <vector<int>> bo;
//	int answer = 0;
//
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			int a = atoi(board[j].substr(j, 1).c_str());
//
//			bo[i].push_back(a);
//		}
//	}
//
//	for (int i = 0; i < bo.size(); i++)
//	{
//		for (int j = 0; j < bo[i].size(); j++)
//		{
//			if (bo[i][j] == 1 && bo[i][j+1] == 1 && bo[i][j+2] == 1 && bo[i][j+3] == 1)
//			{
//				answer++;
//			}
//			else if (bo[i][j] == 1 && bo[i + 1][j] == 1 && bo[i + 2][j] == 1 && bo[i + 3][j] == 1)
//			{
//				answer++;
//			}
//			else if (bo[i][j] == 1 && bo[i + 1][j + 1] == 1 && bo[i + 2][j + 2] == 1 && bo[i + 3][j + 3] == 1)
//			{
//				answer++;
//			}
//
//		}
//
//	}
//
//	return answer;
//}