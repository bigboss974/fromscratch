#ifndef __PARSER_H__
    #define __PARSER_H__
    
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

    /*Type de données  (command ou commentaire)*/
    # define NOT_COMMENT		0
    # define COMMENT			10
    # define START_CMD			20
    # define END_CMD			30
    # define UNKNOW_CMD			40

    
    int type_of_line(char *); //
    Bool startsWith( const char *, const char *); // Compare les premiers caractere d'une chaine
#endif