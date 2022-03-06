//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<string> purchase) 
//{
//	vector<pair<int, int>> pur;
//
//	vector<int> answer;
//
//	for (int i = 0; i < purchase.size(); i++)
//	{
//		int year = atoi(purchase[i].substr(0, 4).c_str());
//		int month = atoi(purchase[i].substr(5, 6).c_str());
//		int date = atoi(purchase[i].substr(8, 9).c_str());
//
//		int money = atoi(purchase[i].substr(11).c_str());
//
//		pur.push_back(make_pair(year * 10000000 + month + date, money));
//	}
//
//	int idx1 = 0;
//	int d = 20191231;
//	int bronze = 0;
//	int silver = 0;
//	int gold = 0;
//	int platinum = 0;
//	int diamond = 0;
//
//	while (answer.size() != 5)
//	{
//		if (pur[idx1].first <= d && pur[idx1].second < 10000) //브론즈 0
//		{
//			bronze = pur[idx1].first;
//			idx1++;
//			answer.push_back(bronze);
//		}
//		else if (pur[idx1].first <= d && pur[idx1].second < 20000) //실 1
//		{
//			silver = pur[idx1].first;
//			idx1++;
//
//			if (bronze == 0)
//			{
//				bronze = silver - bronze;
//			}
//
//			answer.push_back(silver);
//		}
//		else if (pur[idx1].first <= d && pur[idx1].second < 50000) // 골 2
//		{
//			gold = pur[idx1].first;
//			idx1++;
//
//			if (bronze != 0 )
//			{
//				bronze = gold - bronze;
//			}
//			if (silver != 0 )
//			{
//				silver = gold - silver;
//			}
//
//			answer.push_back(gold);
//		}
//		else if (pur[idx1].first <= d && pur[idx1].second < 100000) // 플 3
//		{
//			platinum = pur[idx1].first;
//			idx1++;
//
//			if (bronze != 0)
//			{
//				bronze = platinum - bronze;
//			}
//			if (silver != 0)
//			{
//				silver = platinum - bronze;
//			}
//			if (gold != 0)
//			{
//				gold = platinum - gold;
//			}
//
//			answer.push_back(platinum);
//		}
//		else if (pur[idx1].first <= d && pur[idx1].second >= 100000) //다 4
//		{
//			diamond = pur[idx1].first;
//			idx1++;
//
//			answer.push_back(diamond);
//		}
//
//	}
//
//	answer[0] = (d - pur.back().first);
//}