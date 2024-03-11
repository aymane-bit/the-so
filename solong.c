/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:26:20 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/11 13:14:45 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*map_drawer(char **str, int d, int i, t_obj *obj)
{
	if (str[d][i] == '1' && i == 0 && d == obj->map_lenght - 1)
		return ("images/leftdown.xpm");
	else if (str[d][i] == '1' && i == obj->map_width - 1 && d == obj->map_lenght
			- 1)
		return ("images/rightdown.xpm");
	else if (str[d][i] == '1' && i == obj->map_width - 1 && d == 0)
		return ("images/rightup.xpm");
	else if (str[d][i] == '1' && i == 0 && d == 0)
		return ("images/leftup.xpm");
	else if (str[d][i] == '1' && d == 0)
		return ("images/slepborder.xpm");
	else if (str[d][i] == '1' && d == obj->map_lenght - 1)
		return ("images/slepborder.xpm");
	else if (str[d][i] == '1' && (i == 0 || i == obj->map_width - 1))
		return ("images/borderwallup.xpm");
	else if (str[d][i] == '1')
		return ("images/wall.xpm");
	else if (str[d][i] == '0')
		return ("images/spaces.xpm");
	else if (str[d][i] == 'C')
		return ("images/collect.xpm");
	else if (str[d][i] == 'P')
		return ("images/player.xpm");
	return ("images/exit.xpm");
}

void	visual_start(char **str, t_obj *obj)
{
	t_data	lafin;
	char	*pic;

	lafin.mlx_ptr = mlx_init();
	lafin.win_ptr = mlx_new_window(lafin.mlx_ptr, obj->map_width * 64,
			obj->map_lenght * 64, "MiniLibX Example");
	while (str[obj->d])
	{
		while (str[obj->d][obj->i])
		{
			pic = map_drawer(str, obj->d, obj->i, obj);
			lafin.img_ptr = mlx_xpm_file_to_image(lafin.mlx_ptr, pic,
					&lafin.img_width, &lafin.img_height);
			mlx_put_image_to_window(lafin.mlx_ptr, lafin.win_ptr, lafin.img_ptr,
				obj->i * 64, obj->d * 64);
			obj->i++;
		}
		obj->i = 0;
		obj->d++;
	}
	player_mover(str, obj, &lafin);
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
	t_data	data;
	t_obj	object;

	ft_memset(&object, 0, sizeof(object));
	if (argc == 2)
	{
		if (ber_checker(argv[1]) == 1)
			return (ft_printf("ERROR : the extension is not .ber\n"));
		// exit(1);
		object.str = map_checker(&object);
		position_player(&object);
		visual_start(object.str, &object);
	}
	else
		return (ft_printf("ERROR : check the format [<./solong> <map>]"), 0);
}
