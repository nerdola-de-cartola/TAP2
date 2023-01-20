#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 1000002LL
#define SQRTN 1000LL

ll ALL_PRIMES[N];
bool IMPOSSIBLE_PRIMES[N] = {true};

ll countAlmostPrime(ll n, ll k, ll *primes) {
   int i = 0;
   ll qtd = n;
   ll qtd_primes = 0;

   while(true) {

      if(ALL_PRIMES[i] < n)
         qtd_primes++;
      else 
         break;

      i++;
   }

   for(i = 0; i < k; i++) {
      qtd -= (ll) round( (double) qtd / (double) primes[i]);
   }

   return qtd - qtd_primes;

}

void erastoteles() {
   ll i, j;

   for(i = 2; i < SQRTN; i++) {

      if(IMPOSSIBLE_PRIMES[i]) continue;

      for(j = i + i; j < N; j += i) {
         IMPOSSIBLE_PRIMES[j] = true;
      }
   }

   j = 0;
   for(i = 2; i < N; i++) {
      if(!IMPOSSIBLE_PRIMES[i]) {
         ALL_PRIMES[j] = i;
         //cout << i << '\n';
         j++;
      } 
   }
}

int main(void) {

   ll t, test_case;
   // cin >> t;
   t = 1;

   erastoteles();

   for(test_case = 1; test_case <= t; test_case++) {

      ll n, k;

      cin >> n >> k;

      ll primes[k];

         for(int i = 0; i < k; i++)
            cin >> primes[i];

      cout << "Case " << test_case << ": " << countAlmostPrime(n, k, primes) << '\n';

   }

   return 0;
}