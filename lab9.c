#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Item{
    int itemId;
    char itemName[67];
    int quantity;
    double pricePerItem;

} Item;


int findIndex(Item *arr, int cnt, int id){
    for (int i=0; i<cnt; i++){
        if (arr[i].itemId == id){
            return i;
        }
    }
    return -1;
}




void update(Item *items, int cnt){
    int id;
    printf("Enter item ID: \n");
    scanf("%d", &id);

    int index = findIndex(items, cnt, id);
    if (index==-1){
        printf("Item not found\n");
        return;
    }

    printf("Please enter a new quantity for the item\n");
    scanf("%d", &items[index].quantity);



}




void insertItem(Item **items, int *cnt, int *cap){
    int id;
    char buffer[67];

    printf("Please enter the id of the item\n");
    scanf("%d", &id);

    if (findIndex(*items, *cnt, id) != -1){
        printf("Error Inserting an Item\n");
        return;
    }

    if (*cnt == *cap){
        *cap *=2;
        *items = realloc(*items, (*cap) * (sizeof(Item)) );
    }

    Item newItem;
    newItem.itemId = id;

    printf("Please enter the name of the item\n");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1]= '\0';
    strncpy(newItem.itemName, buffer, sizeof(newItem.itemName)-1);
    newItem.itemName[sizeof(newItem.itemName) - 1] = '\0';

    printf("Please enter the item's quantity\n");
    scanf("%d", &newItem.quantity);
    printf("Please enter the price per item\n");
    scanf("%lf", &newItem.pricePerItem);

    (*items)[*cnt] = newItem;
    (*cnt)+=1;

}
