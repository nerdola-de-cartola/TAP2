#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int tests;

   cin >> tests;

   while(tests--) {
      map<int, int> freq;
      bool found = false;
      int n;
      
      cin >> n;

      for(int i = 0; i < n; i++) {
         int input;

         cin >> input;

         if(!found) {
            freq[input]++;
            if(freq[input] >= 3) {
               cout << input << endl;
               found = true;
            }
         }
      }

      if(!found) {
         cout << -1 << endl;
      }
   }

   return 0;
}