/*
	동적계획법
	-복잡한 문제를 간단한 여러 개의  부분 문제(subproblem)로 나누고, 부분 문제에 대한 해답을 활용
	하여 전체 문제를 해결하는 문제 해결 방식

	-분할 정복법에서는 분할된 부분 문제들이 서로 겹치지 않지만, 동적 계획법에서는 중복되는 부분 문제가
	발생한다는 점이 다름

	- 보통 최적화 문제 또는 카운팅 문제에 적용

	- 유명한 동적 계획법 문제들
		배낭문제, 부분집합의 합문제, 최장공통부분 시퀀스, 연쇄행렬 곱셉, 최소비용 경로

	동적계획법 필요조건
	- 중복되는 부분 문제
		주어진 문제를 여러개의 부분문제로 분할 할경우, 몇몇 부분 문제가 반복되어 나타나는 현상
		부분문제의 솔루션을 저장하여 같은 부분 문제를 중복해서 계산하지 않도록 설정

	- 최적 부분 구조
		부분 문제의 최적해를 조합하여 전체 문제의 최적해를 구할 수 있는 경우를 지칭

	동적계획법 문제의 해결 방법
	-기저 조건 정의 (base case)
	-상태전환(state transition)을 나타내는 순환식 정의
	-순환식을 메모이제이션 또는 타뷸레이션방식으로 풀이

	ex ) 피보나치 수열 (트리를만들어 그래프 만들어보기)

	- 메모이제이션
		중복계산될 수 있는 값을 캐시에 저장하여 재사용
		하향식 접근 방법 (top-down)
		메모라는 배열에 중복되는 값의 해를 저장해서 재사용하는 방식

	- 타뷸레이션
		모든 부분문제 연산결과를 미리 표에 저장하여 사용하는 방식
		상향식 접근 방법

	*둘의 차이점
	- 메모이제이션  : 재귀 호출이 많이 발생하므로, 함수 호출에 따른 오버헤드가 있음

					 경우에따라 모든부분문제를 풀지 않아도 문제에 대한 해답을 구할 수 있음

					 캐시로 사용하는 표의 일부만 필요에 따라 계산하여 채움


	- 타뷸레이션 : 표(배열)에 저장된 값을 참조하는 방식이므로 빠르게 동작

				  상향식 방식이기때문에 모든 부분 문제에 대한 해답을 구해서 표에 저장

				  표의 맨 처음부터 끝까지 차례대로 계산하여 모두 채움

*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int fibo1(int n)
//{
//	if (n <= 1)
//		return n;
//
//	return fibo1(n - 1) + fibo1(n - 2);
//}
//
//vector<int> memo(50, -1); //메모이제이션 메모배열
//
//int fibo2(int n)
//{
//	if (n < 2)
//	{
//		return n;
//	}
//
//	if (memo[n] != -1)
//		return memo[n];
//
//	memo[n] = fibo2(n - 2) + fibo2(n - 1);
//	
//	return memo[n];
//}
//
//int fibo3(int n)
//{
//	vector<int> dp(n + 1, 0); //타뷸레이션 방식
//	dp[1] = 1;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 2] + dp[i - 1];
//	}
//
//	return dp[n]; // dp 안에 다 집어넣는 방식 차례대로
//}
//
//int main()
//{
//	int n = 5;
//
//	cout << fibo1(n) << endl;
//	cout << fibo2(n) << endl;
//	cout << fibo3(n) << endl;
//}