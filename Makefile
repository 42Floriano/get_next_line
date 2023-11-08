####################################################################
## Sources
FILES = get_next_line\
					get_next_line_utils\

HEADER = get_next_line.h\
## This is a bit tricky for me but it ask to check the end of the string in FILES than add .c if there is nothing
## Also possible to just liste the .c and .o files
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER)
NAME = get_next_line

#####################################################################
## Rules

all: $(NAME)

$(NAME): $(OFILES)
		$(CC) $(OFILES) -o $(NAME)

### For each .o file  it needs the the .c file | $< is automatic var that takes the param and $@ the target
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

## Tells the Makefiles that all(all, clean, fclean, re) are not files but just rules
.PHONY: all clean fclean re