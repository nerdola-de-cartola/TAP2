#include <bits/stdc++.h>

using namespace std;

struct Drug {
   int freq, priority;
   string name;
};

void readDrug(Drug &d) {
   cin >> d.name >> d.freq;
   d.priority = 0;
}

int main(void) {
   int tests;

   cin >> tests;

   while(tests--) {
      int n, k;
      vector<Drug> prescription;
      vector<Drug> take_time;
      Drug input;

      cin >> n >> k;

      for(int i = 0; i < n; i++) {
         readDrug(input);
         prescription.push_back(input);
      }

      for(int i = 1, count = 0; count < 53*k; i++) {
         for(int j = 0; j < n && count < 53*k; j++) {
            Drug tmp;

            tmp.priority = j;
            tmp.freq = i * prescription[j].freq;
            tmp.name = prescription[j].name;
            take_time.push_back(tmp);

            count++;
         }
      }

      sort(take_time.begin(), take_time.end(), [](Drug a, Drug b) {
         if(a.freq > b.freq) return false;
         else if(a.freq == b.freq) {
            if(a.priority > b.priority) return false;
         }

         return true;
      });

      for(int i = 0; i < k; i++) {
         cout << take_time[i].freq << ' ' << take_time[i].name << endl;
      }

   }

   return 0;
}
