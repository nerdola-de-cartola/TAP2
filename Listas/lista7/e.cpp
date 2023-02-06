#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 3000003

vector<ll> cubesFree;
bitset<N> isCubeFree;

void sieveOfCubes() {

   ll i, j, cube;

   isCubeFree.set();

   for(i = 2, cube = 8; cube < N; i++) {

      cube = i*i*i;

      if(isCubeFree[i]) {

         for(j = i*i*i; j < N; j += cube)
            isCubeFree[j] = 0; 

      }

   }

   for(i = 0; i < N; i++) {

      if(isCubeFree[i])
         cubesFree.push_back(i);

   }

}

int main(void) {

   ll t, n, i;

   cin >> t;

   sieveOfCubes();

   while(t--) {

      cin >> n;

      if(!isCubeFree[n]) {
         cout << "Not Cube Free\n";
         continue;
      }

      for(i = n; i >= 0; i--) {
         if(cubesFree[i] == n) {
            cout << i << '\n';
            break;
         }
      }

   }

   return 0;
}