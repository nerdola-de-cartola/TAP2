#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {

   ll max_gcd, current_gcd;
   ll number_with_max_gcd;
   ll n, i, j;

   cin >> n;

   ll numbers[n];
   

   for(i = 0; i < n; i++) {
      cin >> numbers[i];
   }

   max_gcd = 0;
   number_with_max_gcd = 0;
   for(i = 2; i <= 1000; i++) {

      current_gcd = 0;

      for(j = 0; j < n; j++) {

         if(numbers[j] % i == 0)
            current_gcd++;

      }

      if(current_gcd > max_gcd) {
         max_gcd = current_gcd;
         number_with_max_gcd = i;
      }

   }

   cout << number_with_max_gcd << '\n';

   return 0;
}