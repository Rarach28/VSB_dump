/* KNIHOVNY */
#include <stdio.h>
#include <stdlib.h>

#include <locale.h> // Kvuli formatu cisel

/* DEKLARACE FUNKCI A GLOBALNICH PROMENNYCH */

/* MAKRA */
#define PROJEKT "Strasne dobry projekt na rozmeneni penez"
#define AUTOR "~ Tomas Hotarek ~"

/* MAIN */
int main(int paramCount, char** paramVals) {
    /* DEKLARACE */
    int bankovky[] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int pocet;
    int castka = 0;
    int pocetBankovek = sizeof(bankovky) / sizeof(bankovky[0]);
    int kontrola = 0;

    setlocale(LC_NUMERIC, ""); //default number locale


    printf("\n\033[0;32m%s\n%27s\033[0m\n",PROJEKT,AUTOR);
    printf("\033[0;32m----------------------------------------\n\n\033[0m\n");

    /* KONTROLA, ZDA ČASTKA BYLA ZADANA PARAMETREM */
    if(paramCount > 1){
        castka = atoi(paramVals[1]);
        if(castka>0){
            kontrola = 1;
        }
    }

    /* ČEKÁNÍ NA VALIDNÍ ČÍSLO */
    while(castka < 1 || kontrola != 1){
        printf("Zadejte prosim kladnou celou castku v korunach: ");
        kontrola = scanf(" %d", &castka);

        /* ČEKÁNÍ NA ENTER A CLEAN BUFFER, BLBO PRO STRING */
        while (getchar() != '\n'); 
    }

    for (int i = 0; i < pocetBankovek; i++) {
        pocet = castka / bankovky[i];
        castka = castka - pocet * bankovky[i];
        if(pocet > 0){
            // ' dela to ze se pouziva locale //bolest
            printf("%'4d x %'5d =\t %'5d\n", pocet, bankovky[i],pocet*bankovky[i]);
        }
    }


    printf("\n\033[0;32m%s\n\033[0m\n","Konec");
    printf("\033[0;32m-----\n\n\033[0m\n");

    return 0;
}
