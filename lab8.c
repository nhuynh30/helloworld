#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc !=3){
        printf("Invalid Input\n");
        return -1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (in == NULL || out == NULL){
        printf("One of the file is Null. ERROR!\n");
        return -1;
    }

    char buffer[100];
    char account[67];
    char name[67];
    char date[67];
    char stock[67];
    int share;
    double open,high,low,close;

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Customer Name | %[^\n]", name);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Account Number | %[^\n]", account);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Report Date | %[^\n]", date);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Stock Name | %[^\n]", stock);
    stock[strcspn(stock, "\r\n")] = '\0';

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Shares Held | %d", &share);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Opening Price | %lf", &open);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "High Price | %lf", &high);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Low Price | %lf", &low);

    fgets(buffer, sizeof(buffer), in);
    sscanf(buffer, "Closing Price | %lf", &close);

    double profit = (close-open)*share;

    char *sign;

    if (profit==0.0){
        sign= "Unchanged";
    }else if(profit >0){
        sign= "Gain";
    }else{
        sign = "Loss";
        profit *= -1;
    }
}
