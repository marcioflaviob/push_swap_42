INCDIR = ./include/

NAME = push_swap
PS_FILE = push_swap.c
SRCSDIR = ./srcs/
OBJDIR = ./objs/

BONUS_NAME = checker
CHECKER = ./bonus/checker.c
BOBJDIR = ./bonus_objs/
BONUSDIR = ./bonus/

SOURCES = $(wildcard $(SRCSDIR)*.c)
BSOURCES = $(wildcard $(BONUSDIR)*.c)
OBJECTS = $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(SOURCES)))
BOBJECTS = $(addprefix $(BOBJDIR), $(notdir $(BSOURCES:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJECTS) $(OBJDIR)push_swap.o
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BOBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)push_swap.o: $(PS_FILE) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR)%.o: $(BONUSDIR)%.c | $(BOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR)checker.o: $(CHECKER) | $(BOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR):
	mkdir -p $(BOBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BOBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus