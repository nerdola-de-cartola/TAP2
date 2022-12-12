#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

vector<string> alphabet;

void alphabetInit() {
   string str = "";
   string old_str = "";

   for(ui i = 0; ;i++) {
      for(ui j = 0; ; j++) {
         str = alphabet[i-1];

         for(char letter = 'a'; letter <= 'z'; letter++) {
            str[j-1] = letter;
            alphabet.push_back(str);
         }
      }
   }
   
}

bool checkWord(const string &str) {
   for(ui i = 1; i < str.size(); i++) {
      if(str[i] <= str[i-1]) return false;
   }

   return true;
}

int getIndex(const string &str) {
   if(!checkWord(str)) return 0;

   return 1;
}

int main(void) {
   string str;

   alphabetInit();

   while(true) {
      if(cin.eof()) break;
      cin >> str;

      cout << getIndex(str) << endl;
   }

   return 0;
}