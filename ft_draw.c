/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:44 by rohidalg         ###   ########.fr       */
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

void ft_draw(t_map *data)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(data->map[i])
    {
        while(data->map[i][j])
        {
            if (data->map[i][j] == '1')
                wall_image(data, &i, &j);
            else if (data->map[i][j] == '0')
                floor_image(data, &i, &j);
            else if (data->map[i][j] == 'p')
                player_image(data, &i, &j);
            else if (data->map[i][j] == 'c')
                mlx_put_image_to_window(data->mlx, data->win, data->images->object, i * 40, j * 40);
            else if (data->map[i][j] == 'e')
                mlx_put_image_to_window(data->mlx, data->win, data->images->exit, i * 40, j * 40);
            i++;
        }
        j++;
    }
}
