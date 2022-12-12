#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

int a(ulli x);
int b(ulli x);

int main(void) {
   ulli m, n;
   unsigned short int k;
   int tests, count;

   cin >> tests;

   while(tests--) {
      cin >> m >> n >> k;

      count = 0;

      for(ulli i = m; i <= n; i++) {
         if(fabs(a(i) - b(i)) == k) count++;
      }

      cout << count << endl;
   }

   return 0;
}

int a(ulli x) {
   ulli mask = 0x01;
   int count = 0;

     while(x != 0) {
      if(x & mask) count++;
      x = x >> 2;
   }

   // cout << "Contador de a(): " << count << endl;

   return count;
}

int b(ulli x) {
   ulli mask = 0x02;
   int count = 0;

   while(x != 0) {
      if(x & mask) count++;
      x = x >> 2;
   }

   // cout << "Contador de b(): " << count << endl;

   return count;
}
