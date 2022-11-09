#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binSrc(const vector<T> &v, int start, int end, const T &target);

int main(void) {
   vector<long long int> dormitories;
   vector<long long int> letters;
   long long int number_dormitories, number_letters;
   long long int i;

   cin >> number_dormitories;
   cin >> number_letters;

   dormitories.reserve(number_dormitories);
   letters.reserve(number_letters);

   // Lê os quartos
   for(i = 0; i < number_dormitories; i++) {
      long long int number_rooms;
      cin >> number_rooms;

      if(i == 0) dormitories.push_back(number_rooms);
      else dormitories.push_back(number_rooms + dormitories[i-1]);
   }

   // Lê as cartas
   for(i = 0; i < number_letters; i++) {
      long long int number_rooms;
      cin >> number_rooms;
      letters.push_back(number_rooms);
   }

   // Encontra o quarto de cada carta
   for(i = 0; i < number_letters; i++) {
      int pos = binSrc(dormitories, 0, dormitories.size()-1, letters[i]);
      if(pos == 0) cout << pos+1 << ' ' << letters[i] << endl;
      else cout << pos+1 << ' ' << letters[i] - dormitories[pos-1] << endl;
   }

   return 0;
}

template <typename T>
int binSrc(const vector<T> &v, int start, int end, const T &target) {
    int mid;

    mid = (end + start)/2;

    if(v[mid] == target) return mid;
    else if(v[mid] > target) {
      if(mid == 0 || v[mid-1] < target) return mid;
    }

    if(v[mid] > target) {
        return binSrc(v, start, mid, target);
    } else {
        return binSrc(v, mid+1, end, target);
    }
}