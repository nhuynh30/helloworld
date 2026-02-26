#include <stdio.h>

int main()
{
    char buffer[69];
    int seed;

    printf("Enter an integer seed\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &seed);
    srand(seed);
    return 0;
}
