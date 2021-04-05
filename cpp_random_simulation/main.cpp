#include <iostream>
#include <random>
#include <chrono>
#include <Windows.h>

using namespace std;

#define WIDTH 10001
#define HEIGHT 10001

int my_map[HEIGHT][WIDTH] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	random_device rd;
	mt19937 mtRand(rd());
	uniform_int_distribution<int> dist1(1, 4);
	uniform_int_distribution<int> dist2(0, WIDTH - 1);
	uniform_int_distribution<int> dist3(0, HEIGHT - 1);

	while (1) {
		int start_y = 0;
		int start_x = 0;
		int step_cnt = 0;

		chrono::system_clock::time_point start = chrono::system_clock::now();
		time_t tt = chrono::system_clock::to_time_t(start);

		cout << tt << '\n';
		mtRand.seed(tt);

		start_y = dist2(mtRand);
		start_x = dist3(mtRand);
		cout << start_y << ' ' << start_x << '\n';

		while (1) {
			if (start_y >= HEIGHT || start_x >= WIDTH || start_y < 0 || start_x < 0) {
				break;
			}
			else {
				step_cnt++;
				my_map[start_y][start_x] = 1;
			}

			switch (dist1(mtRand)) {
			case 1:
				start_x++;
				break;
			case 2:
				start_y++;
				break;
			case 3:
				start_x--;
				break;
			case 4:
				start_y--;
				break;
			}
		}

		// for(int i=0; i<HEIGHT; i++) {
		// 	for(int j=0; j<WIDTH; j++) {
		// 		if(my_map[i][j] == 0) {
		// 			cout << "бс";
		// 		}
		// 		else {
		// 			cout << "бр";
		// 		}
		// 	}
		// 	cout << '\n';
		// }

		cout << "step cnt : " << step_cnt << '\n';
		//Sleep(500);

	}

	//fclose(stdout);

	//system("output.txt");

	return 0;
}