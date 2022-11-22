NAME = cassebrique
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

INCLUDES = includes

SRCS = src/main.c\
       src/utils/ft_strnew.c\
       src/utils/error_msg.c\
       src/utils/success_msg.c\
       src/utils/warning_msg.c\
       src/utils/highlight_msg.c\
       src/map_funcs/init_map.c\
       src/map_funcs/free_map.c\
       src/map_funcs/display_map.c\
       src/map_funcs/validate_map_data.c\
       src/map_funcs/validate_map_format.c\
       src/power_up_funcs/give_power_up.c\
       src/config_funcs/init_config.c \
       src/config_funcs/display_config.c \
       src/config_funcs/free_config.c \
       src/movements_funcs/is_possible_to_move.c \
       src/bomb_funcs/bomb_funcs.c
       src/power_up_funcs/init_power_ups.c\
       src/power_up_funcs/power_to_string.c\


OBJS = $(SRCS:.c=.o)

_BOLD=\033[1;97m
_RED=\033[0;31m
_GREEN=\033[1;32m
_YELLOW=\033[1;33m
_NC=\033[0m


all: $(NAME)


$(NAME): $(OBJS)
	@printf "Making $(_BOLD)$@$(_NC)..."
	@$(CC) -o $@ $^ $(LDFLAGS)
	@printf " $(_GREEN)OK$(_NC)\n"

%.o: %.c
	@printf "Assembling $(_BOLD)$@$(_NC)..."
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
	@printf " $(_GREEN)OK$(_NC)\n"


$(OBJS): $(INCLUDES)/cassebrique.h

run: $(NAME)
	@printf "$(_BOLD)RUNNING APP...$(_NC)\n"
	@./$(NAME)

clean:
	@printf "$(_YELLOW)Cleaning intermediate app building files$(_NC)..."
	@rm -f $(OBJS)
	@printf " $(_GREEN)OK$(_NC)\n"
ifeq ($(MAKECMDGOALS), clean)
	@make -C tests/ clean
endif

fclean: clean
	@printf "$(_YELLOW)Cleaning app executable$(_NC)..."
	@rm -f $(NAME)
	@printf " $(_GREEN)OK$(_NC)\n"
	@make -C tests/ fclean

re: fclean all


tests_run:
	@make -C tests/ run

tests_coverage:
	@make -C tests/ coverage


.PHONY: all run clean fclean re tests_run tests_coverage
