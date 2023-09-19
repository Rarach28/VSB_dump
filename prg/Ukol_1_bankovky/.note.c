/* Pro formatovani cisel */

#include <locale.h>

setlocale(LC_NUMERIC, ""); 

/* Format vy vypisu*/
printf("%'d",12000);

/////////

/* Pro osetreni zadani znaku misto cisla */
while(castka < 1 || kontrola != 1){
    printf("Zadejte prosim kladnou celou castku v korunach: ");
    kontrola = scanf(" %d", &castka);

    /* ČEKÁNÍ NA ENTER A CLEAN BUFFER, BLBLO PRO STRING */
    while (getchar() != '\n');  //!IMPORTANT, jinak cyklus jede nonstop
}
