#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {

   return a * (b / __gcd(a, b));

}

int main(void) {

   ll t, a, b, L, G;
   bool found;

   cin >> t;

   while(t--) {

      cin >> a >> b;

      G =__gcd(a, b);
      L = lcm(a, b);

      found = false;
      // cout << G << ' ' << L << '\n';

      ll i, j;

      for(i = 1; i <= b; i++) {
         for(j = 1; j <= b; j++) {

            if(__gcd(i, j) == a && lcm(i, j) == b) {
               cout << i << ' ' << j << '\n';
               found = true;
               break;
            }
         }

         if(found) break;
      }

      if(!found) cout << "-1\n";

   }

   return 0;
}