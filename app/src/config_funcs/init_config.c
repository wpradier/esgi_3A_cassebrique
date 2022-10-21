#include "../../includes/cassebrique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Si ligne de config non valide (mauvaise valeur, mauvais format de ligne) ou non remplie,
 * mettre une valeur par défaut.
*/



t_config    *init_config(char *path){
    //char * mypath = "../../cassebrique.conf";

    unsigned short myconf[12];
    unsigned short* myconf_ptr = NULL;
    t_config* final_conf = malloc(sizeof(t_config));
    FILE    *textfile;
    char ch;
    int counter = 0;
    int counter_buffer = 0;
    char buffer[5];
    int number_found = 0;
    
    
    textfile = fopen(path, "r");
    if(textfile == NULL)
        return 1;
    

    while((ch = fgetc(textfile))!=EOF) { 
        number_found = 0;
        if(isdigit(ch))
        {
            do
            {
                buffer[counter_buffer++] = ch;
                number_found = 1;
                ch = fgetc(textfile);
            }
            while(ch!=EOF && isdigit(ch));
        }
        
        if(number_found == 1)
        {
            buffer[counter_buffer] = '\0';
            counter_buffer = 0;
            myconf[counter++] = (unsigned short)(atoi(buffer));
        }
    }
    
    fclose(textfile);
    myconf_ptr = (unsigned short*)(final_conf);

    for(int i=0; i<12; i++){

        myconf_ptr[i] = myconf[i];
    }
    //printf("I've read invincibility_rate=%d\n", final_conf->invincibility_rate);

    if(final_conf->invincibility_rate>0) final_conf->invincibility_rate = 0;
    if(final_conf->heart_rate>0) final_conf->heart_rate = 0;
    if(final_conf->health_up_rate>0) final_conf->health_up_rate = 0;
    
    return final_conf;
}


void	    display_config(t_config *config){

    for(int i = 0; i <12;i++){
        printf("%d\n",config[i]);
    }

}


void	    free_config(t_config *config){
    free(config);
    config = NULL;

}
