#include <stdio.h>
#include <stdlib.h>
char *parse_str(const char **ptr);
// void parse_multiplication (const char **ptr);
void parse_token(const char **ptr, char **str, int inc);
// void parse_commentaire  (const char **exp);

int main()
{
    int i = 0;
    const char *expr = "Salle1 19 30";
    char **ptr;
    ptr = malloc (sizeof(char*));
    //printf ();
    parse_token(&expr, ptr, 0);

    for (i=0; i<3; i++)
         printf ("main : [%d] %s\n", i, ptr[i]);
    //    printf ("remaining expr : %s\n", expr);
    return 0;
}

void parse_token(const char **expr, char **str, int inc)
{
    str[inc] = (char *)parse_str(expr);
//    printf("token : [%s] [%d]\n", str[inc], inc);

    if (**expr == ' ')
    {
        *expr += 1;
        inc++;
        parse_token(expr, str, inc);
    }
}

char *parse_str(const char **ptr)
{
    char *str;
    str = malloc(50 * sizeof(char));
    const char *expr = *ptr;
    int i = 0;

    while (expr[i] != ' ' && expr[i] != '\0')
    {
        str[i] = expr[i];
        i = i + 1;
    }
    str[i] = '\0';
    *ptr = expr + i; // ce qui reste a parser
    return str;
}