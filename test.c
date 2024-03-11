/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:45:22 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/10 18:31:22 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	left_walke(t_obj *obj)
{
	if (obj->str[obj->player_y][obj->player_x - 1] == '0'
	|| obj->str[obj->player_y][obj->player_x - 1] == 'C')
	{
		if (obj->str[obj->player_y][obj->player_x - 1] == 'C')
		{
			obj->str[obj->player_y][obj->player_x - 1] = '0';
			obj->collectible--;
		}
		obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "images/spaces.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        obj->player_x--;
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "images/player.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        ft_printf("%d mouvement .\n",obj->a++ + 1);
    }
    else if (obj->str[obj->player_y][obj->player_x - 1] == 'E' 
    && obj->collectible == 0)
      {
		ft_free(obj->str);
	    exit(1);
	  }
}
