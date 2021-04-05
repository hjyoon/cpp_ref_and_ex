#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* pFile = NULL;
	pFile = fopen("csv_test.csv", "rt");
	if(pFile == NULL) {
		printf("pFile is NULL\n");
		return 0;
	}

	int line_num = 0;
	while(!feof(pFile)) {
		char buf[1024] = {0, };
		char* token = NULL;
		int tmp = 0;

		line_num++;

		fgets(buf, sizeof(buf), pFile);
		token = strtok(buf, ",\n");

		if(token) {
			if(line_num > 1) {
				printf("\n");
			}
			printf("%d: ", line_num);
			while(token) {
				printf("%s ", token);
				token = strtok(NULL, ",\n");
			}
		}
	}

	return 0;
}