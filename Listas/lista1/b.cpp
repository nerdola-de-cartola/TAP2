#include <iostream>
#include <cstring>

using namespace std;

string cleanString(const string &str);
int countUnique(const string &str);
bool charInString(const string &str, char letter);

int main(void) {
   string str;

   cin.ignore();
   getline(cin, str);

   str = cleanString(str);

   // cout << str << endl;

   int n = countUnique(str);

   cout << n << endl;

   return 0;
}

string cleanString(const string &str) {
   string new_str = "";

   for(char letter : str) {
      if(letter == ' ' || letter == '{' || letter == '}' || letter == ',') continue;
      new_str += letter;
   }

   return new_str;
}

int countUnique(const string &str) {
   string unique_letters = "";

   for(char letter : str) {
      if(!charInString(unique_letters, letter)) {
         unique_letters += letter;
      }
   }

   // cout << unique_letters;

   return unique_letters.size();
}

bool charInString(const string &str, char letter) {
   for(char current_letter : str) {
      if(current_letter == letter) return true;
   }

   return false;
}