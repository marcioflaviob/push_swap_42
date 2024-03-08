NAME = push_swap
BONUS = checker
INCDIR = ./include/
SRCSDIR = ./srcs/
OBJDIR = ./objs/
BOBJDIR = ./bobjs/
BONUSDIR = ./checker/

SOURCES = $(wildcard $(SRCSDIR)*.c)
BSOURCES = $(wildcard $(BONUSDIR)*.c)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
BOBJECTS = $(addprefix $(BOBJDIR), $(notdir $(BSOURCES:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

bonus: all $(BONUS)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	mv -f $(OBJECTS) $(OBJDIR)

$(BONUS): $(BOBJECTS)
	$(CC) $(CFLAGS) -o $@ $(BOBJECTS)

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BOBJDIR)%.o: $(BONUSDIR)%.c | $(BOBJDIR)
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
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
