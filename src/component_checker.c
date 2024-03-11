/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:45:19 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/11 13:12:49 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	border_checker(char *str)
{
	int		fd;
	char	*str2;
	int		i;

	i = 0;
	fd = open("maps/map.ber", O_RDWR);
	str2 = get_next_line(fd);
	while (str2[i] != '\n')
	{
		if (str2[i] != '1')
			return (free(str2), free(str), 1);
		i++;
	}
	i = 0;
	while (str[++i])
	{
		if (str[i] == '\n' && (str[i + 1] != '1' || str[i - 1] != '1'))
			return (free(str2), free(str), 1);
	}
	if (str[i - 1] != '1')
		return (free(str2), free(str), 1);
	while (str[--i] != '\n')
		if (str[i] != '1')
			return (free(str2), free(str), 1);
	return (free(str2), 0);
}

int	map_linechecker(void)
{
	char	*str1;
	char	*str2;
	int		fd;
	int		i;

	fd = open("maps/map.ber", O_RDWR);
	str1 = get_next_line(fd);
	str2 = get_next_line(fd);
	i = ft_strlen(str1) - 1;
	while (str2)
	{
		if (!comp(str1, str2))
		{
			ft_printf("ERROR : map is not valid (the line are not equal)\n");
			return (free(str1), free(str2), 1);
		}
		if (str2[i] != '\n')
			break ;
		free(str2);
		str2 = get_next_line(fd);
	}
	return (free(str1), free(str2), 0);
}

int	rectangular_checker(char *str, t_obj *obj)
{
	int	map_lenght;
	int	map_width;
	int	i;

	i = 0;
	map_width = 0;
	map_lenght = 0;
	while (str[map_width] != '\n')
		map_width++;
	while (str[i])
	{
		if (str[i] == '\n')
			map_lenght++;
		i++;
	}
	if (map_width == map_lenght + 1)
	{
		printf("ERROR : the map must be rectangular\n");
		return (1);
	}
	obj->map_lenght = map_lenght + 1;
	obj->map_width = map_width;
	return (0);
}

int	component_checker(char *str, t_obj *obj)
{
	int	i;

	i = 0;
	while ((str[i] == '1' || str[i] == '0' || str[i] == 'E' || str[i] == 'C'
			|| str[i] == 'P' || str[i] == '\n') && str[i])
	{
		obj_checker(str[i], obj);
		i++;
	}
	if (obj->exit != 1 || obj->player != 1 || obj->collectible == 0)
	{
		ft_printf("ERROR : the map is not valid (check the P or C or the E)\n");
		exit(1);
	}
	if (rectangular_checker(str, obj) == 1 || map_linechecker() == 1)
		exit(1);
	if (border_checker(str) == 1)
	{
		ft_printf("ERROR : the map is not valid (check the border)\n");
		exit(1);
	}
	if (i == ft_strlen(str) && str[i - 1] != '\n')
		return (0);
	else
		return (1);
}

char	**map_checker(t_obj *obgect)
{
	char	*str1;
	int		fd;
	char	*str2;

	str2 = NULL;
	str2 = 0;
	fd = open("maps/map.ber", O_RDWR);
	str1 = get_next_line(fd);
	while (str1)
	{
		str2 = ft_strjoin(str2, str1);
		free(str1);
		str1 = get_next_line(fd);
	}
	free(str1);
	// free(str2);
		// exit(1);
	if (component_checker(str2, obgect) == 1)
	{
		ft_printf("ERROR : the map is not valid");
	}
	return (ft_split(str2, '\n'));
}
