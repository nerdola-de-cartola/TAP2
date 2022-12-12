#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int tests;

   cin >> tests;

   while(tests--) {
      map<int, int> freq_first, freq_second;
      map<int, bool> checked;
      vector<int>first, second;
      int size_first, size_second;

      cin >> size_first >> size_second;

      first.reserve(size_first);
      second.reserve(size_second);

      for(int i = 0; i < size_first; i++) {
         cin >> first[i];
         freq_first[first[i]]++;
      }

      for(int i = 0; i < size_second; i++) {
         cin >> second[i];
         freq_second[second[i]]++;
      }

      int dif = 0;

      for(int i = 0; i < size_first; i++) {
         if(checked[first[i]]) continue;

         dif += fabs(freq_first[first[i]] - freq_second[first[i]]);
         checked[first[i]] = true;
      }

      for(int i = 0; i < size_second; i++) {
         if(checked[second[i]]) continue;

         dif += fabs(freq_first[second[i]] - freq_second[second[i]]);
         checked[second[i]] = true;
      }

      cout << dif << endl;
   }

   return 0;
}