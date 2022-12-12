#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int n;

   while(true) {
      
      cin >> n;
      if(n == 0) break;

      vector<set<int>> students;
      int input;

      for(int i = 0; i < n; i++) {
         set<int> input_set;

         for(int j = 0; j < 5; j++) {
            cin >> input;
            input_set.insert(input);
         }

         students.push_back(input_set);
      }

      for(int i = 0; i < n; i++) {
         for(auto it = students[i].begin(); it != students[i].end(); it++) {
            for(int k = 0; k < n; k++) {
               if()
            }
         }
      


   }

   return 0;
}