#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int timestamp = 0;
    int temp = 28;
    int battery = 100;
    int orient_err = 0;

    char buffer[69];
    int seed;

    printf("Enter an integer seed\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &seed);
    srand(seed);
    printf("random number test: %d\n", seed);
    printf("Random number is %d\n", rand());

    while (1)
    {
        char buffer2[67];
        char option;

        printf("Enter your option: L, R, T, or Q\n");
        fgets(buffer2, sizeof(buffer2), stdin);
        sscanf(buffer2, "%s", &option);
        option = toupper(option);

        if (option != 'L' && option != 'R' && option != 'T' && option != 'Q')
        {
            printf("You mess up the value somehomhow\n");
            continue;
        }
        break;
    }

    return 0;
}
