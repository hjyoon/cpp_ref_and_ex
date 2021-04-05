#include <stdio.h>
#include <string.h>

void bitPrint(void* _ptr, unsigned int size)
{
	int i=0, j=0;
	unsigned char* ptr = (unsigned char*)_ptr;

	for(i=1; i<=size; i++) {
		for(j=7; j>=0; j--) {
			printf("%d", (*(ptr-i+size) >> j) & 0x01);
		}
		printf(" ");
	}
	printf("\n");
}

int main(void)
{
	double d0 = 1.0;
	double d1 = 1.5;
	double d2 = 1.25;
	double d3 = 2.0;
	double d4 = 2.5;
	double d5 = 2.25;
	double d6 = 4.0;
	double d7 = 4.5;
	double d8 = 4.25;
	double d9 = 8.0;
	//int i = -1;
	//long long dd = 100;
	//char c = 127;
	//short s = -1;

	double d = 0.0;
	for(int i=0; i<100; i++) {
		bitPrint(&d, sizeof(double));
		d += 1.0;
	}

	// bitPrint(&d0, sizeof(double));
	// bitPrint(&d1, sizeof(double));
	// bitPrint(&d2, sizeof(double));
	// bitPrint(&d3, sizeof(double));
	// bitPrint(&d4, sizeof(double));
	// bitPrint(&d5, sizeof(double));
	// bitPrint(&d6, sizeof(double));
	// bitPrint(&d7, sizeof(double));
	// bitPrint(&d8, sizeof(double));
	// bitPrint(&d9, sizeof(double));
	//bitPrint(&i, sizeof(int));
	//bitPrint(&dd, sizeof(long long));
	//bitPrint(&c, sizeof(char));
	//bitPrint(&s, sizeof(short));


	return 0;
}