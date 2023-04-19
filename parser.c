#include "./include/parser.h"

Bool startsWith( const char * theString, const char * theBase ) {
    return strncmp( theString, theBase, strlen( theBase ) ) == 0;
}



int type_of_line (char* line)
{
    int type; // command, commentaire,....

    /*Si la ligne commence par un #*/
    if (line ==  NULL || *line != '#')
            return NOT_COMMENT;
    
    if (startsWith (line, "##start"))
        type = START_CMD;
    else if (startsWith (line, "##end"))
        type = END_CMD;
        else type = COMMENT;

    return (type);
}




