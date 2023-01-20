#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define M 1000000007LL
#define N 1001000

ull fat[N], ifat[N];


ull inv(ull x) {

   ull r = 1;
   ull y = M - 2;

   while(y > 0) {

      if(y&1) 
         r = (r * x) % M;

      y = y >> 1;
      x = (x * x) % M;
   }

   return r;
}

ull bin(ull a, ull b) {

   ull r = (fat[a] * ifat[b]) % M;
   r = (r * ifat[a-b]) % M;

   return r;
}

void calcFat() {
   fat[0] = ifat[0] = 1;

   for(ull i = 1; i < N; i++) {

      fat[i] = (fat[i-1] * i) % M;

      ifat[i] = inv(fat[i]);
   }
}

int main(void) {

   calcFat();

   int tests;
   cin >> tests;

   while(tests--) {

      ull a, b;
      cin >> a >> b;

      cout << bin(a, b) << endl;

   }

   return 0;
}