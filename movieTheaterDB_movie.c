#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieTheaterDB_movie.h"

Movie* insertMovie(Movie *head) {
    Movie *newNode = (Movie*)malloc(sizeof(Movie));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter movie code: ");
    scanf("%d", &newNode->code);
    getchar();

    // Check duplicate
    Movie *temp = head;
    while (temp != NULL) {
        if (temp->code == newNode->code) {
            printf("Movie with this code already exists.\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    printf("Enter movie title: ");
    fgets(newNode->title, sizeof(newNode->title), stdin);
    newNode->title[strcspn(newNode->title, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &newNode->year);
    getchar();

    printf("Enter rating (0.0 - 10.0): ");
    scanf("%f", &newNode->rating);
    getchar();

    newNode->next = head;
    head = newNode;

    printf("Movie inserted successfully.\n");
    return head;
}

Movie* searchMovie(Movie *head, int code) {
    Movie *temp = head;
    while (temp != NULL) {
        if (temp->code == code) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printMovies(Movie *head) {
    Movie *temp = head;
    if (temp == NULL) {
        printf("No movies found.\n");
        return;
    }

    printf("Movies List:\n");
    while (temp != NULL) {
        printf("Code: %d, Title: %s, Year: %d, Rating: %.1f\n",
               temp->code, temp->title, temp->year, temp->rating);
        temp = temp->next;
    }
}
