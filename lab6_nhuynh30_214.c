/*
* Nam Huynh and G01508690
* CS262, Lab section 214
* Lab 6
*/

#include <stdio.h>
#include <stdlib.h>

void InitArray(int *numArray, int arrayLength);
void printArray(int *numArray, int arrayLength);
void ShuffleArray(int *numArray, int arrayLength);
int *get_memory(int n);
int compare(const void *a, const void *b);


int main(int argc, char *argv[]){
    if (argc!=3){
        printf("Invalid Input\n");
        return -1;
    }
    int seed = atoi(argv[1]);
    int lenArr = atoi(argv[2]);

    if (lenArr <2 || lenArr>200){
        printf("Size of array has to be in range [2-200]\n");
        return -1;
    }
    srand(seed);
    int *numArray = get_memory(lenArr);

    for (int i =0; i<15; i++){
        printf("-------Round %d-------\n", i+1);
        printf("Initialize Array\n");
        InitArray(numArray, lenArr);
        printArray(numArray, lenArr);

        printf("Shuffled Array\n");
        ShuffleArray(numArray, lenArr);
        printArray(numArray, lenArr);

        printf("Sorting Array\n");
        qsort(numArray, lenArr, sizeof(int), compare);
        printArray(numArray, lenArr);

    }

    free(numArray);




    return 0;
}

int *get_memory(int n){
    int *numArray = malloc(n*sizeof(int));

    if (numArray == NULL){
        printf("Error allocating memory\n");
        exit(-1);
    }
    return numArray;
}

void InitArray(int *numArray, int arrayLength){
    for (int i=0; i<arrayLength; i++){
        numArray[i] = i+1;
    }
}

void printArray(int *numArray, int arrayLength){
    for (int i=0; i<arrayLength; i++){
        printf("%d", numArray[i]);
        if (i<arrayLength-1){
            printf(", ");
        }
    }
    printf("\n\n");
}

void ShuffleArray(int *numArray, int arrayLength){
    for (int i =arrayLength-1; i>0; i--){
        int j=rand()%(i+1);
        int temp = numArray[i];
        numArray[i] = numArray[j];
        numArray[j] = temp;
    }
}

int compare(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}
