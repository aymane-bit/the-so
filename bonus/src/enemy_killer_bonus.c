/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_killer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:12:50 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/20 23:49:52 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	enemy_killer_left(t_obj *obj)
{
	int	i;
	int	d;

	i = 1;
	d = 1;
	while (obj->str[obj->player_y][obj->player_x - i] != '1'
		&& obj->str[obj->player_y][obj->player_x - i] != 'C'
		&& obj->str[obj->player_y][obj->player_x - i] != 'E')
	{
		if (obj->str[obj->player_y][obj->player_x - i] == 'X')
		{
			while (i-- != 1)
				enemy_killer_left_helper(obj, d++);
			obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
					"images/spaces.xpm", &obj->img_width, &obj->img_height);
			mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				(obj->player_x - d) * 64, obj->player_y * 64);
			mlx_destroy_image(obj->mlx_add, obj->img_add);
			obj->str[obj->player_y][obj->player_x - d] = '0';
			break ;
		}
		i++;
	}
}

void	enemy_killer_right(t_obj *obj)
{
	int	i;
	int	d;

	i = 1;
	d = 1;
	while (obj->str[obj->player_y][obj->player_x + i] != '1'
		&& obj->str[obj->player_y][obj->player_x + i] != 'C'
		&& obj->str[obj->player_y][obj->player_x + i] != 'E')
	{
		if (obj->str[obj->player_y][obj->player_x + i] == 'X')
		{
			while (i-- != 1)
				enemy_killer_right_helper(obj, d++);
			obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
					"images/spaces.xpm", &obj->img_width, &obj->img_height);
			mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				(obj->player_x + d) * 64, obj->player_y * 64);
			mlx_destroy_image(obj->mlx_add, obj->img_add);
			obj->str[obj->player_y][obj->player_x + d] = '0';
			break ;
		}
		i++;
	}
}

void	enemy_killer_up(t_obj *obj)
{
	int	i;
	int	d;

	i = 1;
	d = 1;
	while (obj->str[obj->player_y - i][obj->player_x] != '1'
		&& obj->str[obj->player_y - i][obj->player_x] != 'C'
		&& obj->str[obj->player_y - i][obj->player_x] != 'E')
	{
		if (obj->str[obj->player_y - i][obj->player_x] == 'X')
		{
			while (i-- != 1)
				enemy_killer_up_helper(obj, d++);
			obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
					"images/spaces.xpm", &obj->img_width, &obj->img_height);
			mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->player_x * 64, (obj->player_y - d) * 64);
			obj->str[obj->player_y - d][obj->player_x] = '0';
			mlx_destroy_image(obj->mlx_add, obj->img_add);
			break ;
		}
		i++;
	}
}

void	enemy_killer_down(t_obj *obj)
{
	int	i;
	int	d;

	i = 1;
	d = 1;
	while (obj->str[obj->player_y + i][obj->player_x] != '1'
		&& obj->str[obj->player_y + i][obj->player_x] != 'C'
		&& obj->str[obj->player_y + i][obj->player_x] != 'E')
	{
		if (obj->str[obj->player_y + i][obj->player_x] == 'X')
		{
			while (i-- != 1)
				enemy_killer_down_helper(obj, d++);
			obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
					"images/spaces.xpm", &obj->img_width, &obj->img_height);
			mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->player_x * 64, (obj->player_y + d) * 64);
			mlx_destroy_image(obj->mlx_add, obj->img_add);
			obj->str[obj->player_y + d][obj->player_x] = '0';
			break ;
		}
		i++;
	}
}
