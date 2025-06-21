
#include "uteis.h"

char *leAtributo(FILE *fp)
{
    char input[MAX_STRING];
    fscanf(fp, "%[^';'];", input);
    char *atributo = strdup(input);
    return atributo;
}