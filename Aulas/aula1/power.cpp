#include <iostream>

int pow(int x, int n);

int main(void) {
   int a, n;

   std::cin >> a;
   std::cin >> n;

   std::cout << pow(a, n) << std::endl;

   return 0;
}

int pow(int x, int n) {
   int p, k;

   for(p = 1, k = n; k > 0;) {
      if(k & 1) {
         p *= x;
         k--;
      } else {
         x *= x;
         k = k >> 1;
      }
   }

   return p;
}