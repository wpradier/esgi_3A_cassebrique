//
// Created by Manveer Singh on 26/10/2022.
//
#include "cassebrique.h"

int validate_map_format(const char *name){
    char* extension = ".cassebrique";

    if(strcmp(name + strlen(name) - strlen(extension), extension) != 0){
        error_msg("Wrong file name!");
        return INVALID_FILE_NAME;
    } else{
        //success_msg("File name is good!");
        return VALID_MAP_FORMAT;
    }
}
