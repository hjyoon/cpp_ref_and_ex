#include <stdio.h>
#include <windows.h>

int main(void)
{
	const char* s_path = "";	// 출발 경로 지정
	const char* d_path = "";	// 도착 경로 지정
	
	for(int i=1; i<=100; i++) {
		char s_file_name[1024] = {0, };
		sprintf(s_file_name, "translated_source_%d.txt", i);

		char d_folder_name[1024] = {0, };
		sprintf(d_folder_name, "data_%d", i);

		char command[1024] = {0, };
		sprintf(command, "move %s%s %s%s", s_path, s_file_name, d_path, d_folder_name);

		system(command);

		printf("%s\n", command);
	}
	return 0;
}