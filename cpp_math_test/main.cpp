#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int check(int a) {
	int tmp = 1;
	for(int i=0; i<10; i++) {
		if(tmp == a) {
			return 0;
		}
		tmp *= 2;
	}
	return -1;
}

double logB(double x, double base) {
	return log(x) / log(base);
}

int main() {
	random_device rd;
	mt19937 mtRand(rd());
	
	uniform_real_distribution<double> dist1(0, 20); // 1.5부터 3.5까지의 랜덤 실수 출력

    int n = 20;
    for(int i=1; i<=n; i++) {
    	cout << "i = " << i << '\n';
    	set<pair<double,double>> s;
		for(int i=0; i<10000000; i++) {
	    	double a = 0, b = 0;
	    	a = dist1(mtRand);
	    	uniform_real_distribution<double> dist2(a, 20);
	    	b = dist2(mtRand);
	    	a = round(a*10)/10;
	    	b = round(b*10)/10;
	    	if(b-a > 0 && b-a <= n/2) {
	    		s.insert(make_pair(a,b));
	    	}
	    }

	    cout << "s cnt : " << s.size() << '\n';

	    //sort(va.begin(), va.end());
    	//sort(vb.begin(), vb.end());

    	for(pair<double,double> p : s) {
    		double a = p.first;
    		double b = p.second;
    		double res_a = i*a-a*a;
    		double res_b = i*b-b*b;
			if(res_a == res_b && res_a-(int)res_a == 0 && check((int)res_a) == 0) {
				cout << a << ' ' << b << '\n';
			}
    	}


	    //cout << *max_element(va.begin(), va.end()) << '\n';
	    //cout << *max_element(vb.begin(), vb.end()) << '\n';
    	
    }

    // for(int i=1; i<=n; ) {
    // 	double r = dist2(mtRand);
    // 	// if(logB(i*r-r*r, 2) == 2) {
    // 	// 	cout << r << '\n';
    // 	// }
    // 	cout << r << '\n';
    // 	if(r == 50.0) {
    // 		break;
    // 	}
    // }

    

    // for(double i : va) {
    // 	cout << i << '\n';
    // }

    // for(double i : vb) {
    // 	cout << i << '\n';
    // }

	return 0;
}