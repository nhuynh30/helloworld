// Nam Quan Huynh

#include <stdio.h>

char menu();
char getChar();
int getNum();
void drawLine(int n, char c);
void drawSquare(int n, char c);
void drawTri(int n, char c);
void drawRec(int n, char c);
int isValid(int n, char c);

int main()
{

    char c = ' ';
    int n = 0;
    while (1)
    {
        char choice = menu();

        switch (choice)
        {
        case 'Q':
        case 'q':
            printf("Exiting\n");
            return 0;
        case 'C':
        case 'c':
            c = getChar();
            break;
        case 'N':
        case 'n':
            n = getNum();
            break;
        case 'L':
        case 'l':
            if (isValid(n, c) == 1)
            {
                drawLine(n, c);
            }
            break;
        case 'S':
        case 's':
            if (isValid(n, c) == 1)
            {
                drawSquare(n, c);
            }
            break;
        case 'R':
        case 'r':
            if (isValid(n, c) == 1)
            {
                drawRec(n, c);
            }
            break;
        case 'T':
        case 't':
            if (isValid(n, c) == 1)
            {
                drawTri(n, c);
            }
            break;
        default:
            printf("Please enter a valid choice\n");
        }
    }
}

char menu()
{

    char choice = ' ';
    char buffer[10];

    printf("Menu Choice                    Input Choice\n");
    printf("Enter/Change Character         'C' or 'c'\n");
    printf("Enter/Change Number            'N' or 'n'\n");
    printf("Draw Line                      'L' or 'l'\n");
    printf("Draw Square                    'S' or 's'\n");
    printf("Draw Rectangle                 'R' or 'r'\n");
    printf("Draw Triangle(left justified)  'T' or 't'\n");
    printf("Quit Program                   'Q' or 'q'\n");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &choice);

    return choice;
}

char getChar()
{
    char x = ' ';
    printf("Enter a single character \n");
    scanf(" %c", &x);
    return x;
}

int getNum()
{
    int x = 0;
    while (x > 15 || x < 1)
    {
        printf("Please enter a number from 1-15: \n");
        scanf(" %d", &x);
    }
    return x;
}
