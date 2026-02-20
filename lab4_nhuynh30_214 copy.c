/*
* Nam Quan Huynh G01508690
* CS262, Lab Section 214
* Lab4
*/
#include <stdio.h>

int uniqueDigit(int num);

int main(){
    int A = 0;
    int B = 0;
    char buffer[67];
    int valid = 0;
    int count = 0;


    while(valid != 1){
        printf("Please enter the value of A: \n");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &A);

        if (A<1 || A>5000){
            printf("Error! A must be from 1-5000\n");
            continue;
        }


        printf("Please enter the value of B: \n");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &B);

        if (B<1 || B>5000){
            printf("Error! B must be from 1-5000\n");
            continue;
        }

        if (A>B){
            printf("Error! Make sure A<=B\n");
            continue;
        }

        valid = 1;
    }

    printf("\n\n"); // extra space for clean output

    for (int i=A; i<=B; i++){
        if (uniqueDigit(i)==1){
            printf("%d\n", i);
            count+=1;
        }
    }
    printf("There are total of %d unique numbers.\n", count);


    return 0;
}

int uniqueDigit(int num){
    int arr[10] = {0};

    //if num is one digit, num is unique
    if (num<10 && num>0){
        return 1;
    }

    while(num>0){
        int lastDigit = num%10;
        if (arr[lastDigit] == 1){
            return 0;
        }
        arr[lastDigit] +=1;

        num/=10;

    }
    return 1;
    
}

