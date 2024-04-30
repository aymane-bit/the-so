/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:46:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/20 23:49:19 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	else if (keycode == 32)
	{
		enemy_killer_up(obj);
		enemy_killer_down(obj);
		enemy_killer_left(obj);
		enemy_killer_right(obj);
	}
	else if (keycode == 65307)
		ft_exit(obj);
	return (0);
}

void	player_mover(t_obj *obj)
{
	mlx_hook(obj->win_add, 2, 1L << 0, &handle_key_press, (void *)obj);
	mlx_hook(obj->win_add, 17, 0, &close_button_handler, (void *)obj);
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
