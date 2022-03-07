///*
//* unordered_set컨테이너 (정렬하지않을때 쓰는 set)
//	
//	template<class Key(데이터타입), class Hash(해시함수) = std::hash<Key>,
//			 class KeyEqual = std::equal_to<Key>,
//			 class Allocator = std::allocator<Key>>
//	class unordered_set;
//
//	key타입의 키 값을 저장하는 순서없는 연관 컨테이너
//	데이터 삽입, 삭제, 탐색은 O(1) 시간 복잡도로 동작
//	만약 중복되는 데이터를 unordered_set 구조로 동작하려면 std::unordered_multiset사용
//	사용자 정의 타입을 저장할 경우, 해시 함수 Hash와 비교를 위한 KeyEqual을 지정해야 함.
//	<unordered_set>에 정의 되어 있음
//	주요 함수 사용법은 std::set과 거의 유사함.
//
//	set -> 이진탐색트리를 이용함
//	unordered_set -> 해싱을 이용함
//
//
//	unordered_map 컨테이너
//		
//		template<class key, class T,
//				 class Hash = std::hash<Key>,
//				 class KeyEqual = std::equal_to<Key>,
//				 class Allocator = std::allocator<std::pair<const Key, T>>>
//		class unordered_map;
//
//	Key타입의 키(key)와 T타임의 값(value)의 쌍(pair)을 저장하는 순서없는 연관 컨테이너
//	데이터 삽입, 삭제, 탐색은 O(1) 시간 복잡도로 동작해야함
//	만약 중복되는 데이터를 unordered_map 구조로 저장하려면 std::unordered_multimap 사용
//	사용자 정의 타입을 저장할 경우, 해시함수 Hash와 비교를 위한 KeyEqual을 지정해야함
//	<unordered_map>에 정의되어있음
//	주요 함수 사용법은 std::map과 거의 유사함.
//
//*/

//#include <iostream>
//#include <string>
//#include <vector>
//#include<unordered_set>
//#include<unordered_map>
//
//using namespace std;
//
//int main()
//{
//	// car -> radio -> orange -> ear -> radio
//	// radio가 저장되어있는지없는지 중복체크하는 로직
//
//	unordered_set<string> words; //끝말잇기 게임 
//	words.insert("car"); 
//	words.insert("radio");
//	words.insert("orange");
//	words.insert("ear");
//	
//	
//	string word = "radio";
//
//	if (words.find(word) != words.end())
//	{
//		cout << word << " is used!" << endl;
//	}
//	else
//	{
//		cout << word << " is not used" << endl;
//	}
//
//	//중복되는 값을 찾을때에도 unordered_set을 활용할 수 있음
//	vector<int> numbers{ 1, 5, 3, 1, 5, 7, 4, 5, 6, 3, 2, 7, 3, 6, 2 };
//	unordered_set<int> num_set(numbers.begin(), numbers.end()); // 생성자로 인자값 전달
//
//	cout << "# of numbers: " << num_set.size() << endl;
//
//	unordered_map<string, int> fruits;
//	//정렬되지 않은 상태로 나타남
//	fruits.insert({ "apple", 1000 });
//	fruits.insert({ "banana", 1500 });
//	fruits["orange"] = 3000;
//	fruits["grape"] = 4000;
//	fruits["lemon"] = 5000;
//
//	fruits["apples"] = 2000;
//	fruits.erase("grape");
//}

