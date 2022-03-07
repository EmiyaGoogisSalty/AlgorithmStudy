//#include <algorithm>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
///*
//	template<typename RandomIt>
//	void sort(RandomIt first, RandomIt last);
//
//	template<typename RandomIt>
//	void sort(RandomIt first, RandomIt last, Compare comp);
//
//
//	**std::sort() 함수
//
//	순차 컨테이너에 대해 (first, last) 범위의 원소들을 정해진 방법으로
//	정렬 ( 기본값: 오름차순 )
//
//	같은 값을 갖는 원소의 순서는 보장되지 않음
//	(순서 유지시 std::stabe_sort()함수 사용, 약간 느림)
//
//	std::sort()함수는 O(n log n)으로 동작해야함
//
//	C스타일 배열, vector, deque, array를 정렬할때 주로 사용
//	(list, forward_list는 자체 멤버 함수 사용)
//
//	comp 인자에 비교 함수 객체를 전달 할수 있음
//
//	
//*/
//
//class Person
//{
//public:
//	string name;
//	int age;
//
//	void print() const
//	{
//		cout << name << ", " << age << endl;
//	}
//
//	bool operator<(const Person& a) const //나이순
//	{
//		return this->age < a.age;
//	}
//};
//
//bool abs_cmp(const int a, const int b);
//
//int main()
//{
//
//
//	/*배열 사용시*/
//	int arr[5] = { 4, 2, 3, 5, 1 };
//	sort(arr, arr + 5);  // (첫번째 인자는 sort할 배열을가리킴 즉 포인터임, 두번째는 arr의 크키)
//	sort(begin(arr), end(arr)); //c++스탈 std::begin(),std::end() 라이브러리 전역함수임, arr뿐만아니라 벡터도 사용가능
//	//begin(vec)..
//
//	/*벡터 사용시*/
//	vector<string> vec = { "orange", "banana", "apple", "lemon" };
//	sort(vec.begin(), vec.end()); //오름차순으로 정렬 abc순
//
//	sort(begin(arr), end(arr), greater<>()); //내림차순 
//	sort(vec.begin(), vec.end(), greater<>()); // 내림차순
//
//	/*
//		greater<>() 내림차순 정렬을 위한 비교함수 객체 템플릿형태
//		less<>() 오름차순 , 소트함수는 그레이터를 쓰지않으면 자동으로 오름차순임 잘쓰지않음
//	*/
//
//	class AbsCmp
//	{
//	public:
//		inline bool operator()(int a, int b) const
//		{
//			return abs(a) < abs(b);
//		}
//	};
//
//	vector<int> nums = { 10, 2, -3, 5, 7 }; //절대값크기로 오름차순정렬하고 싶을때
//	sort(nums.begin(), nums.end(), abs_cmp); //abs_cmp함수를 정의해주어야함
//	sort(nums.begin(), nums.end(), AbsCmp()); //펑터를 이용한 절대값 정렬
//
//
//	sort(nums.begin(), nums.end(), [](int a, int b) {return abs(a) < abs(b); }); //람다식
//
//	/*------------------------------------------------------------------------*/
//
//	vector<Person> v;
//	v.push_back({ "Amelia", 29 });
//	v.push_back({ "Noah", 25 });
//	v.push_back({ "Olivia", 31 });
//	v.push_back({ "Shphia", 40 });
//	v.push_back({ "George", 35 });
//
//	sort(v.begin(), v.end());
//		// 정렬시 이름가나다순으로할지 나이순으로 할지 우리가 사용자정의로 정렬을 해야할 때..
//		// 세번째 인자에다가 우리가 비교함수를 정의해 쓰거나 부등호 오버로딩을 정의해주어야함
//		// sort함수 내에 person객체를 비교하는 부등호가 있을거임 그 부등호를 우리가 사용자정의오버로딩을 해서
//		// 나이순으로 정렬하자고 정의해놓으면됨!
//
//	for (const auto& p : v)
//	{
//		p.print();
//	}
//
//}
//
//bool abs_cmp(const int a, const int b)
//{
//	return abs(a) < abs(b);
//}