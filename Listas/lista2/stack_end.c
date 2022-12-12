#include <stdio.h>
#include <stdlib.h>

#define N 1000000000
// char arr[N];

int main(void) {
   char *arr = (char *) malloc(N * sizeof(char));

   unsigned long long int i;
   for(i = 0; i < N; i++) printf("%d\n", arr[i]);

   free(arr);

   return 0;
}