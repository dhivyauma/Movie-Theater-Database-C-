#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieTheaterDB_actor.h"

Actor* insertActor(Actor *head) {
    Actor *newNode = (Actor*)malloc(sizeof(Actor));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter actor code: ");
    scanf("%d", &newNode->code);
    getchar();  // consume newline after scanf

    // Check for duplicate code
    Actor *temp = head;
    while (temp != NULL) {
        if (temp->code == newNode->code) {
            printf("Actor with this code already exists.\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    printf("Enter actor name: ");
    fgets(newNode->name, sizeof(newNode->name), stdin);
    newNode->name[strcspn(newNode->name, "\n")] = 0; // remove newline

    printf("Enter actor age: ");
    scanf("%d", &newNode->age);
    getchar();

    printf("Enter actor IMDb: ");
    fgets(newNode->imdb, sizeof(newNode->imdb), stdin);
    newNode->imdb[strcspn(newNode->imdb, "\n")] = 0;

    newNode->next = head;
    head = newNode;
    printf("Actor inserted successfully.\n");
    return head;
}

Actor* searchActor(Actor *head, int code) {
    Actor *temp = head;
    while (temp != NULL) {
        if (temp->code == code) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printActors(Actor *head) {
    Actor *temp = head;
    if (temp == NULL) {
        printf("No actors found.\n");
        return;
    }

    printf("Actors List:\n");
    while (temp != NULL) {
        printf("Code: %d, Name: %s, Age: %d, IMDb: %s\n",
               temp->code, temp->name, temp->age, temp->imdb);
        temp = temp->next;
    }
}
