#include <iostream>
#include <thread>
#include <future>

using namespace std;

int increase_value3(int x) {
	return x+1;
}

int main(void) {
	// int(int) : int 를 리턴하고 인자로 int 를 받는 함수.
	packaged_task<int(int)> task(increase_value3);

	future<int> data = task.get_future();

	thread t(std::move(task), 1);

	cout << "받은 데이터 : " << data.get() << endl;

	t.join();

	cout << "메인 함수 종료 \n";

	return 0;
}