#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1000001
#define M 1000000007

struct PrimeFactors {
   ll x;
   ll k;
};

ll primes[N];
bitset<N> isPrime;
PrimeFactors FACTORS[N];

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

ll exponential(ll b, ll e) {

   ll answer = 1;

   while (e > 0) {

      if (e&1)
         answer = (answer * b) % M;

      e = e >> 1;

      b = (b * b) % M;

   }

   return answer % M;

}

ll inv(ll x) {
   return exponential(x, M-2);
}

ll sumDivisors(ll n) {

   ll counter = 1;
   ll num, den;
   ll i = 0;

   for(i = 0; i < n; i++) {

      num = exponential(FACTORS[i].x, FACTORS[i].k + 1) - 1;
      den = inv(FACTORS[i].x - 1);

      counter  = (counter * (num * den) % M) % M;

   }
   
   return counter;
}

ll countDivisors(ll n) {

   ll i = 0;
   ll counter = 1;

   for(i = 0; i < n; i++) 
      counter = (counter * (FACTORS[i].k + 1)) % M ;

   return counter;
}

ll productDivisors(ll n) {

   ll e = countDivisors(n);
   e = (e * inv(2)) % (M - 1);

   ll b = 1;
   ll i = 0;

      for(i = 0; i < n; i++)
         b = (b * exponential(FACTORS[i].x, FACTORS[i].k)) % M;


   return exponential(b, e);
}

int main(void) {

   ll n;
   cin >> n;


   sieveOfEratosthenes();

   for(ll i = 0; i < n; i++) 
      cin >> FACTORS[i].x >> FACTORS[i].k;


   cout << countDivisors(n) << ' ';
   cout << sumDivisors(n) << ' ';
   cout << productDivisors(n) << '\n';

   return 0;
}