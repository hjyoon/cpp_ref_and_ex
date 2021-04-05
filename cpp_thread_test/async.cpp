#include <iostream>
#include <thread>
#include <future>

using namespace std;

int sum(int n, int m) {
	int tmp = 0;
	for(int i=n; i<=m; i++) {
		tmp += i;
	}
	return tmp;
}

int main(void) {
	// std::launch::async : 바로 쓰레드를 생성해서 인자로 전달된 함수를 실행한다.
	// std::launch::deferred : future 의 get 함수가 호출되었을 때 쓰레드를 생성해서 실행한다.
	future<int> data = async(std::launch::async, sum, 1, 10);

	cout << "합 : " << data.get() << endl;

	cout << "메인 함수 종료 \n";

	return 0;
}