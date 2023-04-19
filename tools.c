#include "./include/tools.h"
void parse_comment (char **expr)
{   
    Bool command = false;
    if (**expr == '#')
    {
        *expr += 1;
        if (**expr == '#')
        {
         //   printf ("Commande detectée\n");
            parse_str (expr);
            command = true;
            *expr +=1;
        } 
        else 
        {
             printf ("1 : Comment %s", *(expr));  
        }
    }
    else 
    {
    //    printf ("5 .1  :[%s]\n" , *expr);  

        //*expr += 1;
        parse_str (expr);
        //printf ("5 :[%s]\n" , *expr);  
    }
    if (command)
        printf ("6 : Commande à exécuter %s", *expr);
}

void parse_str (char **ptr)
{  
    char str[256];
    char *expr = *ptr;
    int i=0;

    if (expr[i] != '#')
    {
        while (expr[i] != '\0' && expr[i] != '#')
        {
            str[i] = expr[i];
            i = i + 1 ;
        }
        str[i] = '\0'; 
        *ptr = expr + i ; //+1 ;
        printf ("3 : Salle ou link %s\n",str );
        i=0;
    } //if
}

int main (void)
{
    int taille;
    char *str= "Salle1 10 24";

    parse_comment(str);
    return 0;
}

/*int main (void)
{   
    char* buffer;
    size_t bufsize = 32;

    buffer = (char*) malloc (bufsize*sizeof (char));
    if (buffer == NULL)
    {
        perror ("Unable to allocate buffer");
        exit (EXIT_FAILURE);
    }
   
    getline (&buffer, &bufsize, stdin);
    printf ("Nombre de fourmis : %s", buffer);

    while (getline (&buffer, &bufsize, stdin) != EOF)
    {
         parse_comment (&buffer);
    }
    free (buffer);
}*/