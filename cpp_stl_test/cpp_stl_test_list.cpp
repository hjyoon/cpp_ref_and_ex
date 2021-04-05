#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		// 만일 현재 원소가 20 이라면
		// 그 앞에 50 을 집어넣는다.
		if (*itr == 20) {
			lst.insert(itr, 50);
		}
	}

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		// 값이 30 인 원소를 삭제한다.
		if (*itr == 30) {
			lst.erase(itr);
			break;
		}
	}

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		cout << *itr << " ";
	}


	return 0;
}