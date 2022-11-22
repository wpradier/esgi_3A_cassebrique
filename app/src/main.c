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
  
  t_coordinates coordinate;
  t_map *map;
  char* mapString;
  char *map_file_name;
  FILE *map_file;
  t_player* player1;
  player1 = &(t_player){.name ='a',.bomb_range=1,.bombs=1,.health_points=1,.heart=1,.invincible=1,.is_bomb_kick=1,.is_passing_bombs=1,.cordinates = {1,13}};
  coordinate = (t_coordinates){.x = 1,.y = 2};
  map_file_name = "maps/test.cassebrique";
  if (validate_map_format(map_file_name) != VALID_MAP_FORMAT) {
    perror("File format validation error.");
    return EXIT_FAILURE;
  }

  map_file = fopen(map_file_name, "r");

  printf("WELCOME\n");
  map = init_map(map_file);
  if(map != NULL){
      map->state[1][2]->bomb = malloc(sizeof(t_bomb));
      map->state[1][2]->bomb->range = 5;
      bomb_explosion(coordinate, map );

      mapString = display_map(map);

      printf("\nTaille de la chaîne %lu", strlen(mapString));
      printf("\n");

      printf("Autorisation to move :  %d \n",is_possible_to_move(map, player1, LEFT));


      success_msg(mapString);

      free(mapString);
      highlight_msg("Freed map string\n");

      free_map(map);
  }
  free(test_str);
  return 0;
}
