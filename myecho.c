#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned int input = 0;
    while(4 == read(0, &input, 4)) {
        printf("%u\n", input);
    }
    return 0;
}
