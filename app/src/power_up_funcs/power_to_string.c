//
// Created by Manveer Singh on 22/11/2022.
//
# include "cassebrique.h"

char* power_to_string(t_power_up power){
    switch (power) {
        case 0:
            return "-";
        case 1:
            return "B";
        case 2:
            return "b";
        case 3:
            return "Y";
        case 4:
            return "B";
        case 5:
            return "R";
        case 6:
            return "P";
        case 7:
            return "K";
        case 8:
            return "I";
        case 9:
            return "h";
        case 10:
            return "H";
        default:
            return " ";
    }
}