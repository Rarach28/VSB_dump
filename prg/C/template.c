/* KNIHOVNY */
#include <stdio.h>
#include <stdlib.h>

/* DEKLARACE FUNKCI A GLOBALNICH PROMENNYCH */

/* MAKRA */
#define PROJEKT "Unnamed"
#define AUTOR "~ Tomas Hotarek ~"

/* MAIN */
int main(int paramCount, char** paramVals) {
    /* DEKLARACE */

    char* projektName = "Unnamed";
    printf("\n\033[0;32m%s\n%27s\033[0m\n",PROJEKT,AUTOR);
    printf("\033[0;32m----------------------------------------\n\n\033[0m\n");


    // KOD TADY //


    printf("\n\033[0;32m%s\033[0m\n","Konec");
    printf("\033[0;32m-----\n\033[0m\n");

    return 0;
}
