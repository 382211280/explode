#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
struct List
{
    int vertex;
    struct List *next;
};
typedef struct List *llink;
void insert_list(llink *, int);
void display_list(llink);
llink insert_list_recursive(llink, int);
llink search_list(llink, int);
void print_list(llink);
int list_length(llink);
void destroy_list(llink);

#endif // LIST_H