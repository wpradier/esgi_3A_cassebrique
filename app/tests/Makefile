NAME = unit-tests
CC = gcc
CFLAGS = -Wall -Wextra -Werror --coverage
LDFLAGS = --coverage -lcriterion -lgcov

INCLUDES = includes
TESTED_INCLUDES= ../includes

SRCS = utils.c \
       config_funcs.c


OBJS = $(SRCS:.c=.o)

TESTED_SRCS= ../src/utils/ft_strnew.c \
	     ../src/config_funcs/init_config.c

TESTED_OBJS = $(TESTED_SRCS:.c=.o)

GCNO = $(SRCS:.c=.gcno) $(TESTED_SRCS:.c=.gcno)

GCDA = $(SRCS:.c=.gcda) $(TESTED_SRCS:.c=.gcda)

CGCOV = *.c.gcov


_BOLD=\033[1;97m
_RED=\033[0;31m
_GREEN=\033[1;32m
_YELLOW=\033[1;33m
_NC=\033[0m


all: $(NAME)


$(NAME): $(OBJS) $(TESTED_OBJS)
	@printf "Making $(_BOLD)$@$(_NC)..."
	@$(CC) -o $@ $^ $(LDFLAGS)
	@printf " $(_GREEN)OK$(_NC)\n"

%.o: %.c
	@printf "Assembling $(_BOLD)$@$(_NC)..."
	@$(CC) -o $@ -c $< -I$(INCLUDES) -I$(TESTED_INCLUDES) $(CFLAGS)
	@printf " $(_GREEN)OK$(_NC)\n"


$(OBJS): $(INCLUDES)/unit-tests.h


run: $(NAME)
	@printf "$(_BOLD)RUNNING TESTS...$(_NC)\n"
	@./$(NAME) --verbose

clean:
	@printf "$(_YELLOW)Cleaning intermediate tests building files$(_NC)..."
	@rm -f $(OBJS) $(GCNO) $(GCDA) $(CGCOV)
	@printf " $(_GREEN)OK$(_NC)\n"

fclean: clean
	@printf "$(_YELLOW)Cleaning tests executable$(_NC)..."
	@rm -f $(NAME)
	@printf " $(_GREEN)OK$(_NC)\n"

re: fclean all


coverage: run
	@printf "$(_BOLD)COVERAGE$(_NC)\n"
	@gcov $(SRCS) $(TESTED_SRCS)


.PHONY: all run clean fclean re coverage
