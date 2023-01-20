#include <bits/stdc++.h>

using namespace std;

#define M 1000000007ULL
#define N 1001000ULL

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

ull solution(string str) {
   map<char, ull> alphabet;
   ull total = 0;

   total = fat[str.size()];

   for(char letter : str) alphabet[letter]++;

   for(char letter = 'a'; letter <= 'z'; letter++)
      if(alphabet[letter])
         total = (total * ifat[alphabet[letter]]) % M;

   return total;
}

int main(void) {
   string str;

   calcFat();

   cin >> str;

   cout << solution(str) << '\n';

}