#include <stdio.h>
#include <string.h>

using namespace std;

void print(char* data, int* flag, int r) {
	for (int i=0; i<r; i++) {
		printf("%c", data[flag[i]]);
	}
	printf("\n");
}

void combi_overlap(char* data, int* flag, int idx, int n, int r, int target) {
	if (r == 0){
		print(data, flag, idx);
		return;
	}
	else if (target == n){
		return;
	}
	else {
		flag[idx] = target;
		combi_overlap(data, flag, idx+1, n, r-1, target);
		combi_overlap(data, flag, idx, n, r, target+1);
	}
}

int main() {
	char a[] = "ABCD";
	int len = strlen(a);
	int r = 2;
	int flag[r] = {0, };

	combi_overlap(a, flag, 0, len, r, 0);
	return 0;
}