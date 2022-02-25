_SRC = get_next_line.c
_SRC_BONUS = get_next_line_bonus.c

SDIR = src
ODIR = build


SRC = $(addprefix $(SDIR)/,$(_SRC))
SRC_BONUS = $(addprefix $(SDIR)/,$(_SRC_BONUS))



OBJ = $(addprefix $(ODIR)/,$(_SRC:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(B)


all: re

$(ODIR)/%.o: $(SDIR)/%.c

	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(SDIR)/*.o  $(SDIR)/*.out
	@rm -f $(ODIR)/*.o
	@rm -f *.out


re: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o gnl.out

