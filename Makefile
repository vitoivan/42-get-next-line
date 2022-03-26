# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

# Target SRC
TARGET = get_next_line.c get_next_line_utils.c tests/main.c
TEST_TARGET = tests/main.c

# Objects
OBJS = $(TARGET:.c=.o)

MAIN = gnl

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean:
	rm -f *.o tests/*.o

fclean: clean
	rm -f $(MAIN)
	rm -f *.out

re: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

test: clean $(MAIN)
	./$(MAIN) $(file)

.PHONY: all clean fclean re test 
