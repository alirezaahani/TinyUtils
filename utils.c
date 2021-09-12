#include "stdio.h"
#include "stdlib.h"

char* utils_strin()
{
	size_t i = 0, n = 0;
	int ch = 0;

	char *str_buffer = calloc(sizeof(char), '\0');

	do
	{
	    ch = getchar();

		if(i == n)
		{
			n += 16;
			if((str_buffer = realloc(str_buffer, sizeof(char) * n)) == NULL)
			{
				fprintf(stderr, "Realloc failed\n");
				abort();
			}
		}

		str_buffer[i++] = ch;

	} while(ch != '\n' && ch != EOF);

	str_buffer[i - 1] = '\0';

	return str_buffer;
}

int utils_variance(int arr[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
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
int utils_compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int utils_frequent(int arr[], int n)
{
    qsort(arr,n, sizeof(int), utils_compare);

    int count = 1, popular = arr[0], temp_count = 1, i= 0;

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
