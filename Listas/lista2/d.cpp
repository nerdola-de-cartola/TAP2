#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
   vector<unsigned int> students;
   vector<unsigned int> teams;
   unsigned int students_number, max_team;
   unsigned int i, j;

   cin >> students_number;
   students.reserve(students_number);

   for(i = 0; i < students_number; i++) {
      int programming_skill;

      cin >> programming_skill;
      students.push_back(programming_skill);
   }

   sort(students.begin(), students.end());

   i = 0;
   j = 0;
   while(j < students_number) {
      if(students[j] - students[i] <= 5) {
         teams.push_back(j - i + 1);
         j++;
      } else {
         i++;
      }
   }

   max_team = 0;
   for(i = 0; i < teams.size(); i++) {
      if(teams[i] > max_team) max_team = teams[i];
   }

   cout << max_team << endl;

   return 0;
}
