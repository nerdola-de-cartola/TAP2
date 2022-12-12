#include <bits/stdc++.h>

using namespace std;

bool existIn(const string &sub_string, const string& super_string, char &missing_letter) {
   unsigned int i, j;

   for(i = 0, j = -1; i < sub_string.size(); i++) {

      for(j = j + 1; j < super_string.size(); j++) {
         if(sub_string[i] == super_string[j]) break;
      }

      if(j == super_string.size()) {
         missing_letter = sub_string[i];
         return false;
      }
   }

   return true;
}

int main(void) {
   string original, target;
   stack<unsigned int> index_to_remove;
   unsigned int i;

   cin >> original >> target;

   for(i = 0; i < original.size(); i++) {
      unsigned int input;
      cin >> input;

      index_to_remove.push(input - 1);
   }

   string test;
   test.reserve(original.size());

   for(i = 0; i < original.size(); i++) test += '*';

   unsigned int count = 0;
   unsigned int pos;
   char missing_letter;

   while(!index_to_remove.empty()) {
      if(existIn(target, test, missing_letter)) {
         cout << original.size() - count << endl;
         break;
      }

      do {
         pos = index_to_remove.top();
         test[pos] = original[pos];
         index_to_remove.pop();

         count++;
      } while(missing_letter != test[pos]);
      
   }

   return 0;
}