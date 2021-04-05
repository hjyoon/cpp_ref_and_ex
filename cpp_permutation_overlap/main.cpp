#include <stdio.h>
#include <string.h>

void print(char* data, int* flag, int n) {
   for (int i=0; i<n; i++) {
      printf("%c", data[flag[i]]);
   }
   printf("\n");
}

void perm(char* data, int* flag, int depth, int n) {
   if (depth == n) {
      print(data, flag, n);
      return;
   }
   for (int i=0; i<n; i++) {
      flag[depth] = i;
      perm(data, flag, depth+1, n);
   }
}

int main() {
   char a[] = "ABCD";
   int len = strlen(a);

   // init flag
   int flag[len] = {0, };
   
   perm(a, flag, 0, len);

   return 0;
}

