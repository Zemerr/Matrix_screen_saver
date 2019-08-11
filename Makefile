NAME = rase05

SRCS = src/test2.c

INC = inc/header.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: install clean

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCS) -I inc

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf header.h
	@rm -rf test2.c

reinstall: uninstall clean all
