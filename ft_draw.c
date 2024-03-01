/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/01 18:51:31 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void wall_image(t_map *data, int *i, int *j)
{
    mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*i) * 40, (*j) * 40);
}

void floor_image(t_map *data, int *i, int *j)
{
    mlx_put_image_to_window(data->mlx, data->win, data->images->floor, (*i) * 40, (*j) * 40);
}

void player_image(t_map *data, int *i, int *j)
{
    mlx_put_image_to_window(data->mlx, data->win, data->images->player, (*i) * 40, (*j) * 40);
    data->x = *i;
    data->y = *j;
}

void ft_draw()
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(data->map[i])
    {
        while()
        {
            if (i == 1)
                wall.xpm;
            else if (i == 0)
                floor.xpm;
            else if (i == p)
                character.xpm;
            else if (i == c)
                object.xpm;
            else if (i == e)
                exit.xpm;
            i++;
        }
        j++;
    }
}
