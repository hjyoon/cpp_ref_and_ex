#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

void BigLoop() {
    for (int i = 1; i <= 50000; i++) {
        for (int j = 1; j <= 50000; j++) {
            int x = (i + j) * 2 + (i / j);
        }
    }
}

int main(void) {
	// now() 함수를 통해 현재 시간값을 구한다.
    chrono::system_clock::time_point start = chrono::system_clock::now();
    // steady_clock::time_point start = steady_clock::now();

    time_t tt = chrono::system_clock::to_time_t(start);
    struct tm *t;
	t = localtime(&tt);
    //cout << put_time(t, "%H:%M:%S") << endl; // include iomanip // 현재 시간 출력
    cout << asctime(t);
 
    BigLoop();
 
    chrono::system_clock::time_point end = chrono::system_clock::now();
    //steady_clock::time_point end = steady_clock::now();

    // steady_clock 이외의 clock 클래스는 time_point를 얻은 후 
	// 운영체제의 시간을 뒤로 돌린 후 time_point을 얻으면 시간이 과거의 값으로 구해진다.
 
    // 시간 단위
	chrono::hours hour = chrono::duration_cast<chrono::hours>(end - start);

	// 분 단위
	chrono::minutes min = chrono::duration_cast<chrono::minutes>(end - start);

	// 초 단위
	chrono::duration<double> sec = end - start;

	// 밀리 초 단위 (1/1000)
	chrono::milliseconds milliSec = chrono::duration_cast<chrono::milliseconds>(end - start);

	// 마이크로 초 단위 (1/1000000)
	chrono::microseconds microSec = chrono::duration_cast<chrono::microseconds>(end - start);

	// 나노 초 단위 (1/1000000000)
	chrono::nanoseconds nanoSec = end - start;

	cout << sec.count() << " sec" << endl;
	cout << hour.count() << " hour" << endl;
	cout << min.count() << " min" << endl;
	cout << milliSec.count() << " milliSec" << endl;
	cout << microSec.count() << " microSec" << endl;
	cout << nanoSec.count() << " nanoSec" << endl;

	return 0;
}