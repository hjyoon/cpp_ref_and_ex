#include <iostream>
#include <thread>
#include <future>

using namespace std;

#define NUM 1
#define CNT 1000

void increase_value2(promise<int>* retVal) {
	int tmp = 0;
	for(int i=0; i<CNT; i++) {
		for(int j=0; j<CNT; j++) {
			tmp++;
		}
	}
	retVal->set_value(tmp);
}

int main(void) {
	thread t3[NUM];

	promise<int> p;

	// 미래에 int 데이터를 돌려 주겠다는 약속.
	future<int> data = p.get_future();

	for(int i=0; i<NUM; i++) {
		t3[i] = thread(increase_value2, &p);
	}

	// 미래에 약속된 데이터를 받을 때 까지 기다린다.
  	//data.wait();

	// wait 이 리턴했다는 뜻이 future 에 데이터가 준비되었다는 의미.
	// 참고로 wait 없이 그냥 get 해도 wait 한 것과 같다.
	cout << "받은 데이터 : " << data.get() << endl;

	for(int i=0; i<NUM; i++) {
		t3[i].join();
	}

	cout << "메인 함수 종료 \n";

	return 0;
}