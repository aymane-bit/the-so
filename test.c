/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:08:33 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/08 05:52:53 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	**map_checker(t_obj *obgect)
{
	char	*str1;
	int		fd;
	char	*str2;

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
	if (component_checker(str2, obgect) == 1)
	{
		printf("ERROR : the map is not valid");
		exit(1);
	}
	return (ft_split(str2, '\n'));
}
