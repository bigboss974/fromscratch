/*
                VERSIOn 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


typedef struct s_student
{   
    char *firstname;
    char *lastname;
    int rollNumber;
}STUDENT;

void test1 ()
{
    STUDENT *students = malloc (2*sizeof(*students));

    for (int i = 0; i < 2 ; i++)
    {
        students[i].firstname = (char *)malloc (20*sizeof(char *));
        students[i].lastname = (char *)malloc (20*sizeof(char *));
        students[i].rollNumber = i;
    }
    strcpy(students[0].firstname, "Student 1");
    strcpy(students[0].lastname, "Student 1 last");
    strcpy(students[1].firstname, "Student 2");
    strcpy(students[1].lastname, "Student 2 last");

    for (int i=0; i < 2 ; i++)
    {
        printf ("[%s] [%s] [%d]\n",students[i].firstname, students[i].lastname, students[i].rollNumber);
    }

    for (int i=0; i < 2 ; i++)
    {
        free (students[i].firstname);
        free (students[i].lastname);
    }
    free (students);
}

void test2()
{
    t_list *malist = (t_list *)malloc (sizeof (t_list ));

    //if (malist == NULL) exit (EXIT_FAILURE);
    l_init(malist);
    char *str = "Hello world\0";
    char *str2= "Allo world";

    l_push_back(malist, str2, strlen(str2)+1);
    l_view(malist);
    l_clear(malist);
    free(malist);
}

int main (int argc, char *argv[])
{
    //test1();
    test2 ();

    return 0;
}