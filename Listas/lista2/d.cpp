#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int max_team(const vector<int> &arr, int start, int end);

int main(void) {
   vector<int> students;
   int students_number;
   int i;

   cin >> students_number;
   students.reserve(students_number);

   for(i = 0; i < students_number; i++) {
      int programming_skill;

      cin >> programming_skill;
      students.push_back(programming_skill);
   }

   sort(students.begin(), students.end());

   cout << max_team(students, 0, students_number - 1) << endl;

   return 0;
}

int max_team(const vector<int> &arr, int start, int end) {
   if(start == end) return 1;

   int team_dif = fabs(arr[start] - arr[end]);

   if(team_dif <= 5) {
      return (end - start + 1);
   }

   int walk_start = max_team(arr, start+1, end);
   int walk_end = max_team(arr, start, end-1);

   return walk_start >= walk_end ? walk_start : walk_end;
}