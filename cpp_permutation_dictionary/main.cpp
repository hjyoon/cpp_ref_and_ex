#include <stdio.h>
#include <string.h>

void print(char* data, int* flag, int n) {
   for (int i=0; i<n; i++) {
      printf("%c", data[flag[i]]);
   }
   printf("\n");
}

void right_rotate(int* flag, int start, int end) {
   int last = flag[end];
   for(int i=end; i>start; i--) {
      flag[i] = flag[i-1];
   }
   flag[start] = last;
}

void left_rotate(int* flag, int start, int end) {
   int first = flag[start];
   for(int i=start; i<end; i++) {
      flag[i] = flag[i+1];
   }
   flag[end] = first;
}

void perm_dict(char* data, int* flag, int depth, int n) {
   if (depth == n) {
      print(data, flag, n);
      return;
   }
   for (int i=depth; i<n; i++) {
      right_rotate(flag, depth, i);
      perm_dict(data, flag, depth+1, n);
      left_rotate(flag, depth, i);
   }
}

int main() {
   char a[] = "ABCD";
   int len = strlen(a);

   // init flag
   int flag[len] = {0, };
   for(int i=0; i<len; i++) {
      flag[i] = i;
   }
   
   perm_dict(a, flag, 0, len);

   return 0;
}

