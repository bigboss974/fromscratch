#include <stdio.h>
#include <stdlib.h>
void parse_number (const char **ptr);
void parse_multiplication (const char **ptr);
void parse_addition (const char **ptr);
void parse_commentaire  (const char **exp);


int main()
{

    const char *expr = "##start";
    parse_addition (&expr);
    printf ("remaining expr : %s\n", expr);
    return 0;
}

void parse_commentaire (const char **expr)
{   
    if (**expr == '#')
    {
        
    }

}

void parse_multiplication (const char **expr)
{
    parse_number(expr);
    if (**expr == '*')
    {
        *expr +=1;
        parse_multiplication(expr);
        printf ("operator : *\n");
    }
    if (**expr == '/')
    {
        *expr +=1;
        parse_multiplication (expr);
        printf ("operator : /\n");
    }
 
}



void parse_addition (const char **expr)
{
    parse_multiplication(expr);
    if (**expr == '+')
    {
        *expr +=1;
        parse_addition(expr);
        printf ("operator : +\n");
    }
    if (**expr == '-')
    {
        *expr +=1;
        parse_addition (expr);
        printf ("operator : -\n");
    }
    
    if (**expr == '*')
    {
        *expr +=1;
        parse_addition (expr);
        printf ("operator : *\n");
    }
}


void parse_number (const char **ptr)
{
    char number[256];
    const char *expr = *ptr;
    int i=0;
    while ('0' <= expr[i] && expr[i] <= '9')
    {
        number[i] = expr[i];
        i = i+1;
    }
    number[i] = 0;
    *ptr= expr +i ; // ce qui reste a parser
    printf ("number : %s\n", number);

}