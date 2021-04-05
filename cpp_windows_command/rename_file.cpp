#include <stdio.h>
#include <windows.h>

int main(void)
{
	const char* s_path = "";	// 출발 경로 지정
	const char* d_path = "";	// 도착 경로 지정
	
	for(int i=1; i<=100; i++) {
		char s_file_name[1024] = {0, };
		sprintf(s_file_name, "task%d_myself.txt", i);

		char d_file_name[1024] = {0, };
		sprintf(d_file_name, "task%03d_myself.txt", i);

		char command[1024] = {0, };
		sprintf(command, "rename %s%s %s", s_path, s_file_name, d_file_name);

		system(command);

		printf("%s\n", command);
	}
	return 0;
}