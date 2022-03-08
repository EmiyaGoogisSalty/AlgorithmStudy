/*
    큐란?
        -   queue 땋아늘인 머리, 대기열, 줄을 서다.
        -   자료구조에서 큐는 데이터를 마치 줄을 세워 늘여놓듯이 저장하는 선형자료 구조
        -   선입선출: 먼저 들어온 데이터가 먼저 출력. (FIFO)
        -   데이터삽입은 뒤쪽(rear)에서, 데이터 삭제는 앞쪽(front)에서 수행되는 리스트
        -   매표소대기열, 프린터 큐(요청순), 윈도우즈 메세지 처리 ...등

    큐의 주요연산
        -   enqueue(e) 큐의 맨 뒤(rear)에 원소e 추가. push(e)
        -   dequeue()  큐의 맨 앞에 있는 원소삭제. pop()
        -   front()    큐의 맨 앞에 있는 원소를 참조 peek()
        -   empty()
        -   size()

          pop  <- | front  |   |   |   |   | rear | <- push
    
    배열을 이용한 큐의 구현                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        -   미리 정해진 크기의 배열을 할당하고, 큐의 앞과 뒤를 나타내는 front와 rear변수를 사용
        *   enqueue(e) : rear값을 1증가시키고, 해당위치에 e를 대입
        *   dequeue()  : front값을 1 증가시킴.
        *   front()    : arr[front]값을 반환
        *   이러한 큐를 환형큐 서큘러 큐라고도 한다. 
    
    연결 리스트를 이용한 큐의 구현
        -   이중연결 리스트를 이용. 새로추가한 데이터를 연결리스트 맨 앞에 삽입하는 방식
        *   enqueue(e) : push_back(e)
        *   dequeue()  : pop_front()
        *   front()    : header -> next 값을 반환
    
    std::queue
        template <class T, class Container = stdd:deque<T>> class queue;
        -   FIFO 방식의 큐 자료구조를 구현한 컨테이너 어댑터
        -   템플릿 매개변수 T는 큐에 저장할 타입을 지정. 컨테이너에는 내부에서 사용할 컨테이너를 지정
        -   컨테이너에슨 deque 또는 list를 지정할수 있음
        -   <queue>에 정의되어 있음
        -   push, pop 
*/

//std::list를 이용한 큐의 구현
// #include <list>
// #include <iostream>
// using namespace std;

// template <typename T>
// class Queue
// {
// public:
//     Queue() {}

//     void enqueue (const T& e) { lst.push_back(e); }
//     void dequeue () { list.pop_front(); }
//     const T& front() const { return lst.front(); }

//     bool empty() const { return lst.empty(); }
//     int size() const { return lst.size(); }

// private:
//     list<T> lst;

// };

// int main()
// {
//     Queue<int> q;
//     q.enqueue(10);
//     q.enqueue(2);
//     q.enqueue(30);
//     q.dequeue();

//     cout << q.front() << endl;
//     q.enqueue(50);

//     while (!q.empty())
//     {
//         auto& i = q.front();
//         cout << i << ", ";
//         q.dequeue();
//     }

//     cout << endl;
// }