#include <stdio.h>
#include <stdlib.h>
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"

int main() {
    Movie *movieHead = NULL;
    Actor *actorHead = NULL;
    int choice, code;
    Movie *foundMovie;
    Actor *foundActor;

    while (1) {
        printf("\nMovie Theater Database\n");
        printf("1. Insert Movie\n");
        printf("2. Search Movie\n");
        printf("3. Print Movies\n");
        printf("4. Insert Actor\n");
        printf("5. Search Actor\n");
        printf("6. Print Actors\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                movieHead = insertMovie(movieHead);
                break;
            case 2:
                printf("Enter movie code to search: ");
                scanf("%d", &code);
                getchar();
                foundMovie = searchMovie(movieHead, code);
                if (foundMovie) {
                    printf("Movie found: Code: %d, Title: %s, Year: %d, Rating: %.1f\n",
                           foundMovie->code, foundMovie->title, foundMovie->year, foundMovie->rating);
                } else {
                    printf("Movie not found.\n");
                }
                break;
            case 3:
                printMovies(movieHead);
                break;
            case 4:
                actorHead = insertActor(actorHead);
                break;
            case 5:
                printf("Enter actor code to search: ");
                scanf("%d", &code);
                getchar();
                foundActor = searchActor(actorHead, code);
                if (foundActor) {
                    printf("Actor found: Code: %d, Name: %s, Age: %d, IMDb: %s\n",
                           foundActor->code, foundActor->name, foundActor->age, foundActor->imdb);
                } else {
                    printf("Actor not found.\n");
                }
                break;
            case 6:
                printActors(actorHead);
                break;
            case 7:
                printf("Exiting program.\n");
                // Free memory here if you want
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
