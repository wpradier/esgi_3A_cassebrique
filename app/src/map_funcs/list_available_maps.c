#include "cassebrique.h"


t_map		    **list_available_maps(void) {
    t_map	    **maps;
    DIR		    *dr;
    struct dirent   *de;
    char	    *maps_dir = "maps/";
    char	    *map_files_ext = ".cassebrique";
    size_t	    ext_len;
    size_t	    filename_len;
    size_t	    maps_array_size;



    if (!(dr = opendir(maps_dir))) {
	perror("Could not open maps directory");
	return NULL;
    }

    maps = NULL;
    ext_len = strlen(map_files_ext);
    maps_array_size = 0;
    while ((de = readdir(dr))) {
	filename_len = strlen(de->d_name);

	// DT_REG == regular file.
	if (de->d_type != DT_REG || filename_len <= ext_len) {
	    continue;
	}
	

	// Check if current file extension matches defined "map_files_ext"
	if (!strncmp(de->d_name + filename_len - ext_len, map_files_ext, ext_len)) {
	    maps_array_size++;
	    maps = reallocarray(maps, maps_array_size, sizeof(t_map*));
	    maps[maps_array_size - 1] = init_map();
	}
    }

    closedir(dr);


    return maps;
}
