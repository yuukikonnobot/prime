// Prints primes less than 10 million.
#include "prime.h"
#include <iostream>

using namespace std;

int main() {
  for (auto p : get_primes(10000000)) {
    cout << p << endl;
  }
}
