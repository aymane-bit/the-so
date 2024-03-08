CC = cc
CFLAGS = -Wall -Wextra #-Werror
SRC = so_long_b.c get_next_line.c get_next_line_utils.c
LIB = -lmlx -lXext -lX11 -lm -lbsd
cc test.c -lmlx -L-L/usr/lib -lX11 -lXext -lm



all :
    $(CC) $(CFLAGS) $(SRC) $(LIB)
    ./a.out map1.ber