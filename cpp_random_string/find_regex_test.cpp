#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
	fstream in("output.txt");
	string s;

	//regex word_regex("\\([0-9a-zA-Z]{0,}\\)|\\[[0-9a-zA-Z]{1,}\\]|\\{[0-9a-zA-Z]{0,}\\}");
	//regex word_regex("([0-9a-zA-Z]{0,}|\\[[0-9a-zA-Z]{1,}\\]|\\{[0-9a-zA-Z]{0,}\\})");
	//regex word_regex("([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");
	//regex word_regex(".*(.)(.*(\\1)){5,}.*");
	//regex word_regex(".*\\s[A-Z][a-z]*\\s.*");
	regex word_regex(".*[Yy][Oo][Oo][Nn].*");

	if(!in.is_open()) {
		cout << "파일을 찾을 수 없습니다!" << endl;
		return -1;
	}

	int line = 0;
	int cnt = 0;

	while(getline(in, s)) {
		vector<string> v;
		smatch m;
		line++;

		if(regex_match(s, m, word_regex)) {
			cout.setf(ios::left); // 좌측정렬
			// cout.setf(ios::right); // 우측정렬
			cnt++;
			cout << setw(6) << line << " : " << s << '\n';

			//cout << "size : " << m.size() << '\n';
			// for(int i=0; i<m.size(); i++) {
			// 	// 하위표현식 역참조에 사용, m[0]은 전체 결과 집합이 들어있고, m[1]~m[3]까지 개별 결과가 들어 있다.
			// 	cout << m[i] << '\n';
			// }
		}
	}

	// while(in >> s) {
	// 	string tmp_s = s;
	// 	vector<string> v;
	// 	smatch m;
	// 	line++;

	// 	int p_cnt = 0;
	// 	while (regex_search(tmp_s, m, word_regex)) {
	// 		p_cnt++;
	// 		cout.setf(ios::left); // 좌측정렬
	// 		// cout.setf(ios::right); // 우측정렬
	// 		if(p_cnt == 1) {
	// 			cnt++;
	// 			//cout << setw(6) << line << " : " << s << '\n';
	// 		}
	// 		//cout << "size : " << m.size() << '\n';
	// 		// for(int i=0; i<m.size(); i++) {
	// 		// 	// 하위표현식 역참조에 사용, m[0]은 전체 결과 집합이 들어있고, m[1]~m[3]까지 개별 결과가 들어 있다.
	// 		// 	cout << m[i] << '\n';
	// 		// }
	// 		//cout << m[0] << '\n';
	// 		v.push_back(m[0]);
	// 		tmp_s = m.suffix();
	// 	}
	// 	if(p_cnt > 2) {
	// 		cout << setw(6) << line << " : " << s << '\n';
	// 		for(string s : v) {
	// 			cout << s << '\n';
	// 		}
	// 		cout << "p_cnt" << " : " << p_cnt << '\n' << '\n';
	// 	}
	// }

	cout << "cnt" << " : " << cnt << '\n';

	// while(1) {
	// 	in >> s;

	// 	if(in.eof()) {
	// 		break;
	// 	}
	// 	else {
	// 		cout << s << '\n';
	// 	}
	// }




	return 0;
}