//#include <algorithm>
//#include <vector>
//#include <iostream>
//
//using namespace std;

/*
	이진탐색(binary search)
	정렬된 배열에 대해 검색 단계별로 검색 범위를 반으로 줄여가면서 데이터를 탐색하는 기법

	이미 정렬이 되어있어햐 가능함 !

	ex)
	1	2	3	5	7	10	13	15	18	23	25	27	28	30	33

	find(23)

	1	2	3	5	7	10	13	15	18	23	25	27	28	30	33
	^							^							^
	lower = 0					middle (lower+upper)/2		upper= 14

	-반으로 갈라서 middle값과 find값을 비교함
	- 23은 15보다 크기 때문에 미들부터 어퍼까지 탐색범위가 줄여짐 
	- middle위치에 lower위치를 옮겨서 lower = middle 이 되게 만들기

	줄여진 범위에서 middle을 정해서 ( (lower+upper)/2 자리 ) 파인드(23)값과 미들(27)값과 비교
	미들과 어퍼는 27 ~33이기때문에 찾고자하는 23이 없는 범위임

	검색범위 또줄여주고 또줄여줌... 

	middle값이 23이면 트루

	* 시간복잡도 : O(log n)
	
	* 장점: 검색속도가 빠름, 상당히 간단
	* 단점: 이미 정렬되어있는 데이터에만 적용가능



	*std::binary_search() 함수

	template <class ForwardIt, class T>
	bool binary_search(ForwardIt first, ForwardIt last, const T& value);

	template <class ForwardIt, class T, class Compare>
	bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);

	정렬된 컨테이너에서 first,last범위 안에 value값이 있는지 검사
	최소 first last 범위 안에서라도 정렬이 되어 있어야 동작함
	기본적으로 < 연산자를 이용하여 값을 비교하고 비교함수 comp를 지정할수도 있음
	<algorithm>에 정의되어있음

*/

//bool binary_search(int data[], int n, int target)
//{
//	int lower = 0;
//	int upper = n - 1;
//
//	if (data[lower] > target || data[upper] < target)
//	{
//		return false;
//	} //예외처리 해주기 중간에서 타겟값을 반환할수 없기에 
//
//	while (lower <= upper)
//	{
//		int mid = (lower + upper) / 2;
//
//		if (data[mid] == target)
//			return true;
//
//		else if (data[mid] < target)		//미드값이 타겟보다 작으면 lower ~ mid 범위
//			lower = mid + 1;				
//
//		else								//그렇지 않으면 lower ~ upper 범위
//			upper = mid - 1;
//	}
//
//	return false;
//}
//
//int main()
//{
//	int data[] = { 1,2,3,4,5,6,7,8,10,15,18,23,25,27,29,30,33 };
//	int target = 23; //찾으려고 하는 값
//
//	
//	bool res2 = binary_search(data, std::size(data), target); //정의해놓은 함수
//	bool res3 = std::binary_search(std::begin(data), std::end(data), target); //라이브러리 함수
//
//	std::cout << res2 << std::endl; //찾으면 트루반환 1
//	std::cout << res3 << std::endl;	
//}