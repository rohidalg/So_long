/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:08:22 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/17 17:06:51 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_frame_left(t_map *data, int *j, int *i)
{
         if (data->frame <= 16)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa4, (*j) * 60, (*i) * 60);
        else if (data->frame <= 24)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa5, (*j) * 60, (*i) * 60);
        else if (data->frame <= 32)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa6, (*j) * 60, (*i) * 60);
        else if (data->frame <= 59)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa7, (*j) * 60, (*i) * 60);
        else if (data->frame > 59)
        {  
            data->frame = 0;
	        ft_reset_dir(data);
            ft_stopp(data, j, i);
        }
}

void ft_frame_right(t_map *data, int *j, int *i)
{
         if (data->frame <= 16)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd4, (*j) * 60, (*i) * 60);
        else if (data->frame <= 24)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd5, (*j) * 60, (*i) * 60);
        else if (data->frame <= 32)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd6, (*j) * 60, (*i) * 60);
        else if (data->frame <= 59)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd7, (*j) * 60, (*i) * 60);
        else if (data->frame > 59)
        {  
            data->frame = 0;
	        ft_reset_dir(data);
            ft_stopp(data, j, i);
        }
}

void ft_stopp(t_map *data, int *j, int *i)
{
	if (data->frame <= 34)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm1, (*j) * 60, (*i) * 60);
	else if (data->frame <= 40)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm2, (*j) * 60, (*i) * 60);
	else if (data->frame <= 48)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm3, (*j) * 60, (*i) * 60);
	else if (data->frame > 48)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm4, (*j) * 60, (*i) * 60);
}
 
void ft_spritep(t_map *data, int *j, int *i)
{
    if (data->right == 1)
        ft_frame_right(data,j,i);
    else if (data->left == 1)
        ft_frame_left(data,j,i);
    else 
        ft_stopp(data, j, i);
}
