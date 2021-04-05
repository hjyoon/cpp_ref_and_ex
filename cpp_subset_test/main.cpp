#include <stdio.h>
#include <string.h>

using namespace std;

void print(char* data, int* flag, int cur_size) {
   for (int i = 0; i < cur_size; i++) {
      printf("%c", data[flag[i]]);
   }
   printf("\n");
}

void subset(char* data, int* flag, int idx, int n, int cur_size) {
	if (idx == n+1){
		print(data, flag, cur_size);
		return;
	}

	flag[cur_size] = idx;
	subset(data, flag, idx+1, n, cur_size+1);
	subset(data, flag, idx+1, n, cur_size);
}

int main() {
	char a[] = "ABCD";
	int len = strlen(a);
	int flag[len] = {0, };

	subset(a, flag, 0, strlen(a)-1, 0);
	return 0;
}