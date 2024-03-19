/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/19 18:28:03 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_image(t_map *data, int *i, int *j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*i) * 32,
		(*j) * 32);
}

void	floor_image(t_map *data, int *i, int *j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->floor, (*i)
		* 32, (*j) * 32);
}

void	player_image(t_map *data, int *i, int *j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->player, (*i)
		* 32, (*j) * 32);
	data->x = *i;
	data->y = *j;
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
				wall_image(data, &i, &j);
			else if (data->map[i][j] == '0')
				floor_image(data, &i, &j);
			else if (data->map[i][j] == 'p')
				player_image(data, &i, &j);
			else if (data->map[i][j] == 'c')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->object, i * 32, j * 32);
			else if (data->map[i][j] == 'e')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, i * 32, j * 32);
			i++;
		}
		j++;
	}
}
