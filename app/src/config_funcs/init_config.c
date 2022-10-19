#include "../../includes/cassebrique.h"
#include <stdio.h>

/* Si ligne de config non valide (mauvaise valeur, mauvais format de ligne) ou non remplie,
 * mettre une valeur par défaut.
*/

t_config      *init_config(char *path);



int main() {




    FILE    *textfile;
    char ch;
    
    textfile = fopen("../../cassebrique.conf", "r");
    if(textfile == NULL)
        return 1;

    while((ch = fgetc(textfile))!=EOF) {
        putchar(ch);
    }
     
    fclose(textfile);
    return 0;
}





