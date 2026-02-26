#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void run_tick(int *timestamp, int *temp, int *battery, int *orient_err);
void print_status(int *timestamp, int *temp, int *battery, int *orient_err);

int main()
{
    int timestamp = 0;
    int temp = 28;
    int battery = 100;
    int orient_err = 0;

    char buffer[69];
    int seed;

    print_status(&timestamp, &temp, &battery, &orient_err);

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

        switch (option)
        {
        case 'L':
            run_tick(&timestamp, &temp, &battery, &orient_err);
            print_status(&timestamp, &temp, &battery, &orient_err);
            break;
        case 'R':

            break;
        case 'T':

            break;

        case 'Q':
            exit(0);
            break;
        }
    }

    return 0;
}

void run_tick(int *timestamp, int *temp, int *battery, int *orient_err)
{
    (*timestamp)++;
    (*temp) += rand() % 10 - 5;
    (*battery) -= rand() % 3;
    (*orient_err) += rand() % 7;
    int rad_hits = rand() % 6;
    if (rad_hits == 5)
    {
        printf("You died");
    }
}

void print_status(int *timestamp, int *temp, int *battery, int *orient_err)
{
    printf("timestamp: %d\n", *timestamp);
    printf("temp is %d\n", *temp);
    printf("batter is %d\n", *battery);
    printf("orient_err is %d\n", *orient_err);
}
