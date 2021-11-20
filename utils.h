#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef TINY_UTILS_UNICODE
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#endif // TINY_UTILS_UNICODE

char *utils_strin();
int utils_variance(int arr[], int n);
int utils_frequent(int arr[], int n);
bool *utils_sieve_prime(uint64_t n);
bool utils_is_prime(uint64_t n);

#define utils_bit_is_set(x, n) (x & (1 << n))
#define utils_bit_set(x, n) (x | (1 << n))
#define utils_bit_reset(x, n) (x & (~(1 << n)))
#define utils_bit_toggle(x, n) (x ^ (1 << n))

#ifdef TINY_UTILS_UNICODE
wchar_t *utils_wstrin();
#endif //TINY_UTILS_UNICODE

#endif // UTILS_H_INCLUDED

#ifdef TINY_UTILS_IMPLEMENTATION

// Macros for bit hacks


char *utils_strin()
{
    size_t i = 0, n = 0;
    int ch = 0;
    char *str_buffer = calloc(sizeof(char), '\0');

    do
    {
        ch = getchar();
        if (i == n)
        {
            n += 16;
            if ((str_buffer = realloc(str_buffer, sizeof(char) * n)) == NULL)
            {
                fprintf(stderr, "Realloc failed\n");
                abort();
            }
        }
        str_buffer[i++] = ch;
    } while (ch != '\n' && ch != EOF);
    str_buffer[i - 1] = '\0';
    return str_buffer;
}

#ifdef TINY_UTILS_UNICODE
wchar_t *utils_wstrin()
{
    _setmode(_fileno(stdin), _O_U16TEXT);

    size_t i = 0, n = 0;
    wint_t ch = 0;

    wchar_t *str_buffer = calloc(sizeof(wchar_t), '\0');

    do
    {
        ch = getwchar();
        if (i == n)
        {
            n += 16;
            if ((str_buffer = realloc(str_buffer, sizeof(wchar_t) * n)) == NULL)
            {
                fprintf(stderr, "Realloc failed\n");
                abort();
            }
        }
        str_buffer[i++] = ch;
    } while (ch != '\0' && ch != L'\n');
    str_buffer[i - 1] = '\0';

    return str_buffer;
}
#endif //TINY_UTILS_UNICODE

int utils_variance(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    double mean = (double)sum / n;
    double square_mean = 0;

    for (int i = 0; i < n; i++)
    {
        square_mean += (arr[i] - mean) * (arr[i] - mean);
    }

    return square_mean / (n - 1);
}

// compare function for qsort
static int utils_compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int utils_frequent(int arr[], int n)
{
    qsort(arr, n, sizeof(int), utils_compare);

    int count = 1, popular = arr[0], temp_count = 1, i = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            temp_count++;
        }
        else
        {
            if (temp_count > count)
            {
                count = temp_count;
                popular = arr[i - 1];
            }
            temp_count = 1;
        }
    }

    // If last element is most frequent
    if (temp_count > count)
    {
        count = temp_count;
        popular = arr[n - 1];
    }

    return popular;
}

bool *utils_sieve_prime(uint64_t n)
{
    bool *is_prime = malloc(sizeof(bool) * n);

    is_prime[0] = false;
    is_prime[1] = false;

    for (uint64_t i = 2; i < n; i++)
    {
        is_prime[i] = true;
    }

    for (uint64_t i = 2; i < n; i++)
    {
        if (is_prime[i])
        {
            for (uint64_t j = 2 * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

bool utils_is_prime(uint64_t n)
{
    if (n < 2)
        return false;

    int i = 2;

    while (i * i < n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }

    return true;
}

#endif // TINY_UTILS_IMPLEMENTATION
