/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:49:03 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/20 23:49:15 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_exit(t_obj *obj)
{
	mlx_destroy_window(obj->mlx_add, obj->win_add);
	mlx_destroy_display(obj->mlx_add);
	free(obj->mlx_add);
	free(obj->str2);
	free_array(obj->str, obj->map_lenght);
	exit(1);
}

int	close_button_handler(void *object)
{
	ft_exit(object);
	return (0);
}

int	map_right_down(int d, int i, t_obj *obj)
{
	if (obj->str[d][i] == '1' && i == obj->map_width - 1 && d == obj->map_lenght
		- 1)
		return (0);
	else
		return (1);
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
