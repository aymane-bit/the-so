/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:26:20 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:03:38 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*map_drawer(int d, int i, t_obj *obj)
{
	if (obj->str[d][i] == '1' && i == 0 && d == obj->map_lenght - 1)
		return ("images/leftdown.xpm");
	else if (obj->str[d][i] == '1' && i == obj->map_width - 1
			&& d == obj->map_lenght - 1)
		return ("images/rightdown.xpm");
	else if (obj->str[d][i] == '1' && i == obj->map_width - 1 && d == 0)
		return ("images/rightup.xpm");
	else if (obj->str[d][i] == '1' && i == 0 && d == 0)
		return ("images/leftup.xpm");
	else if (obj->str[d][i] == '1' && d == 0)
		return ("images/slepborder.xpm");
	else if (obj->str[d][i] == '1' && d == obj->map_lenght - 1)
		return ("images/slepborder.xpm");
	else if (obj->str[d][i] == '1' && (i == 0 || i == obj->map_width - 1))
		return ("images/borderwallup.xpm");
	else if (obj->str[d][i] == '1')
		return ("images/wall.xpm");
	else if (obj->str[d][i] == '0')
		return ("images/spaces.xpm");
	else if (obj->str[d][i] == 'C')
		return ("images/collect.xpm");
	else if (obj->str[d][i] == 'P')
		return ("images/player.xpm");
	return ("images/exit.xpm");
}

void	visual_start(t_obj *obj)
{
	char	*pic;

	obj->mlx_add = mlx_init();
	obj->win_add = mlx_new_window(obj->mlx_add, obj->map_width * 64,
			obj->map_lenght * 64, "SO_LONG");
	while (obj->str[obj->d])
	{
		while (obj->str[obj->d][obj->i])
		{
			pic = map_drawer(obj->d, obj->i, obj);
			obj->img_add = mlx_xpm_file_to_image(obj->mlx_add, pic,
					&obj->img_width, &obj->img_height);
			mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
				obj->i * 64, obj->d * 64);
			mlx_destroy_image(obj->mlx_add, obj->img_add);
			obj->i++;
		}
		obj->i = 0;
		obj->d++;
	}
	player_mover(obj);
}

void	position_player(t_obj *obgect)
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
			if (obgect->str[y][x] == 'P')
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
	obgect->player_x = x;
	obgect->player_y = y;
}

int	ber_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i--] != 'r')
		return (1);
	if (str[i--] != 'e')
		return (1);
	if (str[i--] != 'b')
		return (1);
	if (str[i--] != '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_obj	object;

	ft_memset(&object, 0, sizeof(object));
	object.filename = argv[1];
	if (argc == 2)
	{
		if (ber_checker(argv[1]) == 1)
			return (ft_printf("ERROR : the extension is not .ber\n"));
		map_checker(&object);
		position_player(&object);
		position_exit(&object);
		flood_fill(&object);
		visual_start(&object);
	}
	else
		return (ft_printf("ERROR : check the format [<./solong> <map>]"), 0);
}
