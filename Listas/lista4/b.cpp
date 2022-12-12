#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int tests;

   cin >> tests;

   for(int test = 1; test <= tests; test++) {
      vector<string> A, B;
      set<string> C;
      string input;
      int size_A, size_B;

      cin >> size_A >> size_B;
      cin.ignore();

      A.reserve(size_A);
      B.reserve(size_B);

      for(int i = 0; i < size_A; i++) {
         getline(cin, input);
         A.push_back(input);
      }

      for(int i = 0; i < size_B; i++) {
         getline(cin, input);
         B.push_back(input);
      }

      for(int i = 0; i < size_A; i++) {
         for(int j = 0; j < size_B; j++) {
            C.insert(A[i] + B[j]);
            // cout << A[i] + B[j] << endl;
         }
      }

      cout << "Case " << test << ": " << C.size() << endl;  
   }

   return 0;
}