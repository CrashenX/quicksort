#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define BUF_COUNT 32768
#define BUF_SLICE (BUF_COUNT * sizeof(unsigned int))

unsigned int naive_random(int min, int max)
{
    unsigned long range = max - min + 1;
    return min + (unsigned int)(range*rand()/(RAND_MAX + 1.0));
}

void swap(unsigned int* a, unsigned int* b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned int partition(unsigned int* A, int left, int right)
{
    unsigned int p = naive_random(left, right);
    unsigned int store = left;
    swap(A+p, A+right);
    for(int i = left; i < right; ++i) {
        if(A[i] <= A[right]) {
            swap(A+i, A+store);
            ++store;
        }
    }
    swap(A+store, A+right);
    return store;
}

void quicksort(unsigned int* A, int left, int right)
{
    if(left < right) {
        unsigned int pi = partition(A, left, right);
        quicksort(A, left, pi - 1);
        quicksort(A, pi + 1, right);
    }
}

int main()
{
    srand((unsigned int)time(0));
    unsigned int  max_buf   = BUF_COUNT;
    unsigned int  size      = BUF_SLICE;
    unsigned int* buffer    = malloc(size);
    unsigned int  count     = 0;
    unsigned int  input     = 0;

    srand(1337);

    while(4 == read(0, &input, 4)) {
        buffer[count] = input;
        ++count;
        if(count == max_buf) {
            size += BUF_SLICE;
            max_buf += BUF_COUNT;
            buffer = realloc(buffer, size);
        }
    }

    quicksort(buffer, 0, count-1);

    for(unsigned int i = 0; i < count; ++i) {
        ;
        //printf("%u\n", buffer[i]);
    }

    free(buffer);

    return 0;
}
