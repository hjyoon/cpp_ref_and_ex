#include <iostream>

using namespace std;

int main() {
	// long double d = 0;

	// cout.precision(32);

	// for(int i=0; i<1000; i++) {
	// 	d = d + (100-d)*0.01;
	// 	cout << i << " " << d << endl;
	// }

	int a = 100;

	cout.precision(32);

	for(int i=0; i<1000; i++) {
		double d = (100*(100/(double)(a+100)));
		cout << a << " " << d << endl;
		a+=1;
	}

	return 0;
}