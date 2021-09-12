# tiny-c-utils
Utils for C

`char* utils_strin()`   
Reads input without skipping space and stops if `EOF` or `\n` are passed, grows the buffer in 16 char chunks if needed, return a pointer to memory in heap, free after using it.   

`int utils_variance(int arr[], int n)`    
Returns variance of an int array.    

`int utils_frequent(int arr[], int n)`    
Returns most frequent item in an array.   