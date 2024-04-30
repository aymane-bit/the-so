/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:51:43 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/20 23:49:38 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_door(t_obj *obj)
{
	char	*num;

	num = ft_itoa(obj->a++ + 1);
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/leftup.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add, 0, 0);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	mlx_string_put(obj->mlx_add, obj->win_add, 30, 40, 0xFFFFFF, num);
	if (obj->collectible == 0)
	{
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
				"images/open_exit.xpm", &obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->exit_x * 64, obj->exit_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
	}
	free(num);
}

void	left_walke(t_obj *obj)
{
	if (obj->str[obj->player_y][obj->player_x - 1] == '0'
		|| obj->str[obj->player_y][obj->player_x - 1] == 'C')
	{
		if (obj->str[obj->player_y][obj->player_x - 1] == 'C')
		{
			obj->str[obj->player_y][obj->player_x - 1] = '0';
			obj->collectible--;
		}
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		obj->player_x--;
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
				"images/left_walk.xpm", &obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_door(obj);
	}
	else if ((obj->str[obj->player_y][obj->player_x - 1] == 'E'
		&& obj->collectible == 0)
			|| obj->str[obj->player_y][obj->player_x - 1] == 'X')
		ft_exit(obj);
}

void	right_walke(t_obj *obj)
{
	if (obj->str[obj->player_y][obj->player_x + 1] == '0'
		|| obj->str[obj->player_y][obj->player_x + 1] == 'C')
	{
		if (obj->str[obj->player_y][obj->player_x + 1] == 'C')
		{
			obj->str[obj->player_y][obj->player_x + 1] = '0';
			obj->collectible--;
		}
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		obj->player_x++;
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_door(obj);
	}
	else if ((obj->str[obj->player_y][obj->player_x + 1] == 'E'
		&& obj->collectible == 0)
			|| obj->str[obj->player_y][obj->player_x + 1] == 'X')
		ft_exit(obj);
}

void	up_walke(t_obj *obj)
{
	if (obj->str[obj->player_y - 1][obj->player_x] == '0'
		|| obj->str[obj->player_y - 1][obj->player_x] == 'C')
	{
		if (obj->str[obj->player_y - 1][obj->player_x] == 'C')
		{
			obj->str[obj->player_y - 1][obj->player_x] = '0';
			obj->collectible--;
		}
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		obj->player_y--;
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/up_walk.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_door(obj);
	}
	else if ((obj->str[obj->player_y - 1][obj->player_x] == 'E'
		&& obj->collectible == 0) || obj->str[obj->player_y
			- 1][obj->player_x] == 'X')
		ft_exit(obj);
}

void	down_walke(t_obj *obj)
{
	if (obj->str[obj->player_y + 1][obj->player_x] == '0'
		|| obj->str[obj->player_y + 1][obj->player_x] == 'C')
	{
		if (obj->str[obj->player_y + 1][obj->player_x] == 'C')
		{
			obj->str[obj->player_y + 1][obj->player_x] = '0';
			obj->collectible--;
		}
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		obj->player_y++;
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add,
				"images/down_walk.xpm", &obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_door(obj);
	}
	else if ((obj->str[obj->player_y + 1][obj->player_x] == 'E'
		&& obj->collectible == 0) || obj->str[obj->player_y
			+ 1][obj->player_x] == 'X')
		ft_exit(obj);
}
