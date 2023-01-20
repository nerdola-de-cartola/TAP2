#include <bits/stdc++.h>

using namespace std;

#define M 1000000007ULL
#define N 4004000ULL

typedef unsigned long long ull;
typedef long long ll;

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

ll parenteses(string str) {
   ll height = 0;

   for(char letter : str) {

      if(letter == '(')
         height++;
      else if(letter == ')')
         height--;

      if(height < 0)
         return -1;

   }

   return height;
}

ull convolutionCatalan(ull n, ull k) {

   ull m;
   m = (2 * n) + k;

   ull r = comb(m, n) % M;
   r = (r * (k + 1)) % M;
   r = (r * inv(n + k + 1)) % M;

   return r;
}

int main(void) {

   calcFat();

   ull n;
   string str;

   cin >> n >> str;
   ll k = parenteses(str);   

   if(n&1 || k < 0) {
      cout << 0 << '\n';
      return 0;
   }

   ull pairs_number = n - str.size() + k;

   if(pairs_number&1) {
      cout << 0 << '\n';
      return 0;
   }

   pairs_number /= 2;

   if((ull) k > pairs_number) {
      cout << 0 << '\n';
      return 0;
   }

   cout << convolutionCatalan(pairs_number - k, k) << '\n';

   return 0;
}