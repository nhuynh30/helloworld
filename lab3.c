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