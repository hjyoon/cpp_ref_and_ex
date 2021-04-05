#include <iostream>
#include <cstring>

using namespace std;

int main() {
	const char* base = "C:\\Users\\hjyoon\\NaverCloud\\google_trans\\resources\\article\\";
	for(int i=1; i<=100; i++) {
		char s_file_name[1024] = {0, };
		sprintf(s_file_name, "data_%d\\myself_%d.txt", i, i);

		char d_file_name[1024] = {0, };
		sprintf(d_file_name, "data_%d\\myself.txt", i);

		char s_path[1024] = {0, };
		sprintf(s_path, "%s%s", base, s_file_name);

		char d_path[1024] = {0, };
		sprintf(d_path, "%s%s", base, d_file_name);

		printf("%s\n", s_path);

		FILE* fp_r = fopen(s_path, "r");
		FILE* fp_w = fopen(d_path, "w");

		if(fp_r == NULL) {
			printf("fp_r 파일 열기 실패\n");
			return 1;
		}
		if(fp_w == NULL) {
			printf("fp_w 파일 열기 실패\n");
			return 2;
		}

		while(!feof(fp_r)) {
			char buf[1024] = {0, };
			fgets(buf, 1024, fp_r);

			char* line_p = strchr(buf, '\n');

			if(buf[0] == '\n') {
				*line_p = '\0';
				line_p = NULL;
			}

			if(line_p != NULL) {
				*line_p = ' ';
				*(line_p+1) = '\0';
			}

			fprintf(fp_w, "%s", buf);
		}

		fclose(fp_r);
		fclose(fp_w);
	}
	return 0;
}