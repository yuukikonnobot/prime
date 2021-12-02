#include "prime.h"

using namespace std;

// Returns whether `n` is prime. Determined by trial division by integers.
bool is_prime(const ull n) {
  if (n < 2) {
    return false;
  }

  if (n == 2) {
    return true;
  }

  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  const ull sqrt_n = sqrt(n);

  // Starting from 5, divides only by integers of the form 6k +/- 1 (i.e. that
  // are not multiples of 2 or 3).
  for (ull i = 5; i <= sqrt_n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

// Returns whether `n` is prime. Determined by trial division by `primes`.
bool is_prime(const ull n, vector<ull> const &primes) {
  if (n < 2) {
    return false;
  }

  const ull sqrt_n = sqrt(n);

  for (ull i = 0; primes[i] <= sqrt_n; i++) {
    if (n % primes[i] == 0) {
      return false;
    }
  }

  return true;
}

// Returns a vector of primes less than or equal to `x`.
vector<ull> get_primes(const ull x) {
  if (x < 2) {
    return {};
  }

  if (x == 2) {
    return {2};
  }

  vector<ull> primes = {2, 3};

  // Iterates only for integers of the form 6k +/- 1.
  for (ull n = 5; n <= x; n += 6) {
    if (is_prime(n, primes)) {
      primes.push_back(n);
    }

    if (n + 2 <= x && is_prime(n + 2, primes)) {
      primes.push_back(n + 2);
    }
  }

  return primes;
}

// Returns a vector of prime factors of `n`. Factored by trial division by
// integers.
vector<ull> factor(ull n) {
  // Here we define the factorization of 1 as {1} and that of 0 as {0} for no
  // reason.
  if (n <= 3) {
    return {n};
  }

  vector<ull> prime_factors;

  while (n % 2 == 0) {
    prime_factors.push_back(2);
    n /= 2;
  }

  while (n % 3 == 0) {
    prime_factors.push_back(3);
    n /= 3;
  }

  const ull sqrt_n = sqrt(n);

  // Divides by integers of the form 6k +/- 1.
  for (ull i = 5; i <= sqrt_n; i += 6) {
    while (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }

    while (n % (i + 2) == 0) {
      prime_factors.push_back(i + 2);
      n /= i + 2;
    }
  }

  if (n != 1) {
    prime_factors.push_back(n);
  }

  return prime_factors;
}
