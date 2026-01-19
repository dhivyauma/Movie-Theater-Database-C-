# Movie Theater Database (C)

A command-line database application written in C for managing two simple datasets: movies and actors. The program provides an interactive menu to insert, search, and print records. Data is stored in memory using singly linked lists.

## Features
- Movie management
  - Insert a movie (with duplicate code checking)
  - Search a movie by code
  - Print all movies

- Actor management
  - Insert an actor (with duplicate code checking)
  - Search an actor by code
  - Print all actors

- Interactive terminal menu loop
  - Clear numbered options
  - Immediate feedback for success and search results

## Data Model
### Movie
Stored as a node in a singly linked list:
- `code` (int)
- `title` (string)
- `year` (int)
- `rating` (float)
- `next` pointer

Defined in: `movieTheaterDB_movie.h`

### Actor
Stored as a node in a singly linked list:
- `code` (int)
- `name` (string)
- `age` (int)
- `imdb` (string)
- `next` pointer

Defined in: `movieTheaterDB_actor.h`

## Project Structure
- `movieTheaterDB.c`
  - Main program and menu interface
  - Calls insert/search/print functions for movies and actors

- `movieTheaterDB_movie.h`
  - `Movie` struct definition and function prototypes:
    - `insertMovie`
    - `searchMovie`
    - `printMovies`

- `movieTheaterDB_actor.h`
  - `Actor` struct definition and function prototypes:
    - `insertActor`
    - `searchActor`
    - `printActors`

- `movieTheaterDB_actor.c`
  - Actor operations implementation (insert/search/print)

- `movieTheaterDB.h`
  - Common includes (stdio/stdlib/string)

- `Makefile`
  - Build rules for compiling and linking the program

- `movieTheater.png`
  - Example run screenshot

## Build
Using the Makefile:

```bash
make
