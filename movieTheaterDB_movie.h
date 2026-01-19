#ifndef MOVIE_H
#define MOVIE_H

typedef struct Movie {
    int code;
    char title[100];
    int year;
    float rating;
    struct Movie *next;
} Movie;

Movie* insertMovie(Movie *head);
Movie* searchMovie(Movie *head, int code);
void printMovies(Movie *head);

#endif // MOVIE_H
