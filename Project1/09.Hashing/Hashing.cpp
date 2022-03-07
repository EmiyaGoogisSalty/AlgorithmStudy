

/*	해싱이란?
		hash : 잘게 썰은 것, 긁어 모은 것, 아무렇게나 뒤섞다.

	각각의 데이터를 (가급적) 고유한 숫자 값으로 표현하고, 이를 이용하여 특정 데이터의
	존재여부를 확인하거나 또는 원본 데이터를 추출하는 작업.

	응용분야: 빠른 자료 탐색(O(1)), 변조 탐지 및 에러 검출(MD5, SHA)
	
	ex) 책의 맨 뒷쪽 인덱스 찾아보기 같은 모양..

	예시 
		요구사항: 정수를 저장하고 있는 컨테이너가 있고, 이 컨테이너에 특정 정수가 들어 있는지를
				 빠르게 판단 하고 싶을 때

		해결방법: 적절한 크기의 bool 타입 배열을 하나 만들고, 이 배열에서 입역 정수에 해당하는
				 인덱스의 원소 값을 true로 설정

			|	2,  5	|
			|	4, 7	|	??     ->		bool data[8] = {}; false초기화
			_____________					data[2] = true;
			<랜덤주머니>						data[4] = true;
											data[5] = true;
											data[7] = true;
		문제점:
			정수 범위가 너무 크다면? 데이터가 실수라면? 데이터가 숫자가 아니면?
			배열의 크기가 너무 크게 잡히기 때문에 메모리 손실이 일어남 (비효율적)

			해결-> 어떠한 데이터 타입의 값이든 원하는 범위의 정수로 매핑하는 함수를 만들어 사용

			hash(x) = x % n

			hash(해시함수) (x)(키) = x%n <- 해시 값

			bool 배열을 만들지말고 인트형 백터를 하나 선언 (불로쓰면 어떠한값이 트루가 되는지 모르기때문에)

			vector<int> data(8) = {};
			data[ 2 % 8 ]
			data[ 4 % 8 ]
			data[ 5 % 8 ]
				...
			data[ 9999 % 8 ]
			
		해시함수(hash function)
		- 주어진 데이터로부터 (가급적) 고유한 숫자 값을 계산하는 함수
		- 보통 함수의 출력은 고정된 범위의 정수로 매핑됨 
		- 예를들어, h(k) = k % n 함수는 입력 k를 [0,n-1] 범위의 정수로 매핑하는것임

			키(key)		해시함수		해시 값			해시 테이블

			Amelia		변환			02로변환			[02] 524-1234


		키
		-해시 함수의 입력으로, 입력 데이터 자체이거나 또는 데이터를 구분하는 값

		해시값
		- 해시 함수의 출력, 보통 해시테이블의 인덱스로 사용됨
		- 해시 코드 또는 해시라고도 부름

		해시테이블
		- 입력 데이터가 저장되는 배열로서, 해시 함수에 의해 계산된 인덱스에 데이터가 저장됨
		- 해시 맵(hash map) -> key와 value값으로 구성
		- 해시 셋(hash set) -> key만 구성

		버킷
		- 해시 테이블에서 하나의 데이터가 저장된 공간 (하나의 원소를 가리키는 말)
		- 슬롯(slot) 셀이라고도 부름

		충돌
		- 해시 함수가 서로 다른키에 대해 같은 해시 값을 반환함으로써, 다수의 키가 같은 해시값을
		  갖게 되는 현상 해시테이블에서 하나의 버킷에 여러개의 데이터를 저장하려고 하는 상황

		- 해시테이블의 크기가 저장할 데이터의 개수보다 작으면 반드시 충돌이 발생함
		- 해시테이블의 크기가 저장할 데이터의 개수보다 크더라도 해시 함수의 동작에 따라 충돌이 발생할 수 잇음

		- 체이닝, 오픈 어드레싱, 뻐꾸기 해싱 등의 방법으로 해결

		-------------------------------------------------------------------------------------------
		** 체이닝
			- 해시 테이블의 특정 위치에서 하나의 키를 저장하는것이 아니라 하나의 '연결리스트'를 저장하는 기법
			- 새로 삽입된 키에 의해 충돌이 발생하면 리스트에 새로운 키를 추가한다. 

			키(key)		해시함수		해시 값			해시 테이블

			Amelia		변환			02로변환			[02]  Amellia 524-1234 -> George 386-2580 
														(리스트 설정)

		
		체이닝 특징 : 삽입연산은 O(1)의 시간 복잡도로 동작
					 (최악의 경우) 모든 데이터가 같은 해시 값을 가질경우(하나의 해시값에 연결리스트가 연결되어있는경우),
					 탐색연산은 O(n)의 시간 복잡도로 동작

					 삭제 연산의 경우, 먼저 탐색을 수행하므로 최악의 경우 O(n)의 시간 복잡도로 동작.

		부하율과 재해싱
			- 부하율(load factor) : 해시 테이블에서 각각의 리스트에 저장되는 키의 평균개수.
				
										a = n / m

				n: 해시 테이블에 저장할 전체 키의 개수
				m: 해시 테이블 크기(연결 리스트 개수)
				a: 부하율

			- 부하율이 1보다 작으면 저장할 데이터수 보다 해시테이블을 크게 잡은경우임 메모리낭비
			- 부하율이 1보다 크면 충돌이 많이 발생하며 리스트가 크게 증가하기때문에 탐색삭제연산이 느리게 동작
				재해싱을 통해 부하율이 1에 가까운 값이 되도록 조정

		-------------------------------------------------------------------------------------------
		** 오픈 어드레싱 (open addressing) 열린주소지정
			- 해시 충돌이 발생할 경우, 해시 테이블에서 다른 비어잇는 버킷을 찾아 데이터를 저장하는 방식.
			- 해시 테이블의 크기가 데이터 개수보다 커야함.
			- 새로운 위치 탐사 방식
					- 선형탐사
					- 제곱탐사
					- 이중해싱
			
			선형탐사: 특정 해시 값에서 충돌이 발생하면 해당 위치에서 하나씩 다음 위치로 이동하면서 
					  비어있는 위치에 원소 삽입
					  즉, h(key)가 사용중일때 h(key)+1, h(key)+2 .... 순서로 빈 위치를 찾음
					  데이터가 특정 위치에 몰리게 되는 군집화(clustering)되는경우 해싱 효율이 떨어 질 수 있음..

					  hash(x) = x % 7

			제곱탐사: 고정 크기로 이동하는 선형 탐사와 달리 제곱수 크기로 이동하면서 비어있는 위치를 찾응 방식
					  즉, h(key)가 사용중이면 h(key)+1^2, h(key)+2^2.... 순서로 빈 위치를 찾음
					  군집화를 피하기위해 간격을 두고 데이터를 저장하는 방식..

					  hash(x) = x % 7  => 1에 삽입할경우 제곱 제곱하면서 빈위치를 찾아냄

		-------------------------------------------------------------------------------------------
		실수 해시 함수
		- 주어진 실수를 적절하게 조작하거나 또는 실수의 각 숫자를 조합하여 해시 값 생성

		예) 실수 키 x가 주어질 경우, 0에서 1사이의 임의의 실수 A를 곱한 결과의 소수점 아래 부분을
			s로 설정
			0 <= s < 1		0 <= sm < m

			이후 s에 정수 m을 곱한 후, 소수점 아래를 버림으로써 [0, m-1] 사이의 정수를 얻을 수 있음

		문자열 해시 함수
		- 문자열의 각 문자를 아스키코드로 변환하고, 이 값을 조합하여 해시 값 생성
		
		예) "cat" 이라는 문자열을 정수 형태로 변환 할 경우, 'c'= 99, 'a'= 97, 't' = 116 이므로
			99 * 128^2 + 97 * 128^1 + 116 * 128^0 = 1,634,548를 얻을 수 있음

		- 이후 해시 테이블 크기에 맞게 나머지 연상을 수행



		좋은 해시 함수의 조건

		- 빠르고 효율적인 연산
		- 해시 값이 균일하게 분포
			충돌 최소화
			해시 테이블 사용 효율이 높을 것
			사용할 키의 모든 정보를 이용


	


*/


		
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <list>
//
//using namespace std;
//
//class hash_set
//{
//private:
//	int sz; //데이터의 크기
//	std::vector<int> data;
//
//public:
//	hash_set(int n) : sz(n), data(sz, -1) {}
//
//	int hash(int key) { return key % sz; } //해시값을 구해주는 해시함수
//
//	void insert(int value) 
//	{
//		data[hash(value)] = value;
//	}
//
//	bool find(int value)
//	{
//		return (data[hash(value)] == value);
//	}
//
//	void erase(int value)
//	{
//		data[hash(value)] = -1;
//	}
//
//	void print()
//	{
//		for (auto n : data)
//		{
//			cout << n << endl;
//		}
//	}
//};
//
//class chaning_hash // 체이닝을 구현한 해싱 클래스
//{
//private:
//	int sz;
//	vector<list<int>> data;
//	// 만약 키와 밸류 쌍으루 이루는 데이터를 hash_map으로 구성하려면 std::pair사용하기
//	// vector<list<pair<string,int>>> data;
//
//public:
//	chaning_hash(int n) : sz(n), data(sz) {}
//
//	int hash(int key) { return key % sz; }
//
//	void insert(int value)
//	{
//		data[hash(value)].push_back(value);
//	}
//
//	bool find(int value)
//	{
//		auto& entries = data[hash(value)];
//		
//		return std::find(entries.begin(), entries.end(), value) != entries.end();
//	}
//
//	void erase(int value)
//	{
//		auto& entries = data[hash(value)];
//		auto it = std::find(entries.begin(), entries.end(), value);
//
//		if (it != entries.end())
//		{
//			entries.erase(it);
//		}
//	}
//
//	void print()
//	{
//		for (int i = 0; i < sz; i++)
//		{
//			cout << i << ": "; //버킷
//			for (auto n : data[i])
//			{
//				cout << n << ", ";
//			}
//
//			cout << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	hash_set num_set(7);
//
//	num_set.insert(10); //3번째원소에 10값 들어감
//	num_set.insert(15); // 1번째
//	num_set.insert(20); // 6번째
//	num_set.insert(100); // 2번째
//
//	num_set.print();
//
//	int value = 10;
//
//	if (num_set.find(value))
//		cout << value << " is found!" << endl;
//	else
//		cout << value << " is not found" << endl;
//
//	num_set.insert(2); // 2번째 원소값에 들어가게 되는데
//	num_set.print(); // 그렇게되면 원래 2번째에 있던 100값이 사라지고 2로 덮어씌워짐
//
//	value = 100;
//
//	if (num_set.find(value))
//		cout << value << "is found!" << endl;
//	else
//		cout << value << " is not found.." << endl;
//
//	// 100 값을 찾을 수 없다고 나옴. 하지만 분명히 우리는 인서트 100 을 넣은 상황
//
//	cout << endl << endl;
//
//	//체이닝 기법
//	chaning_hash num_set2(7);
//
//	num_set2.insert(10);
//	num_set2.insert(14);
//	num_set2.insert(20);
//	num_set2.insert(100);
//
//	int value2 = 10;
//
//	if (num_set2.find(value))
//		cout << value << " is found!" << endl;
//	else
//		cout << value << " is not found" << endl;
//
//	num_set2.insert(2);
//
//	value2 = 100;
//
//	if (num_set2.find(value))
//		cout << value << " is found!" << endl;
//	else
//		cout << value << " is not found" << endl;
//
//	num_set2.print();
//
//}