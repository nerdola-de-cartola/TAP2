#include <iostream>

using namespace std;

int countSequencies(string str, int n);

int main(void) {
   int n;
   cin >> n;

   string str;
   cin >> str;

   cout << countSequencies(str, n) << endl;
   
   return 0;
}

int countSequencies(string str, int n) {
   bool start_sequencie = false;
   bool first_sequencie = false;
   int a_qtd = 0;

   for(int i = 0; i < n; i++) {
      if(!start_sequencie) {
         if(str[i] == 'a') {
            start_sequencie = true;
            first_sequencie = true;
         }
      } else {
         if(str[i] == 'a') {
            if(first_sequencie) {
               a_qtd++;
               first_sequencie = false;
            }
            a_qtd++;
         } else {
            start_sequencie = false;
         }
      }
   }

   return a_qtd;
}