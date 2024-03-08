#ifndef SOLONG_H
# define SOLONG_H

typedef struct	s_data {
	void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int img_width, img_height;
}				t_data;


typedef struct s_obj
{
	int space;
	int wall;
	int collectible;
	int collect;
	int exit;
	int player;
	int map_width;
	int map_lenght;
	int player_x;
	int player_y;
	int	x;
	int	y;
	int		i;
	int		d;
	int img_width, img_height;
	void *win_add;
	void *mlx_add;
	void *img_add;
	char **str;
}					t_obj;

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "LIBFT/libft.h"

void    player_mover(char **str,t_obj *obj,t_data *lafin);
char	**map_checker(t_obj *obgect);
int	obj_checker(char c, t_obj *obj);
int	comp(char *str1, char *str2);
char	*get_next_line(int fd);
char  **map_checker(t_obj *obgect);

#endif