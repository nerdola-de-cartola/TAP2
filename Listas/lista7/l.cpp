#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 10000000

struct Factor {
   ll x;
   ll k;
};

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

ll sumDivisors(vector<Factor> *factors) {

   ll counter = 1;
   ll num, den;
   ll i = 0;

   for(i = 0; i < (ll) factors->size(); i++) {

      num = pow(factors->at(i).x, factors->at(i).k + 1) - 1;
      den = factors->at(i).x - 1;

      counter  *= num / den;

   }
   
   return counter;
}

vector<Factor> *primeFactors(ll n) {

   auto f = new vector<Factor>;
   ll i = 0, exp;
   Factor tmp;

   while(primes[i] * primes[i] <= n) {

      exp = 0;

      while(n % primes[i] == 0) {
         exp++;
         n /= primes[i];
      }

      if(exp > 0) {
         tmp.x = primes[i];
         tmp.k = exp;
         f->push_back(tmp);
      }

      i++;     
   }

   if(n != 1) {
      tmp.x = n;
      tmp.k = 1;
      f->push_back(tmp);
   }

   return f;

}

ll recursiveGCD(vector<Factor> *f) {

   ll i, a;
   ll gcd = pow(f->at(0).x, f->at(0).k);

   for(i = 1; i < (ll) f->size(); i++) {
      a = pow(f->at(i).x, f->at(i).k);
      gcd = __gcd(gcd, a);
   }

   return gcd;
}

int main(void) {

   ll n, p;

   cin >> n >> p;

   auto f = primeFactors(p);

   ll gcd = recursiveGCD(f);

   cout << gcd << '\n';
 
   return 0;

}