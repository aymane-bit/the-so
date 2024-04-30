/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:49:03 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:03:48 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_obj *obj,	int i)
{
	if (i == 1)
		ft_printf("%d mouvement .\n", obj->a++ + 1);
	mlx_destroy_window(obj->mlx_add, obj->win_add);
	mlx_destroy_display(obj->mlx_add);
	free(obj->mlx_add);
	free(obj->str2);
	free_array(obj->str, obj->map_lenght);
	exit(1);
}

int	close_button_handler(void *object)
{
	ft_exit(object, 0);
	return (0);
}

void	position_exit(t_obj *obgect)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	x = 0;
	y = 0;
	while (obgect->str[y] && !found)
	{
		while (obgect->str[y][x++])
		{
			if (obgect->str[y][x] == 'E')
			{
				found = 1;
				break ;
			}
		}
		if (!found)
		{
			x = 0;
			y++;
		}
	}
	obgect->exit_x = x;
	obgect->exit_y = y;
}
