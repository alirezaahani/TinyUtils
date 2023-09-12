# Tiny Utils Library

A small C library that provides utility functions for common tasks.

## Introduction

The Tiny Utils Library is a collection of utility functions designed to simplify common tasks in C programming. This library includes functions for string input, calculating variance, finding the most frequent element in an array, generating prime numbers using the Sieve of Eratosthenes algorithm, and checking if a number is prime. Additionally, there are macros for bit manipulations.

## Functions

1. `char *utils_strin(void)`: Reads a string of characters from the standard input and returns a dynamically allocated string.

2. `int utils_variance(int arr[], int n)`: Calculates the variance of an integer array, given its length. Returns the variance as an integer.

3. `int utils_frequent(int arr[], int n)`: Finds the most frequent element in an integer array, given its length. Returns the value of the most frequent element.

4. `bool *utils_sieve_prime(uint64_t n)`: Generates an array of boolean values indicating whether each number up to `n` is prime or not, using the Sieve of Eratosthenes algorithm. Returns a dynamically allocated boolean array.

5. `bool utils_is_prime(uint64_t n)`: Checks if a given number `n` is prime. Returns `true` if `n` is prime, and `false` otherwise.

## Macros

The following macros are provided for bit manipulations:

- `bit_chk(x, n)`: Checks if the `n`th bit of `x` is set.

- `bit_set(x, n)`: Sets the `n`th bit of `x` to 1.

- `bit_res(x, n)`: Resets the `n`th bit of `x` to 0.

- `bit_xor(x, n)`: Flips the `n`th bit of `x` (0 to 1 or 1 to 0).

## Usage

To use the Tiny Utils Library in your C program, include the `utils.h` header file in your source code.

```c
#include "utils.h"
```

Define the following in one of your source file: 

```c
#define TINY_UTILS_IMPLEMENTATION
```

## Contributing

Contributions to the Tiny Utils Library are welcome! If you have any improvements or bug fixes, please submit a pull request.

## License

The Tiny Utils Library is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
