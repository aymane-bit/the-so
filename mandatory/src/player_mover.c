/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:51:43 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:03:31 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y][obj->player_x - 1] == 'E'
			&& obj->collectible == 0)
		ft_exit(obj, 1);
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
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y][obj->player_x + 1] == 'E'
			&& obj->collectible == 0)
		ft_exit(obj, 1);
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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y - 1][obj->player_x] == 'E'
			&& obj->collectible == 0)
		ft_exit(obj, 1);
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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
			obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y + 1][obj->player_x] == 'E'
			&& obj->collectible == 0)
		ft_exit(obj, 1);
}
