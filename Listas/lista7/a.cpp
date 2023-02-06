#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1000001

ll primes[N];
bitset<N> isPrime;

void sieveOfEratosthenes() {

   int i, j;

   isPrime.set();

   for(i = 4; i < N; i += 2)
      isPrime[i] = 0;

   for(i = 3; (i*i) < N; i += 2) {

      if(isPrime[i]) {

         for(j = i + i; j < N; j += i)
            isPrime[j] = 0; 

      }

   }

   primes[0] = 2;
   for(i = 3, j = 1; i < N; i += 2) {
      if(isPrime[i]) {
         primes[j] = i;
         j++;
      }
   }

}

ll countDivisors(ll x) {

   ll counter = 1;
   ll i = 0;

   while((primes[i] * primes[i]) <= x) {

      ll expoente = 0;

      while(x % primes[i] == 0) {
         x /= primes[i];
         expoente++;
      }

      counter *= expoente + 1; 
      i++;
   }

   return x == 1 ? counter : 2 * counter;

}

int main(void) {

   ll t;
   cin >> t;

   sieveOfEratosthenes();

   while(t--) {

      ll x;
      cin >> x;

      cout << countDivisors(x) << '\n';

   }

   return 0;
}