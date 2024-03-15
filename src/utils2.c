/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:49:03 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/15 21:57:14 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_exit(t_obj *obj)
{
	ft_printf("%d mouvement .\n", obj->a++ + 1);
	mlx_destroy_window(obj->mlx_add, obj->win_add);
	mlx_destroy_display(obj->mlx_add);
	free(obj->mlx_add);
	free_array(obj->str, obj->map_lenght);
	ft_printf("you won \n");
	exit(1);
}

int	close_button_handler(void *object)
{
	ft_exit(object);
	return (0);
}
