#include <iostream>

using namespace std;

int& foo(int& src) {
	//int tmp = 10;
	int& res = src;
	return res;
}

int main(void) {
	int a = 10;
	int& b = foo(a);
	a++;
	cout << b << endl;

	return 0;
}