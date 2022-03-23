# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

# Target SRC
TARGET = get_next_line.c get_next_line_utils.c tests/main.c

# Objects
OBJS = $(TARGET:.c=.o)

MAIN = gnl

all: $(MAIN)
	@echo "Simple compiler named $(MAIN) has been compiled"

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
	./$(MAIN) ./teste.txt

.PHONY: clean
