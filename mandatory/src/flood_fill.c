/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:45:42 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:03:27 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood(char **map, int x, int y, t_obj *obj)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	if (x == obj->exit_x && y == obj->exit_y)
		return ;
	flood(map, x + 1, y, obj);
	flood(map, x - 1, y, obj);
	flood(map, x, y + 1, obj);
	flood(map, x, y - 1, obj);
}

void	flood_fill(t_obj *obj)
{
	char	**tmp;
	int		i;
	int		d;

	d = 0;
	tmp = ft_split(obj->str2, '\n');
	flood(tmp, obj->player_x, obj->player_y, obj);
	while (tmp[d])
	{
		i = 0;
		while (tmp[d][i])
		{
			if (tmp[d][i] == 'E' || tmp[d][i] == 'C')
			{
				ft_printf("ERROR : tha map is not valid (! acces)\n");
				free_array(tmp, obj->map_lenght);
				free_array(obj->str, obj->map_lenght);
				free(obj->str2);
				exit(1);
			}
			i++;
		}
		d++;
	}
	free_array(tmp, obj->map_lenght);
}
