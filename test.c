/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:46:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/15 21:47:22 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_exit(t_obj *obj)
{
	ft_printf("%d mouvement .\n", obj->a++ + 1);
	mlx_destroy_window(obj->mlx_add, obj->win_add);
	mlx_destroy_display(obj->mlx_add);
	free(obj->mlx_add);
	free_array(obj->str, obj->map_lenght);
	ft_printf("you won \n");
	exit(1);
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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y][obj->player_x - 1] == 'E'
			&& obj->collectible == 0)
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
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y][obj->player_x + 1] == 'E'
			&& obj->collectible == 0)
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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y - 1][obj->player_x] == 'E'
			&& obj->collectible == 0)
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
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, "images/player.xpm",
				&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->player_x * 64, obj->player_y * 64);
		mlx_destroy_image(obj->mlx_add, obj->img_add);
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	}
	else if (obj->str[obj->player_y + 1][obj->player_x] == 'E'
			&& obj->collectible == 0)
		ft_exit(obj);
}

int	handle_key_press(int keycode, void *param)
{
	t_obj	*obj;

	obj = (t_obj *)param;
	obj->str[obj->player_y][obj->player_x] = '0';
	if (keycode == 119)
		up_walke(obj);
	else if (keycode == 97)
		left_walke(obj);
	else if (keycode == 100)
		right_walke(obj);
	else if (keycode == 115)
		down_walke(obj);
	else if (keycode == 65307)
		ft_exit(obj);
	return (0);
}
int	close_button_handler(void *object)
{
	ft_exit(object);
	return (0);
}

void	player_mover(t_obj *obj)
{
	mlx_hook(obj->win_add, 17, 0, &close_button_handler, (void *)obj);
	mlx_key_hook(obj->win_add, &handle_key_press, (void *)obj);
	mlx_loop(obj->mlx_add);
}

int	obj_checker(char c, t_obj *obj)
{
	if (c == '1')
		obj->wall++;
	if (c == '0')
		obj->space++;
	if (c == 'C')
		obj->collectible++;
	if (c == 'E')
		obj->exit++;
	if (c == 'P')
		obj->player++;
	return (0);
}

int	comp(char *str1, char *str2)
{
	static int	i;
	int			ln1;
	int			ln2;

	ln1 = ft_strlen(str1);
	ln2 = ft_strlen(str2);
	if (ft_strchr(str2, '\n') == 0)
		ln2++;
	i++;
	return (ln1 == ln2);
}
