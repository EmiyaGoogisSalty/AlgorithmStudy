
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//
//
//using namespace std;
//
//
//int solution(vector<int> scoville, int K) 
//{
//	int count = 0;
//	priority_queue<int> pq;
//	vector<int> vec;
//	
//	stack<int> stk;
//
//	for (int i = 0; i < scoville.size(); i++)
//	{
//		pq.push(scoville[i]);
//	}
//
//	while (!pq.empty())
//	{
//		if (pq.top() >= K)
//		{
//			pq.pop();
//		}
//		if (pq.top() < K)
//		{
//			stk.push(pq.top());
//			pq.pop();
//		}
//	}
//
//	while (!stk.empty())
//	{
//		int m = stk.top() + ((stk.top() - 1) * 2);
//		count++;
//
//		stk.pop();
//		stk.pop();
//
//		if (m < K)
//			stk.push(m);
//		
//		if (stk.top() >= stk.top() - 1)
//		{
//			int m = (stk.top() - 1) + (stk.top() * 2);
//			count++;
//
//			stk.pop();
//			stk.pop();
//		}
//			
//	}
//
//	return count;
//}



//for (int i = 0; i < vec.size(); i++)
//{
//	sort(vec.begin(), vec.end(), greater<int>());
//
//	if (vec.back() < K && vec.back() - 1 < K)
//	{
//		count++;
//
//		int a = vec.back();
//		int b = vec.back() - 1;
//
//		vec.push_back(plusint(a, b));
//	}
//}
//
//while (!sco.empty())
//{
//	int num1 = sco.top();
//	sco.pop();
//	int num2 = sco.top();
//	sco.pop();
//
//	if (num1 > num2)
//		q.push(num1);
//
//	else if (num2 < sco.top())
//	{
//		int num3 = sco.top();
//		sco.pop();
//
//		int val = num3 + (num2 * 2);
//		count++;
//
//		q.push(val);
//	}
//
//
//}