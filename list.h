#ifndef __LIST__H__
#define __LIST__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_element
{
    void *data;
    struct s_element *prev;
    struct s_element *next;
} t_element;

typedef struct s_list
{
    t_element *first;
    t_element *last;
} t_list;

void l_init(t_list *);
void l_push_back(t_list *, void *, size_t);
void l_push_front(t_list *, void *, size_t);
void *l_pop_back(t_list *);
void *l_pop_front(t_list *);

void l_view(t_list *);
void l_view_struct(t_list *);

void l_clear(t_list *);
void test_list(void);

#endif