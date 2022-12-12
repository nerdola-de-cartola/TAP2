#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

void splitBits(ui n, ui &a, ui &b);

int main(void) {
   ui n, a, b;
   
   while(true) {
      cin >> n;
      
      if(n == 0) break;

      splitBits(n, a, b);

      cout << a << ' ' << b << endl; 
   }
   

   return 0;
}

void splitBits(ui n, ui &a, ui &b) {
   ui mask = 1;
   a = 0;
   b = 0;
   ui count = 1;

   for(ui i = 1; i <= 32; i++) {
      if(n & mask) {
         if(count & 1) { // count é ímpar
            a = a | mask;
         } else { // count é par
            b = b | mask;
         }

         count++;
      }

      mask = mask << 1;
   }
}