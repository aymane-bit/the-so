/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:00:19 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/15 22:01:37 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "LIBFT/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		img_width;
	int		img_height;
}			t_data;

typedef struct s_ints
{
	int		i;
	int		x;
	int		p;
}			t_ints;

typedef struct s_obj
{
	int		a;
	int		space;
	int		wall;
	int		collectible;
	int		collect;
	int		exit;
	int		player;
	int		map_width;
	int		map_lenght;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
	int		i;
	int		d;
	int		img_width;
	int		img_height;
	void	*win_add;
	void	*mlx_add;
	void	*img_add;
	char	*str2;
	char	**str;
}			t_obj;

void		left_walke(t_obj *obj);
void		right_walke(t_obj *obj);
void		up_walke(t_obj *obj);
void		down_walke(t_obj *obj);
int			ft_exit(t_obj *obj);
int			close_button_handler(void *object);
int			ft_strschr(char **str, char c);
void		flood_fill(t_obj *obgect);
int			ft_exit(t_obj *obj);
char		**free_array(char **ptr, int i);
void		ft_free(char **str);
void		player_mover(t_obj *obj);
int			map_checker(t_obj *obgect);
int			obj_checker(char c, t_obj *obj);
int			comp(char *str1, char *str2);
char		*get_next_line(int fd);

#endif