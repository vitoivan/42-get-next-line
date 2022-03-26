# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

# Target SRC
TARGET = get_next_line.c get_next_line_utils.c tests/main.c

BONUS_TARGET = get_next_line_bonus.c get_next_line_utils.c test/main.c

# Objects
OBJS = $(TARGET:.c=.o)
BONUS_OBJS = $(BONUS_TARGET:.c=.o)

NAME = gnl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f *.o tests/*.o

fclean: clean
	rm -f $(NAME)
	rm -f *.out

re: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


bonus: $(BONUS_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS)

test: clean $(NAME)
	./$(NAME) $(file)

.PHONY: all clean fclean re test bonus 
