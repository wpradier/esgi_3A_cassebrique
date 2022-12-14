#include "cassebrique.h"


/* Si ligne de config non valide (mauvaise valeur, mauvais format de ligne) ou non remplie,
 * mettre une valeur par défaut.
*/



t_config    *init_config(char *path){
    //char * mypath = "../../cassebrique.conf";
    int len_to_allocate = sizeof(t_config)/sizeof(unsigned short);
    unsigned short *myconf_ptr = NULL;
    t_config *final_conf = malloc(sizeof(t_config));
    FILE    *textfile;

    unsigned short value = 0;
    int counter = 0; 

    size_t len = 0;
    ssize_t read;
    char   *line = NULL;

    char delim[] = "= ";
    char   *ptr = NULL;

    const int default_val = 0;

    // init config with unassigned values
    myconf_ptr = (unsigned short*)(final_conf);
    for(int i=0; i<len_to_allocate; i++){
        myconf_ptr[i] = default_val;
    }

    textfile = fopen(path, "r");
    if(textfile == NULL)
        return NULL;

    
    while((read = getline(&line, &len, textfile)) != -1) {
        ptr = strtok(line, delim);
        // printf("spliter str: %s\n", ptr);
        // ptr = strtok(NULL, delim);
        // printf("spliter int: %d\n", value);
        
        counter++;
        if (counter-1==len_to_allocate){ //if empty line added to the end of the conf file
            break;
        }
    
        
        char *bomb_max_range = strstr("bomb_max_range", ptr);
        char *bomb_up_rate = strstr("bomb_up_rate", ptr);
        char *bomb_down_rate = strstr("bomb_down_rate", ptr);
        char *yellow_flame_rate = strstr("yellow_flame_rate", ptr);
        char *blue_flame_rate = strstr("blue_flame_rate", ptr);
        char *red_flame_rate = strstr("red_flame_rate", ptr);
        char *pass_bomb_rate = strstr("pass_bomb_rate", ptr);
        char *bomb_kick_rate = strstr("bomb_kick_rate", ptr);
        char *invincibility_rate = strstr("invincibility_rate", ptr);
        char *heart_rate = strstr("heart_rate", ptr);
        char *health_up_rate = strstr("health_up_rate", ptr);
        char *number_of_powers = strstr("number_of_powers", ptr);
        char *powers_spawn_rate = strstr("powers_spawn_rate", ptr);

        ptr = strtok(NULL, delim);
        value = (unsigned short)(atoi(ptr));

        if (bomb_max_range != NULL){
            final_conf->bomb_max_range = value;
        }
        else if (bomb_up_rate != NULL){
            final_conf->bomb_up_rate = value;
        }
        else if (bomb_down_rate != NULL){
            final_conf->bomb_down_rate = value;
        }
        else if (yellow_flame_rate != NULL){
            final_conf->yellow_flame_rate = value;
        }
        else if (blue_flame_rate != NULL){
            final_conf->blue_flame_rate = value;
        }
        else if (red_flame_rate != NULL){
            final_conf->red_flame_rate = value;
        }
        else if (pass_bomb_rate != NULL){
            final_conf->pass_bomb_rate = value;
        }
        else if (bomb_kick_rate != NULL){
            final_conf->bomb_kick_rate = value;
        }
        else if (invincibility_rate != NULL){
            final_conf->invincibility_rate = value;
        }
        else if (heart_rate != NULL){
            final_conf->heart_rate = value;
        }
        else if (health_up_rate != NULL){
            final_conf->health_up_rate = value;
        }
        else if (number_of_powers != NULL){
            final_conf->number_of_powers = value;
        }
        else if (powers_spawn_rate != NULL){
            final_conf->powers_spawn_rate = value;
        }
        else {
            printf("the given config line is not readable [%s]\n", line);
        }
    }
 
    
    fclose(textfile);
    
    

    return final_conf;
}


