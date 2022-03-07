//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <set>
//#include <string>
//#include <map>
//
//using namespace std;
////
///*
//	STL 컨테이너 종류
//
//	순차 컨테이너: vector, array, deque, list, forward_list
//
//	연관 컨테이너: set, multiset, map, multimap
//
//	순서없는 연관 컨테이너: unordered_set, unordered_multiset, unordered_map, unordered_multimap
//
//	컨테이너 어댑터: stack, queue, priority_queue
//
//
//	set 과 map 차이
//
//	- set은 키만 저장
//	- map은 키와 값을 저장
//
//	set과 multiset 차이
//
//	- set은 고유한 키의 데이터만 저장(중복 허용 안함)
//	- multiset은 중복되는 데이터를 저장
//
//	set과 unordered_set차이
//
//	- set은 내부에서 데이터를 정렬해서 저장
//	- unordered_set은 데이터를 정렬하지 않음
//
//
//	* set 컨테이너 *
//	
//		template<class Key, class Compare = std::less<key>,
//				class Allocator = std::allocator<key>>
//		class set;
//
//	- Key 타입의 키값을 저장하는 연관 컨테이너
//
//	- 저장된 데이터는 키 값을 기준으로 정렬됨
//
//	- 데이터 삽입, 삭제, 탐색은 O(log n) 시간 복잡도로 동작
//
//	- std::set은 보통 레드-블랙 트리를 이용하여 구현됨
//
//	- 만약 중복되는 데이터를 set구조로 저장하려면 std::multiset 컨테이너를 사용
//
//	- 만약 데이터를 정렬되지 않은 상태로 저장하려면 std::unordered_set 컨테이너를 사용
//
//	- 사용자 정의 타입을 저장할 경우, 비교연산(<,>...)을 지원해야함
//
//	- #include<set>에 정의 되어 있음
//
//
//	begin(), end(), rbegin(), rend() : 순 방향 및 역방향 반복자 반환
//
//	insert(): (중복되지 않는) 새로운 원소를 삽입 
//
//	erase(): 특정 원소 삭제
//
//	find(): 특정 키 값을 갖는 원소를 찾아 반복자를 반환. 원소를 끝까지 찾지 못하면
//			end()에 해당하는 반복자를 반환. (cf.)contains()
//
//	clear(): 모든 원소를 삭제
//
//	size(): 원소의 개수를 반환
//
//	empty(): set이 비어있으면 true를 반환
//
//
//
//
//	* map 컨테이너 *
//			template<class Key, class T, 
//					 class Compare = std::less<Key>,
//					 class Allocator = <std::allocator<std::pair<const Key, T>>>
//			class map;
//
//	set컨테이너와 매우 흡사 
//	Key타입의 키와 T타입의 값과 쌍을 저장하는 연관 컨테이너
//	저장된 데이터는 키 값을 기준으로 정렬됨
//	데이터 삽입, 삭제, 탐색은 O(log n) 시간 복잡도로 동작
//	보통 레드 블랙 트리를 이용하여 구현됨
//	만약 중복되는 데이터를 map 구조로 저장하려면 mtd::multimap 컨테이너를 사용
//	만약 데이터를 정렬되지 않은 상태로 저장하려면 std::unordered_map 컨테이너를 사용
//	사용자 정의 타입을 저장할 경우, 비교 연산을 지원해야 함 (연산자 오버로딩)
//	<map>에 정의되어 있음
//
//	begin(), end(), rbegin(), rend()
//	insert()
//	erase()
//	*operator[] : 특정 키에 해당하는 원소의 값을 참조로 반환. 해당 키의 원소가 없으면
//				  새로운 원소를 기본 값으로 생성하여 참조를 반환.
//	
//	find()
//	clear()
//	size()
//	empty()
//
//*/
//
//int main()
//{
//	set<int> odds; //홀수 정수값 저장
//	//set<int> odds { 1,7,5,4,9}; 라고 초기화할수도 있음
//
//	set<int, greater<>> evens{ 2, 4, 6, 8 }; //내림차순으로 짝수값 저장, greater<> 인자추가
//
//	evens.insert(10);
//	evens.insert(2); //초기값에있는 키값이 중복이되면 인서트의 2인 값은 무시됨
//
//	if (evens.find(4) != evens.end())
//	{
//		cout << "4 is found!" << endl;
//	}
//	else
//	{
//		cout << "4 is not found" << endl;
//	}
//	// 파인드함수를써서 특정값을 찾을때 만약 찾지못하면 반복자는 end()위치를 가리킴
//	// if조건문엔 만약 파인드(4)값이 엔드가 아닐경우 즉 찾은경우
//
//
//	odds.insert(1);
//	odds.insert(7);
//	odds.insert(5);
//	odds.insert(3);
//	odds.insert(9); //값들 삽입
//
//	for (auto n : odds)
//	{
//		cout << n << ", ";
//	}
//	cout << endl;
//	// 오름차순으로 정렬되는 특징이 있다. 
//
//	for (auto n : evens)
//	{
//		cout << n << ", ";
//	}
//	cout << endl;
//
//	using psi = pair<string, int>; //using 선언
//
//	//struct psi
//	//{
//	//	string first;
//	//	int second;
//
//	//}; 
//	//사용자 정의타입에 대해서 키값을 쓰고 싶을땐 컴파일러의 비교연산을 위해 
//	// 연산자 오버로딩을 재정의하여 쓰면됨.
//
//	//문자열가 정수값을 쌍으로 이루는 타입을 선언하고싶을때
//	set<psi> managers{ {"Amila", 29}, {"Noah", 25}, {"Olivia", 31} };
//	managers.insert({ "George", 35 });
//
//	psi person1 = { "Noah", 25 };
//
//	if (managers.find(person1) != managers.end())
//	{
//		cout << person1.first << "is a manager!" << endl;
//	}
//	else
//	{
//		cout << person1.first << "is not a manager!" << endl;
//	}
//
//	managers.erase({ "Sophia", 40 }); //없는 키값이기에 무시됨
//	managers.erase({ "Noah", 30 }); //30살의 노아는 없기에 무시됨
//
//	for (const auto& m : managers)
//	{
//		cout << m.first << "(" << m.second << ")" << endl;
//		// first -> 저장된 키값 첫번째 
//		// first -> 저장된 키값 두번째 
//	}
//
//	/*----------------------------------------------------------*/
//	
//	map<string, int> fruits; //과일이름과 가격을 저장
//
//	fruits.insert({ "apple", 1000 }); //중괄호는 페어를 뜻함 
//	fruits.insert({ "banana", 1500 });
//	
//	// 맵도 자체적으로 abc순으로 정렬을 해놓기 때문에 인서트 순서에 상관없이 오름차순 정렬됨
//
//	// operator[]
//	cout << fruits["apple"] << endl;
//	//대괄호연산자 안에 키값을 넣게되면 그안에 페어값을 참조하여 반환함.
//
//	fruits["orange"];
//	//코드를 이렇게만 작성하면 키값만 설정이 되고, 안에 페어값(int)는 0으로 초기화됨.
//	fruits["orange"] = 3000;
//
//	// fruits& operator[](int a) ;
//
//
//	fruits["grape"] = 4000;
//	fruits["lemon"] = 1000;
//
//	fruits["apple"] = 2000; //기존애플의 페어값을 바꿀 수도 있음.
//
//	fruits.erase("apple"); //키값만 넣으면 지워짐
//
///*	for (auto [name, price] : fruits)
//	{
//		cout << name << " is " << price << "won." << endl;
//	}*/ //?
//
//	for (const auto& p : fruits)
//	{
//		cout << p.first << " is " << p.second << " won." << endl;
//	}
//
//
//}