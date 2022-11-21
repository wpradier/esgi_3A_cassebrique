#include "cassebrique.h"



int	  main(void) {
  t_config *my_test = init_config("./cassebrique.conf");
  display_config(my_test);
  free_config(my_test);
  char  *test_str;

  test_str = ft_strnew(28);
  if (!test_str) {
    printf(RED);
    printf("ft_strnew call returned NULL\n");
    printf(NC);
    return 1;
  }

  t_map *map;
  char* mapString;
  char *map_file_name;
  FILE *map_file;

  map_file_name = "maps/test.cassebrique";
  if (validate_map_format(map_file_name) != VALID_MAP_FORMAT) {
    perror("File format validation error.");
    return EXIT_FAILURE;
  }

  map_file = fopen(map_file_name, "r");

  printf("WELCOME\n");
  map = init_map(map_file);
  if(map != NULL){
      mapString = display_map(map);

      printf("\nTaille de la chaîne %lu", strlen(mapString));
      printf("\n");

      success_msg(mapString);

      free(mapString);
      highlight_msg("Freed map string\n");

      free_map(map);
  }
  free(test_str);
  return 0;
}
