/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:45:19 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/21 00:03:23 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	border_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (free(str), 1);
		i++;
	}
	i = 0;
	while (str[++i])
	{
		if (str[i] == '\n' && (str[i + 1] != '1' || str[i - 1] != '1'))
			return (free(str), 1);
	}
	if (str[i - 1] != '1')
		return (free(str), 1);
	while (str[--i] != '\n')
		if (str[i] != '1')
			return (free(str), 1);
	return (0);
}

int	map_linechecker(char *str1, t_obj *obj)
{
	char	**str;
	int		i;
	int		a;
	int		d;

	if (str1[0] == '\n')
		return (1);
	str = ft_split(str1, '\n');
	i = 1;
	d = ft_strlen(str[0]) - 1;
	while (str[i])
	{
		a = 0;
		while (str[i][a])
		{
			if (str[i][a + 1] == '\0' && d != a)
				return (free_array(str, obj->map_lenght), 1);
			a++;
		}
		i++;
	}
	return (free_array(str, i), 0);
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
	size_t	i;

	i = 0;
	while ((str[i] == '1' || str[i] == '0' || str[i] == 'E' || str[i] == 'C'
			|| str[i] == 'P' || str[i] == '\n') && str[i])
	{
		obj_checker(str[i], obj);
		i++;
	}
	if (obj->exit != 1 || obj->player != 1 || obj->collectible == 0)
	{
		free(str);
		ft_printf("ERROR : the map is not valid (check the P or C or the E)\n");
		exit(1);
	}
	if (rectangular_checker(str, obj) == 1 || map_linechecker(str, obj) == 1)
		return (free(str), 1);
	if (border_checker(str) == 1)
	{
		ft_printf("ERROR : the map is not valid (check the border)\n");
		exit(1);
	}
	if (i == ft_strlen(str) && str[i - 1] != '\n')
		return (0);
	return (free(str), 1);
}

int	map_checker(t_obj *obgect)
{
	char	*str1;
	int		fd;
	char	*str2;
	char	*tmp;

	str2 = 0;
	fd = open(obgect->filename, O_RDWR);
	str1 = get_next_line(fd);
	if (!str1)
		exit(1);
	while (str1)
	{
		tmp = ft_strjoin(str2, str1);
		free(str2);
		str2 = tmp;
		free(str1);
		str1 = get_next_line(fd);
	}
	if (component_checker(str2, obgect) == 1)
	{
		ft_printf("ERROR : the map is not valid");
		exit(1);
	}
	obgect->str = ft_split(str2, '\n');
	return (obgect->str2 = str2, 0);
}
