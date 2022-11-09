#include <iostream>
#include <set>
#include <stack>

using namespace std;

int main(void) {
   int tests;
   cin >> tests;

   while(tests--) {
      int size;
      int i;
      stack<int> s;

      cin >> size;

      for(i = 0; i < size; i++) {
         int n;
         cin >> n;
         s.push(n);
      }

      set<int> unique;
      for(i = 0; i < size; i++) {
         int n;
         n = s.top();
         s.pop();
         auto ans = unique.insert(n);
         if(ans.second == false) break;
      }

      cout << size - i << endl;

   }


   return 0;
}