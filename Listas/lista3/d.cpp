#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull maiorPotencia(ull x);

int main(void) {
   ull x;
   ull mp;

   cin >> x;

   int i = 0;
   while(x > 0) {
      mp = maiorPotencia(x);
      x -= mp;
      i++;
   }

   // cout << endl;
   cout << i << endl;
}

ull maiorPotencia(ull x) {
   ull p = 1;

   while(p <= x) {
      p = p << 1;
   }

   p = p >> 1;

   // cout << p << endl;

   return p;
}