#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	//vec.insert(vec.begin() + 2, 15);	// 지정 위치에 데이터 삽입
	//vec.erase(vec.begin() + 1);		// 지정 위치의 데이터를 삭제

	// 접근법
	// cout << vec[0];
	// cout << vec.at(0);

	// 배열과 같이 포인터 연산이 가능하다
	// int arr[4] = {10, 20, 30, 40}
	// *(arr + 2) == arr[2] =V= 30;
	// *(itr + 2) == vec[2] == 30;

	// 순회
	// for (vector<int>::size_type i = 0; i < vec.size(); i++) {
	// 	cout << vec[i] << endl;
	// }

	//vec.pop_back();	// 맨 뒤에 위치한 데이터 삭제

	// 첫번째 원소의 데이터를 1로 바꾼다.
	// vector<int>::iterator *itr = vec.begin();
	//*itr = 1;
	//*(vec.begin()) = 1;	// 위 방법과 같은 방법이다.

	vector<int>::iterator itr = vec.begin();

	// 벡터 내에서 20인 값을 모두 지운다.
	for (; itr != vec.end(); itr ++) {
		if (*itr == 20) {
			vec.erase(itr);
			itr = vec.begin();	// 이 구문이 없으면 에러
			// 또는 vec.erase(vec.begin() + i);
		}

	}
	
	//vector<int>::const_iterator citr = vec.cbegin();
	//*citr = 300;


	// 반복자를 이용한 순회
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		cout << *itr << endl;
	}
	
	return 0;
}