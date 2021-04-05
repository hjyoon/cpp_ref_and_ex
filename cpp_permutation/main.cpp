#include <stdio.h>
#include <string.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(char* data, int* flag, int n) {
	for(int i=0; i<n; i++) {
		printf("%c", data[flag[i]]);
	}
	printf("\n");
}

void perm(char* data, int* flag, int depth, int n) {
	if(depth == n) {
		print(data, flag, n);
		return;
	}
	for (int i=depth; i<n; i++) {
		swap(&flag[depth], &flag[i]);
		perm(data, flag, depth+1, n);
		swap(&flag[depth], &flag[i]);
	}
}

bool next_perm_dictionary_non_recursive(int* flag, int n) {
	int i = n-1;
	while(i > 0 && flag[i-1] >= flag[i]) {
		i--;
	}
	if (i <= 0) {
		return false; // 마지막 순열
	}
    int j = n-1;
    while (flag[j] <= flag[i-1]) {
        j--;
    }
    swap(&flag[i-1], &flag[j]);
    j = n-1;
    while (i < j) {
        swap(&flag[i], &flag[j]);
        i++; 
        j--;
    }
    return true;
}

bool next_perm_overlab_dictionary_non_recursive(int* flag, int n, int r) {
	/* this check is not strictly necessary, but if r is not close to n,
	   it makes the whole thing quite a bit faster */
	// if(flag[r-1] < n-1) {
	// 	flag[r-1]++;
	// 	return true;
	// }
	int i = r-1;
	while(flag[i] >= n-1) {
		i--;
		if(i < 0) {
			return false;
		}
	}
	flag[i]++;
	while(i < r-1) {
		flag[i+1] = 0;
		i++;
	}
	return true;
}

bool next_comb_non_recursive(int* flag, int n, int r) {
	/* this check is not strictly necessary, but if r is not close to n,
	   it makes the whole thing quite a bit faster */
	if(flag[r-1] < n-1) {
		flag[r-1]++;
		return true;
	}
	int i = r-1;
	while(flag[i] >= n-(r-i)) {
		i--;
		if(i < 0) {
			return false;
		}
	}
	flag[i]++;
	while(i < r-1) {
		flag[i+1] = flag[i] + 1;
		i++;
	}
	return true;
}

bool next_comb_overlab_non_recursive(int* flag, int n, int r) {
	/* this check is not strictly necessary, but if r is not close to n,
	   it makes the whole thing quite a bit faster */
	// if(flag[r-1] < n-1) {
	// 	flag[r-1]++;
	// 	return true;
	// }
	int i = r-1;
	while(flag[i] >= n-1) {
		i--;
		if(i < 0) {
			return false;
		}
	}
	flag[i]++;
	while(i < r-1) {
		flag[i+1] = flag[i];
		i++;
	}
	return true;
}

int main() {
	char a[] = "ABCD";
	int len = strlen(a);

	// init flag
	int flag[len] = {0, };
	for(int i=0; i<len; i++) {
		flag[i] = i;
	}

	perm(a, flag, 0, len);

	// do {
	// 	print(a, flag, len);
	// } while(next_perm_dictionary_non_recursive(flag, len));

	// int r = 4;
	// do {
	// 	print(a, flag, r);
	// } while(next_perm_overlab_dictionary_non_recursive(flag, len, r));

	// int r = 2;
	// do {
	// 	print(a, flag, r);
	// } while(next_comb_non_recursive(flag, len, r));

	// int r = 2;
	// do {
	// 	print(a, flag, r);
	// } while(next_comb_overlab_non_recursive(flag, len, r));

	return 0;
}