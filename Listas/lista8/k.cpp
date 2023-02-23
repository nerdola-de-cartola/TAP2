#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll absolute(ll x) {
   if(x < 0) return -x;
   return x;
}

int main(void) {

   ll n;

   cin >> n;

   ll matrix[n][n];
   ll i, j;

   for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++) {
         cin >> matrix[i][j];
      }
   }

   ll main = 0, secondary = 0;

   for(i = 0, j = 0; i < n; i++, j++) {
      main += matrix[i][j];
   }
   
   for(i = 0, j = n-1; i < n; i++, j--) {
      secondary += matrix[i][j];
   }

   // cout << main << '\n' << secondary << '\n';

   cout << absolute(main - secondary) << '\n';

   return 0;
}