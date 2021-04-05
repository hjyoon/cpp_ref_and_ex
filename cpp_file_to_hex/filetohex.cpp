#include <stdio.h>

int main(void)
{
	FILE* in = NULL;

	in = fopen("input.txt", "rb");
	if(in == NULL) {
		printf("fopen() is error\n");
		return 0;
	}

	while(!feof(in)) {
		printf("%02x ", fgetc(in));
	}

	fclose(in);

	return 0;
}