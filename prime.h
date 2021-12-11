#ifndef PRIME_H
#define PRIME_H

#include <cmath>
#include <vector>

using ull = unsigned long long;

bool is_prime(const ull);
bool is_prime(const ull, std::vector<ull> const &);
std::vector<ull> generate_primes(const ull);
std::vector<ull> factor(ull);

#endif // PRIME_H
