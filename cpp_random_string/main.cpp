#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// char c_set[] = {
// 	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
// 	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
// 	'0','1','2','3','4','5','6','7','8','9',
// 	'!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
// 	':',';','<','=','>','?','@',
// 	'[','\\',']','^','_','`',
// 	'{','|','}','~',
// 	' ',
// };

char c_set[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
};

int main() {
	freopen("output.txt", "w", stdout);

	int start=0, end=0;

	end = sizeof(c_set)/sizeof(c_set[0]);

	mt19937 mtRand((unsigned int)time(NULL));
	uniform_int_distribution<char> dist1(start, end-1);

	for(int i=0; i<1000000; i++) {
		string s;
		for(int j=0; j<32; j++) {
			char c = c_set[dist1(mtRand)];
			s = s + c;
		}
		cout << s << '\n';
	}

	return 0;
}