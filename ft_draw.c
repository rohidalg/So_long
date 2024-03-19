/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/19 19:24:18 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_image(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*j) * 32,
		(*i) * 32);
}

void	floor_image(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->floor, (*j)
		* 32, (*i) * 32);
}

void	player_image(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->player, (*j)
		* 32, (*i) * 32);
	data->x = *j;
	data->y = *i;
}

void	ft_draw(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				wall_image(data, &j, &i);
			else if (data->map[i][j] == '0')
				floor_image(data, &j, &i);
			else if (data->map[i][j] == 'p')
				player_image(data, &j, &i);
			else if (data->map[i][j] == 'c')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->object, j * 32, i * 32);
			else if (data->map[i][j] == 'e')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
