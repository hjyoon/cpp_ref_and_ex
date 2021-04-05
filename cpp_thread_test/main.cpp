#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

#define NUM 10
#define CNT 10

mutex value_mutex;

void func(int n) {
	for(int i=0; i<CNT; i++) {
		value_mutex.lock();
		cout << "thread " << n << " ... (" << i << ")" << endl;
		value_mutex.unlock();
	}
}

int n = 0;

void increase_value() {
	for(int i=0; i<100; i++) {
		n++;
	}
}

int main(void) {
	thread t[NUM];
	for(int i=0; i<NUM; i++) {
		t[i] = thread(func, i);
	}

	thread t2[NUM];
	for(int i=0; i<NUM; i++) {
		t2[i] = thread(increase_value);
	}

	// thread t1(func, 1);
	// thread t2(func, 2);
	// thread t3(func, 3);

	// detach 는 말 그대로, 해당 쓰레드를 실행 시킨 후, 잊어버리는 것 이라 생각하시면 됩니다. 대신 쓰레드는 알아서 백그라운드에서 돌아가게 됩니다.
	// t1.detach();
	// t2.detach();
	// t3.detach();

	// join 은, 해당하는 쓰레드들이 실행을 종료하면 리턴하는 함수 입니다. 따라서 t1.join() 의 경우 t1 이 종료하기 전 까지 리턴하지 않습니다.

	for(int i=0; i<NUM; i++) {
		t[i].join();
		value_mutex.lock();
		cout << "thread " << i << " is " << "finished" << endl;
		value_mutex.unlock();
	}

	for(int i=0; i<NUM; i++) {
		t2[i].join();
	}

	cout << n << endl;

	cout << "메인 함수 종료 \n";

	return 0;
}