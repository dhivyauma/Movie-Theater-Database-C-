#ifndef ACTOR_H
#define ACTOR_H

typedef struct Actor {
    int code;
    char name[50];
    int age;
    char imdb[50];
    struct Actor *next;
} Actor;

Actor* insertActor(Actor *head);
Actor* searchActor(Actor *head, int code);
void printActors(Actor *head);

#endif // ACTOR_H
