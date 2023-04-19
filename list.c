// #include "list.h"
#include "list.h"

/*
        Front ==> NULL <- el1 -> el2 -> NULL <== Back
                   /|\                   /|\
                    |                     |
                First                   Last

    File : FIFO PushBack PopFront || Pushfront PopBack
    Pile : LIFO PushBack PopBack || PushFront PopFront
*/

/*
**================= l_init ========================
**Initialisation des pointeurs d'entrée et de sortie de la liste.
*/
void l_init(t_list *l)
{
    l->first = NULL;
    l->last = NULL;
}

/*
**================= l_push_back ========================
** Ajoute un élement data de taille size en fin de liste
*/
void l_push_back(t_list *l, void *data, size_t size)
{
    t_element *newone = malloc(sizeof(t_element));

    if (!newone)
        exit(EXIT_FAILURE);

    newone->data = malloc(size);
    if (!newone->data)
        exit(EXIT_FAILURE);
    memcpy(newone->data, data, size);

    newone->prev = l->last;
    newone->next = NULL;

    if (l->last)
        l->last->next = newone;
    else
        l->first = newone;

    l->last = newone;
}

/*
**================= l_push_front ========================
** Ajoute un élement data de taille size en début de liste
*/
void l_push_front(t_list *l, void *data, size_t size)
{
    t_element *newone = malloc(sizeof(t_element));

    if (!newone)
        exit(EXIT_FAILURE);

    newone->data = malloc(size);
    if (!newone->data)
        exit(EXIT_FAILURE);
    memcpy(newone->data, data, size);

    newone->next = l->first;
    newone->prev = NULL;

    if (l->first)
        l->first->prev = newone;
    else
        l->last = newone;

    l->first = newone;
}

/*
**================= l_pop_back ========================
*/
void *l_pop_back(t_list *l)
{
    t_element *tmp = l->last;
    void *val;

    if (!tmp)
        return NULL;
    val = tmp->data;
    l->last = tmp->prev;

    if (l->last)
        l->last->next = NULL;
    else
        l->first = NULL;

    free(tmp);
    return val;
}

/*
**================= l_pop_front ========================
*/
void *l_pop_front(t_list *l)
{
    t_element *tmp = l->first;
    void *val;

    if (!tmp)
        return NULL;
    val = tmp->data;
    l->first = tmp->next;

    if (l->first)
        l->first->prev = NULL;
    else
        l->last = NULL;

    free(tmp);
    return val;
}

/*
**================= l_clear ========================
** Vide la liste libere la mémoire.
*/
void l_clear(t_list *l)
{
    t_element *tmp;
    t_element *pelem = l->first;

    while (pelem)
    {
        tmp = pelem;
        pelem = pelem->next;
        free(tmp);
    }
    l->first = NULL;
    l->last = NULL;
}

/*
**================= l_view ========================
** Affiche la file  (exemple a modifier en fonction des besoins (cast))
*/
void l_view(t_list *l)
{
    t_element *pelem = l->first;
    while (pelem != NULL)
    {
        printf("elem : [%s]\n", (char *)pelem->data);
        pelem = pelem->next;
    }
}