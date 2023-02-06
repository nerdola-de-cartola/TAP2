#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 3000003

vector<ll> primes;
bitset<N> isPrime;

void sieveOfEratosthenes() {

   ll i, j;

   isPrime.set();

   for(i = 4; i < N; i += 2)
      isPrime[i] = 0;

   for(i = 3; (i*i) < N; i += 2) {

      if(isPrime[i]) {

         for(j = i + i; j < N; j += i)
            isPrime[j] = 0; 

      }

   }

   primes.push_back(2);
   for(i = 3, j = 1; i < N; i += 2) {
      if(isPrime[i]) {
         primes.push_back(i);
         j++;
      }
   }

}

void findDivisors(ll x) {

   ll i = 0;
   ll p = -1, q = -1;

   while(primes[i] <= x) {

      ll expoente = 0;

      while(x % primes[i] == 0) {
         x /= primes[i];
         expoente++;
      }

      if(expoente == 1) 
         q = primes[i];

      if(expoente == 2)
         p = primes[i];

      if(p != -1 && q != -1) {
         cout << p << ' ' << q << '\n';
         break;
      }

      i++;
   }


}

int main(void) {

   ll t;
   cin >> t;

   sieveOfEratosthenes();

   while(t--) {

      ll n;
      cin >> n;

      findDivisors(n);

   }

   return 0;

}