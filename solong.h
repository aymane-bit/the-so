#ifndef SOLONG_H
# define SOLONG_H



typedef struct s_obj
{
	int space;
	int wall;
	int collectible;
	int exit;
	int player;
}					t_obj;

// # include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "LIBFT/libft.h"

char	*get_next_line(int fd);
int map_checker(t_obj *obgect);

#endif