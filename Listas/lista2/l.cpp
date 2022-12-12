#include <bits/stdc++.h>

using namespace std;

int main(void) {
   vector<string> words;
   unsigned int words_number, words_length;
   unsigned int i, j;

   cin >> words_number;
   cin >> words_length;

   words.reserve(26 * words_number);

   for(i = 0; i < words_number; i++) {
      string input;
      cin >> input;

      int ast_pos;
      for(j = 0; j < input.size(); j++) {
         if(input[j] == '*') {
            ast_pos = j;
            break;
         }
      }

      for(char letter = 'a'; letter <= 'z'; letter++) {
         input[ast_pos] = letter;
         words.push_back(input);
      }
   }

   sort(words.begin(), words.end());

   int max_count = 0;
   int index_ans;

   for(i = 0; i < words.size(); i = j) {

      j = i+1;
      int count = 1;

      while(words[i] == words[j] && j < words.size()) {
         count++;
         j++;
      }

      if(count > max_count) {
         max_count = count;
         index_ans = i;
      }
   }

   cout << words[index_ans] << ' ' << max_count << endl;

   return 0;
}

