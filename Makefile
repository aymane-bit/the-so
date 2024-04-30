# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 03:50:25 by jotavare          #+#    #+#              #
#    Updated: 2024/03/20 23:43:35 by akajjou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
BONUS_NAME = so_long_bonus

LIBFT_DIR = ./LIBFT
LIBS = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -L/usr/lib -lX11 -lXext -lm

SRCS = mandatory/src/solong.c \
       mandatory/src/component_checker.c \
       mandatory/src/utils2.c \
       mandatory/src/utils.c \
       mandatory/src/flood_fill.c \
       mandatory/src/player_mover.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS =    bonus/src/solong_bonus.c \
                bonus/src/utils2_bonus.c \
                bonus/src/utils_bonus.c \
                bonus/src/flood_fill_bonus.c \
                bonus/src/component_checker_bonus.c \
                bonus/src/enemy_killer_bonus.c \
                bonus/src/enemy_killer_helper_bonus.c \
                bonus/src/player_mover_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBS):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) $(LIBS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLXFLAGS) $(LIBS) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -f main/*.o bonus/*.o
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all