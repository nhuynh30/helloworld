#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Movie{
    char *title;
    struct Movie *next;
} Movie;

void insert_movie(Movie **head, char *title){
    Movie *newMovie = malloc(sizeof(Movie));
    int len = strlen(title);
    newMovie->title = malloc(len+1);
    strncpy(newMovie->title, title, len+1);
    newMovie->next = NULL;

    if(*head==NULL || strcmp(title, (*head)->title) < 0){
        newMovie->next = *head;
        *head = newMovie;
        return;
    }

    Movie *curr = *head;
    while(curr->next!= NULL && strcmp(curr->next->title, title) < 0){
        curr = curr->next;
    }

    newMovie->next = curr->next;
    curr->next = newMovie;

}

void delete_movie(Movie **head, char *title){
    if (*head== NULL){
        return;
    }

    Movie *curr = *head;
    Movie *prev = NULL;
    while (curr!=NULL){
        if (strcmp(curr->title, title)==0){
            Movie *temp = curr;
            if (prev==NULL){
                *head = curr->next;
                free(temp->title);
                free(temp);
                return;
            }else{
                prev->next = curr->next;
                free(temp->title);
                free(temp);
                return;
            }
        }
        prev = curr;
        curr = curr->next;
        
    }
    return;
}


void display_movie(Movie *head){
    if (head == NULL){
        printf("Movie list is empty\n");
        return;
    }
    printf("Here is the movie list:\n");
    int id = 1;
    Movie *curr = head;
    while (curr!=NULL){
        printf("Movie %d: ", id);
        printf("%s\n", (curr->title));
        curr = curr->next;
        id++;
    }
    printf("\n");
    return;
}
