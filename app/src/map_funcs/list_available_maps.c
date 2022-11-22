#include "cassebrique.h"

FILE		    *open_map(const char *map_file_name) {
    if (validate_map_format(map_file_name) != VALID_MAP_FORMAT) {
	perror("File format validation error.");
	return NULL;
    }

    return fopen(map_file_name, "r");
}

t_map_list	    *list_available_maps(void) {
    char	    BUFF[256];
    t_map	    **maps;
    t_map_list	    *map_list;
    char	    **names;
    DIR		    *dr;
    struct dirent   *de;
    char	    *maps_dir = "maps/";
    char	    *map_files_ext = ".cassebrique";
    FILE	    *map_file;
    size_t	    ext_len;
    size_t	    filename_len;
    size_t	    maps_array_size;
    size_t	    display_name_len;



    if (!(dr = opendir(maps_dir))) {
	perror("Could not open maps directory");
	return NULL;
    }

    maps = NULL;
    ext_len = strlen(map_files_ext);
    maps_array_size = 0;
    map_list = malloc(sizeof(t_map_list));
    while ((de = readdir(dr))) {
	filename_len = strlen(de->d_name);

	// DT_REG == regular file.
	if (de->d_type != DT_REG || filename_len <= ext_len) {
	    continue;
	}
	

	// Check if current file extension matches defined "map_files_ext"
	if (!strncmp(de->d_name + filename_len - ext_len, map_files_ext, ext_len)) {
	    strcpy(BUFF, maps_dir);
	    strcat(BUFF, de->d_name);
	    if (!(map_file = open_map(BUFF))) {
		continue;
	    }

	    maps_array_size++;

	    maps = reallocarray(maps, maps_array_size, sizeof(t_map*));
	    maps[maps_array_size - 1] = init_map(map_file);
	    fclose(map_file);
	    

	    char **prev_names = names;
	    names = reallocarray(prev_names, maps_array_size, sizeof(char*));


	    display_name_len = filename_len - ext_len;

	    names[maps_array_size - 1] = malloc(sizeof(char) * (display_name_len + 1));
	    
	    strncpy(names[maps_array_size - 1], de->d_name, display_name_len);
	    names[maps_array_size - 1][display_name_len] = '\0';
	}
    }

    closedir(dr);

    map_list->list = maps;
    map_list->names = names;
    map_list->length = maps_array_size;

    return map_list;
}
