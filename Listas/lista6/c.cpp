#include <bits/stdc++.h>

using namespace std;

#define M 1000000007ULL
#define N 2002000ULL

typedef unsigned long long ull;

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

void calcFat() {
   fat[0] = ifat[0] = 1;

   for(ull i = 1; i < N; i++) {

      fat[i] = (fat[i-1] * i) % M;

      ifat[i] = inv(fat[i]);
   }
}

ull comb(ull n, ull k) {
   
   ull r = (fat[n] * ifat[k]) % M;
   r = (r * ifat[n-k]) % M;

   return r;
}



int main(void) {

   calcFat();

   ull n, m;
   cin >> n >> m;

   cout << comb(n + m - 1, m) << '\n';

   return 0;
}