/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:46:47 by akajjou           #+#    #+#             */
/*   Updated: 2024/03/08 12:50:58 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void    left_walke(t_obj *obj)
{
    if (obj->str[obj->player_y][obj->player_x - 1] == '0'
    || obj->str[obj->player_y][obj->player_x - 1] == 'C')
    {
        if (obj->str[obj->player_y][obj->player_x - 1] == 'C')
        {
            obj->str[obj->player_y][obj->player_x - 1] = '0';
            obj->collectible--;
        }
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "spaces.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        obj->player_x--;
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "player.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
    }
    else if (obj->str[obj->player_y][obj->player_x - 1] == 'E' 
    && obj->collectible == 0)
        exit(1);
        
}

void    right_walke(t_obj *obj)
{
    if (obj->str[obj->player_y][obj->player_x + 1] == '0' 
    || obj->str[obj->player_y][obj->player_x + 1] == 'C')
    {
        if (obj->str[obj->player_y][obj->player_x + 1] == 'C')
        {
            obj->str[obj->player_y][obj->player_x + 1] = '0';
            obj->collectible--;
        }
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "spaces.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        obj->player_x++;
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "player.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
    }
    else if (obj->str[obj->player_y ][obj->player_x + 1] == 'E' 
    && obj->collectible == 0)
        exit(1);
}
void    up_walke(t_obj *obj)
{
    if (obj->str[obj->player_y - 1][obj->player_x] == '0'
    || obj->str[obj->player_y - 1][obj->player_x] == 'C')
    {
        if (obj->str[obj->player_y - 1][obj->player_x] == 'C')
        {
            obj->str[obj->player_y - 1][obj->player_x] = '0';
            obj->collectible--;
        }
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "spaces.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        obj->player_y--;
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "player.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
    }
    else if (obj->str[obj->player_y - 1][obj->player_x] == 'E' 
    && obj->collectible == 0)
        exit(1);
}
void    down_walke(t_obj *obj)
{
    if (obj->str[obj->player_y + 1][obj->player_x] == '0'
    || obj->str[obj->player_y + 1][obj->player_x] == 'C')
    {
        if (obj->str[obj->player_y + 1][obj->player_x] == 'C')
        {
            obj->str[obj->player_y + 1][obj->player_x] = '0';
            obj->collectible--;
        }
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "spaces.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
        obj->player_y++;
        obj->img_add = mlx_xpm_file_to_image(obj->mlx_add , "player.xpm",
					&obj->img_width, &obj->img_height);
		mlx_put_image_to_window(obj->mlx_add, obj->win_add, obj->img_add,
		    		obj->player_x * 64, obj->player_y * 64);
    }
    else if (obj->str[obj->player_y + 1][obj->player_x] == 'E' 
    && obj->collectible == 0)
        exit(1);
}

int handle_key_press(int keycode, void *param)
{
    t_obj *obj;
    obj = (t_obj *)param;
    obj->str[obj->player_y][obj->player_x] = '0';
    if (keycode == 119)
        up_walke(obj);
    else if (keycode == 97)
        left_walke(obj);
    else if (keycode == 100)
        right_walke(obj);
    else if (keycode == 115)
        down_walke(obj);
    
    return (0);       
}

void    player_mover(char **str,t_obj *obj,t_data *lafin)
{
    obj->win_add = lafin->win_ptr;
    obj->mlx_add = lafin->mlx_ptr;
    obj->img_add = lafin->img_ptr;
    mlx_key_hook(lafin->win_ptr, &handle_key_press, (void *)obj);
    mlx_loop(lafin->mlx_ptr);
}

int	obj_checker(char c, t_obj *obj)
{
	if (c == '1')
		obj->wall++;
	if (c == '0')
		obj->space++;
	if (c == 'C')
		obj->collectible++;
	if (c == 'E')
		obj->exit++;
	if (c == 'P')
		obj->player++;
	return (0);
}

int	comp(char *str1, char *str2)
{
	static int	i;
	int			ln1;
	int			ln2;

	ln1 = ft_strlen(str1);
	ln2 = ft_strlen(str2);
	if (ft_strchr(str2, '\n') == 0)
		ln2++;
	i++;
	return (ln1 == ln2);
}
