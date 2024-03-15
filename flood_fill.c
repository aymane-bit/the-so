/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:45:42 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/15 17:07:49 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../solong.h"

int map_p(char *str)
{
	int i = 0;
	while (str[i] != 'P')
		i++;
	return i;
}


int	filler(t_ints *vars, char *map)
{
	int stat;
	int	arr[4];
	int	i;

	i = 0;
	arr[0] = vars->i + 1;
	arr[1] = vars->i - 1;
	arr[2] = vars->i - (vars->x + 1);
	arr[3] = vars->i + (vars->x + 1);
	while (i <= 3)
	{
		if (map[arr[i]] == '0' || map[arr[i]] == 'C')
		{
			map[arr[i]] = 'S';
			stat = 1;
		}
		i++;
	}
	return (stat);
}

int	filler2(t_ints *vars, char *map)
{
	int stat;
	int	arr[4];
	int	i;

	i = 0;
	arr[0] = vars->i + 1;
	arr[1] = vars->i - 1;
	arr[2] = vars->i - (vars->x + 1);
	arr[3] = vars->i + (vars->x + 1);
	while (i <= 3)
	{
		if (map[arr[i]] == '0' || map[arr[i]] == 'C'
			|| map[arr[i]] == 'E')
		{
			map[arr[i]] = 'S';
			stat = 1;
		}
		i++;
	}
	return (stat);
}
void	checker_4(char *map)
{
	int	r;
	t_ints vars;

	vars.x = 13;
	vars.p = map_p(map);
	vars.i = vars.p;
	filler(&vars, map);
	while (1)
	{
		vars.i = 0;
		r = 0;
		while (map[vars.i])
		{
			if (map[vars.i] == 'S')
				r += filler(&vars, map);
			vars.i++;
		}
		if (r == 0)
			break ;
	}
	if (!ft_strchr(map, 'C'))
		return ;
	
		// ft_printf();
	exit (0);
}




/*
void prt(char **str)
{
	int i = 0;
	int d = 0;
	while (str[d])
	{
		ft_printf("%s\n",str[d]);
	d++;	
	}	

}

int	helper(t_obj *obj)
{
	static int l;
	int stat;
	int i;
	int x[4];
	int y[4];
	
	i = 0;
	stat = 0;
	x[0] = obj->player_x + 1;
	y[0] = obj->player_y;
	x[1] = obj->player_x - 1;
	y[1] = obj->player_y;
	x[2] = obj->player_x;
	y[2] = obj->player_y - 1;
	x[3] = obj->player_x;
	y[3] = obj->player_y + 1;
	while (i <= 3)
	{
		ft_printf(" p_x = %d\n p_y = %d\n----\n",obj->player_x,obj->player_y);
		ft_printf("d_x = %d\n d_y = %d\n",x[i],y[i]);
		if (obj->str[y[i]][x[i]] == 'C' || obj->str[y[i]][x[i]] == '0')
		{
			obj->str[y[i]][x[i]] = 'W';
			stat = 1;
		}
		i++;
	}
	ft_printf("at cal n = %d stat = %d\n",l, stat);
	l++;
	return (stat);
}

void flood_fill(t_obj *obj)
{
	int dm;
	int y;
	int x;

	x = 0;
	y = 0;
	dm = 0;
	helper(obj);
	while (1)
	{
		dm = 0;
		while (obj->str[y])
		{
			x = 0;
			while (obj->str[y][x])
			{
				if (obj->str[y][x] == 'W')
				{
					obj->player_x = x;
					obj->player_y = y;
					dm += helper(obj);
				}
				x++;
			}
		y++;
		}
					ft_printf("%d\n",dm);
		if (dm == 0)
			break;
	}
	prt(obj->str);
	// ft_printf("asdggdsfhdfhs\n");
	if (!ft_strschr(obj->str, 'C') || !ft_strschr(obj->str, 'E'))
	{
	obj->str = ft_split(obj->str2,'\n');
	return;
	}
	
	ft_printf("ex\n");
	exit (1);
}*/



