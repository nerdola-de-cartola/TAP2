#include <iostream>
#include <vector>

using namespace std;

vector<int> points_arr;
int matrix[100][100];
int m, n, k;

int calcMaxPoints(int c) {
   points_arr.clear();
   int p1, p2;
   unsigned int i ;

   p1 = -1;   
   while(p1 < n) {
      for(p1++; p1 < n; p1++) {
         if(matrix[p1][c] == 1) break;
      }

      int points = 0;
      for(p2 = 0; p2 < k; p2++) {
         if(p1 + p2 >= n) break;
         points += matrix[p1 + p2][c];
      }

      points_arr.push_back(points);
   }

   int max_points = 0;
   for(i = 0; i < points_arr.size(); i++) {
      if(points_arr[i] > points_arr[max_points]) max_points = i;
   }

   return max_points;
}

int main(void) {
   int l, c;

   cin >> n >> m >> k;

   for(l = 0; l < n; l++) {
      for(c = 0; c < m; c++) {
         cin >> matrix[l][c];
      }
   }
   
   int total_points = 0;
   int total_moves = 0;
   for(c = 0; c < m; c++) {
      int i = calcMaxPoints(c);
      total_moves += i;
      total_points += points_arr[i];
   }

   cout << total_points << ' ' << total_moves << endl;

   return 0;
}