#include <bits/stdc++.h>

using namespace std;

int main(void) {

   int tests;
   cin >> tests;

   while(tests--) {
      int n;
      char input;
      cin >> n;

      for(int i = 0; i < n; i++) {
         cin >> input;
      }

      cout << 3 * (10-n) * (10 - n - 1) << endl;
   }

   return 0;
}