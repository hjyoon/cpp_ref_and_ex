#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);

	// 전체 덱을 출력하기
	for (deque<int>::iterator itr = dq.begin(); itr != dq.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	dq.pop_front();	// 맨 앞의 원소 제거
	dq.pop_back();	// 맨 뒤의 원소 제거

	dq.push_front(5);	// 맨 앞에 원소를 추가

	// 전체 덱을 출력하기
	for (deque<int>::iterator itr = dq.begin(); itr != dq.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	return 0;
}