NAME 	= so_long

CC 		= cc -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFT = ./LIBFT/libft.a

CFLAGS 	=  -Imlx

SRCS 	=	solong.c				\

all: $(NAME)

$(LIBFT):
		$(MAKE) -C ./LIBFT

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC)   $^ -o $@

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all