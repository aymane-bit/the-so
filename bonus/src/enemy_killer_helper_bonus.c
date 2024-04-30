/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_killer_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:48:01 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/20 23:49:46 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	enemy_killer_up_helper(t_obj *obj, int d)
{
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/fire_up.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		obj->player_x * 64, (obj->player_y - d) * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		obj->player_x * 64, (obj->player_y - d) * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	usleep(40000);
}

void	enemy_killer_down_helper(t_obj *obj, int d)
{
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/fire_up.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		obj->player_x * 64, (obj->player_y + d) * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		obj->player_x * 64, (obj->player_y + d) * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	usleep(40000);
}

void	enemy_killer_right_helper(t_obj *obj, int d)
{
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/fire.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		(obj->player_x + d) * 64, obj->player_y * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		(obj->player_x + d) * 64, obj->player_y * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	usleep(40000);
}

void	enemy_killer_left_helper(t_obj *obj, int d)
{
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/fire.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		(obj->player_x - d) * 64, obj->player_y * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/spaces.xpm",
			&obj->img_width, &obj->img_height);
	mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		(obj->player_x - d) * 64, obj->player_y * 64);
	mlx_destroy_image(obj->mlx_add, obj->img_add);
	usleep(40000);
}
