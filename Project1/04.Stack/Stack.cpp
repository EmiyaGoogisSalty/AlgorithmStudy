/*
    스택이란?
        -   stack 물건을 쌓아올린 더미 또는 쌓는 행위
        -   자료구조ㅓ에서 스택은 데이터를 쌓아 올리듯이 저장하는 선형자료구조.
        -   후입선출 (나중에 들어온 데이터가 먼저 출력됨)
        -   데이터의 입출력이 한쪽방향에서만 수행되는 리스트
        -   스택의 사용예 : 텍스트 편집기의 실행취소기능, 뒤로가기, 함수호출 복귀주소기억...등

    스택의 주요연산
        -   push(n)
        -   pop()
        -   top()
        -   empty()
        -   size()

    배열을 이용한 스택의 구현
        -   미리 정해진 크기의 배열을 할당하고, 가장 최근에 입력된 자료위치를 가리키는 t변수를 사용
        -   push(n): n값을 1증가시키고, 해당 위치에 n대입
        -   pop(): n값을 1감소
        -   top(): arr[n]값을 반환

        -   장점: 구현이 간단, 삽입삭제가 빠르게 동작
        -   단점: 미리 정해진 크기보다 많은 데이터를 삽입할 경우, 스택오버플로우 발생
    
    연결리스트를 이용하여 스택의 구현
        -   단순 연결리스트를 이용하여, 새로 추가한 데이터를 연결리스트 맨 앞에 삽입하는 방식
        -   push(n): push_first(n)
        -   pop(): pop_first()
        -   top(): head->next값 반환
    
        -   장점: 크기가 제한되지 않음
        -   단점: 구현이 복잡하고 삽입이나 삭제시간이 오래걸림 (배열에비해)

    std::stack
        -   LIFO방식의 스택 자료구조를 구현한 컨테이너 어댑터
        -   템플릭 매개변수 T는 스택에 저장할 타입을 지정하고, Container에는 내부에서 사용할 컨테이너를 지정
        -   Container에는 deque, vector, list를 지정할 수 있음
        -   <stack>에 정의 되어 있음
*/

//벡터를 이용한 스택구현
// template<typename T>
// class Stack
// {
// public:
//     Stack(){}
//     void push(const T& e) { v.push_back(e); }
//     void pop() {v.pop_back();}
//     const T& top() const { return v.back(); }

//     bool empty() const { return v.empty(); }
//     int size() const { retrun v.size(); }

// private:
//     vector<T> v;
// };