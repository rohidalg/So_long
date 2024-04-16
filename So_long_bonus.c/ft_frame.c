/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:08:22 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/16 20:55:58 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_frame_left(t_map *data, int *j, int *i)
{
    int init;

    init = -1;
    while(++init < 1)
    {
        if (data->frame <= 6)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa1, (*j) * 60, (*i) * 60);
        else if (data->frame <= 10)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa2, (*j) * 60, (*i) * 60);
        else if (data->frame <= 14)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa3, (*j) * 60, (*i) * 60);
        else if (data->frame <= 18)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa4, (*j) * 60, (*i) * 60);
        else if (data->frame <= 22)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa5, (*j) * 60, (*i) * 60);
        else if (data->frame <= 26)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa6, (*j) * 60, (*i) * 60);
        else if (data->frame <= 30)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pa7, (*j) * 60, (*i) * 60);
    }
}

void ft_frame_right(t_map *data, int *j, int *i)
{
    int init;

    init = -1;
    while(++init < 1)
    {
        if (data->frame <= 6)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd1, (*j) * 60, (*i) * 60);
        else if (data->frame <= 10)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd2, (*j) * 60, (*i) * 60);
        else if (data->frame <= 14)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd3, (*j) * 60, (*i) * 60);
        else if (data->frame <= 18)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd4, (*j) * 60, (*i) * 60);
        else if (data->frame <= 22)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd5, (*j) * 60, (*i) * 60);
        else if (data->frame <= 26)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd6, (*j) * 60, (*i) * 60);
        else if (data->frame <= 30)
            mlx_put_image_to_window(data->mlx, data->win, data->images->pd7, (*j) * 60, (*i) * 60);
    }
}

void ft_stopp(t_map *data, int *j, int *i)
{
	if (data->frame <= 34)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm1, (*j) * 60, (*i) * 60);
	else if (data->frame <= 38)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm2, (*j) * 60, (*i) * 60);
	else if (data->frame <= 42)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm3, (*j) * 60, (*i) * 60);
	else if (data->frame > 42)
		mlx_put_image_to_window(data->mlx, data->win, data->images->pm4, (*j) * 60, (*i) * 60);
}
 
void ft_spritep(t_map *data, int *j, int *i)
{
	// if ()
	ft_stopp(data, j, i);
}
