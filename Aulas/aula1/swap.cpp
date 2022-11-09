#include <iostream>

void swap(int &a, int &b) {
   a = a+b;
   b = a-b;
   a = a-b;
}

int main(void) {
   int a = 2;
   int b = 5;

   swap(a, b);

   std::cout << a << " e " << b << std::endl;
}