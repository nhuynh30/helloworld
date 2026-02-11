#include <stdio.h>
#define BSA1 0.007184
#define BSA2 0.425
#define BSA3 0.725
#include <math.h>


int main(){
    float height, weight;
    double res;
    char input[50];

    printf("Please enter your weight(kg) and height(cm): \n");
    fgets(input, sizeof(input),stdin);
    sscanf(input, "%f %f", &weight, &height);

    res = BSA1 * pow(weight, BSA2) * pow(height, BSA3);
    printf("The height is: %.1f centimeters\n", height);
    printf("The weight is: %.1f kilograms\n", weight );
    printf("BSA: %.4f square meters\n", res);
    print

    return 0;
}
