#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int tests;

   cin >> tests;

   for(int test = 1; test <= tests; test++) {
      vector<vector<int>> stamps;
      map<int, int> unique_stamps;
      unsigned int kids_number;
      unsigned int total_unique;
      unsigned int i, j;

      cin >> kids_number;

      for(i = 0; i < kids_number; i++) {
         map<int, bool> marked_stamps;
         unsigned int stamps_number;

         cin >> stamps_number;

         vector<int> v_input;
         v_input.reserve(stamps_number);

         for(j = 0; j < stamps_number; j++) {
            int i_input;
            cin >> i_input;

            v_input.push_back(i_input);

            if(!marked_stamps[i_input]) {
               unique_stamps[i_input]++;
               marked_stamps[i_input] = true;
            }
         }

         stamps.push_back(v_input);
         v_input.clear();
      }

      total_unique = 0;

      for(i = 0; i < stamps.size(); i++) {
         map<int, bool> marked_stamps;

         for(j = 0; j < stamps[i].size(); j++) {

            if(!marked_stamps[stamps[i][j]]) {
               
               if(unique_stamps[stamps[i][j]] == 1) {
                  total_unique++;
                  marked_stamps[stamps[i][j]] = true;
               }
            }
         }
      }

      cout << "Case " << test << ": ";

      cout << fixed << setprecision(6);
      for(i = 0; i < stamps.size(); i++) {
         map<int, bool> marked_stamps;
         int unique = 0;

         for(j = 0; j < stamps[i].size(); j++) {

            if(!marked_stamps[stamps[i][j]]) {
               if(unique_stamps[stamps[i][j]] == 1) {
                  unique++;
                  marked_stamps[stamps[i][j]] = true;
               }
            }

         }

         cout << (double) unique / (double) total_unique * 100.0 << '%';

         if(i != stamps.size() - 1)
            cout << ' ';
      }

      cout << endl;
   }

   return 0;
}