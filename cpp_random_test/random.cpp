#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main(void) {
    random_device rd; // 하드웨어 리소스를 기반으로 난수를 생성
    for(int i=0; i<5; i++) {
        cout << rd() << endl;
    }

    mt19937 mtRand(rd()); // 메르센 트위스터(Mersenne twister) 방식으로 난수를 생성하겠다는 선언
    for(int i=0; i<5; i++) {
        cout << mtRand() << endl;
    }

    //chrono::system_clock::time_point start = chrono::system_clock::now();
    //time_t tt = chrono::system_clock::to_time_t(start);

    //mtRand.seed(tt);

    mt19937_64 mtRand_64(rd()); // 64비트 자료형
    for(int i=0; i<5; i++) {
        cout << mtRand_64() << endl;
    }

    uniform_int_distribution<int> dist1(1, 100); // 난수의 범위와 자료형 정의. rand() % 100과는 다르게 100도 나올 수 있음
    for(int i=0; i<10; i++) {
        cout << dist1(mtRand) << endl;
    }

    uniform_real_distribution<double> dist2(1.5, 3.5); // 1.5부터 3.5까지의 랜덤 실수 출력
    for(int i=0; i<10; i++) {
        cout << dist2(mtRand) << endl;
    }

    normal_distribution<double> dist3(1.5, 3.5); // 정규 분포 (평균, 표준 편차)
    for(int i=0; i<10; i++) {
        cout << dist3(mtRand) << endl;
    }

    bernoulli_distribution dist4(0.7); // 베르누이 분포, (성공 할 확률(0.0 ~ 1.0) 지정), 성공하면 true를 실패하면 false를 반환함. 
    for(int i=0; i<10; i++) {
        cout << dist4(mtRand) << endl;
    }

    std::binomial_distribution<int> dist5(100, 0.5); // 베르누이 분포, (시도 횟수, 확률(0.0 ~ 1.0)), 성공한 횟수를 반환 
    for(int i=0; i<10; i++) {
        cout << dist5(mtRand) << endl;
    }

    return 0;
 
}