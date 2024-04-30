/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:00:19 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:04:51 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../LIBFT/libft.h"
# include <mlx.h>
# include <unistd.h>

typedef struct s_obj
{
	int		a;
	char	*filename;
	int		space;
	int		wall;
	int		collectible;
	int		collect;
	int		exit;
	int		player;
	int		exit_x;
	int		exit_y;
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

void		position_exit(t_obj *obgect);
void		flood_fill(t_obj *obj);
void		left_walke(t_obj *obj);
void		right_walke(t_obj *obj);
void		up_walke(t_obj *obj);
void		down_walke(t_obj *obj);
int			ft_exit(t_obj *obj, int i);
int			close_button_handler(void *object);
int			ft_strschr(char **str, char c);
void		flood_fill(t_obj *obgect);
char		**free_array(char **ptr, int i);
void		ft_free(char **str);
void		player_mover(t_obj *obj);
int			map_checker(t_obj *obgect);
int			obj_checker(char c, t_obj *obj);
int			comp(char *str1, char *str2);
char		*get_next_line(int fd);

#endif
