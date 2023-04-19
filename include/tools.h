#ifndef __TOOLS_H__
    #define __TOOLS_H__
    
    /*Fichier a inclure */
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    /*Définition type Booléen*/
    typedef enum
    {
        false,
        true
    }Bool;

    
    Bool is_digit (char );
    void str_split (char**, char*, char);
    void parse_str (char **);
    void parse_comment (char **);
#endif