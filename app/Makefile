NAME = cassebrique
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

INCLUDES = includes

SRCS = src/main.c 		\
       src/utils/ft_strnew.c


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
	@printf "$(_BOLD)RUNNING EXECUTABLE NOW...$(_NC)\n"
	@./$(NAME)

clean:
	@printf "$(_YELLOW)Cleaning object files$(_NC)..."
	@rm -f $(OBJS)
	@printf " $(_GREEN)OK$(_NC)\n"

fclean: clean
	@printf "$(_YELLOW)Cleaning executable$(_NC)..."
	@rm -f $(NAME)
	@printf " $(_GREEN)OK$(_NC)\n"

re: fclean all


.PHONY: all run clean fclean re
