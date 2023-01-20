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

ull chaoticPermutations(ull n) {
   ull chaotic[n+1];

   chaotic[1] = 0;
   chaotic[2] = 1;

   for(ull i = 3; i <= n; i++) 
      chaotic[i] = ((i-1) * (chaotic[i-1] + chaotic[i-2])) % M;

   return chaotic[n];
}


int main(void) {

   calcFat();

   ull n;
   cin >> n;

   if(n&1) {
      cout << 0 << '\n';
      return 0;
   }
   
   n /= 2;

   ull r = (fat[2*n] * ifat[n+1]) % M;
   r = (r * ifat[n]) % M;

   cout << r << '\n';

   return 0;
}