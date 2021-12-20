#include "prime.h"

using namespace std;

// Returns whether `n` is prime. Determined by trial division by integers.
bool is_prime(const uint64_t n) {
  if (n <= 3) {
    return n > 1;
  }

  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  const uint64_t sqrt_n = sqrt(n);
  // Divides by integers of the form 6k +- 1.
  for (uint64_t i = 5; i <= sqrt_n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

// Returns whether `n` is prime. Determined by trial division by `primes`.
bool is_prime(const uint64_t n, vector<uint64_t> const &primes) {
  if (n <= 3) {
    return n > 1;
  }

  const uint64_t sqrt_n = sqrt(n);
  for (uint64_t i = 0; primes[i] <= sqrt_n; ++i) {
    if (n % primes[i] == 0) {
      return false;
    }
  }

  return true;
}

// Returns a vector of prime numbers less than or equal to `n`. Generated by the
// sieve of Eratosthenes.
vector<uint64_t> generate_primes(const uint64_t n) {
  if (n <= 2) {
    return n <= 1 ? vector<uint64_t>{} : vector<uint64_t>{2};
  }

  vector<uint64_t> primes = {2, 3};
  vector<bool> primality(n + 1, true);

  const uint64_t sqrt_n = sqrt(n);
  uint64_t i;
  // Iterates over integers of the form 6k +- 1.
  for (i = 5; i <= sqrt_n; i += 4) {
    if (primality[i]) {
      for (uint64_t j = i * i; j <= n; j += i) {
        primality[j] = false;
      }

      primes.push_back(i);
    }

    i += 2;

    if (i > sqrt_n) {
      break;
    }

    if (primality[i]) {
      for (uint64_t j = i * i; j <= n; j += i) {
        primality[j] = false;
      }

      primes.push_back(i);
    }
  }

  for (; i <= n; i += 4) {
    if (primality[i]) {
      primes.push_back(i);
    }

    i += 2;

    if (i > n) {
      break;
    }

    if (primality[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

// Returns a vector of prime factors of `n`. Factored by trial division by
// integers.
vector<uint64_t> factor(uint64_t n) {
  if (n <= 3) {
    return n == 1 ? vector<uint64_t>{} : vector<uint64_t>{n};
  }

  vector<uint64_t> prime_factors;

  while (n % 2 == 0) {
    prime_factors.push_back(2);
    n /= 2;
  }

  while (n % 3 == 0) {
    prime_factors.push_back(3);
    n /= 3;
  }

  const uint64_t sqrt_n = sqrt(n);
  // Divides by integers of the form 6k +- 1.
  for (uint64_t i = 5; i <= sqrt_n; i += 4) {
    while (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }

    i += 2;

    while (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }
  }

  if (n != 1) {
    prime_factors.push_back(n);
  }

  return prime_factors;
}
