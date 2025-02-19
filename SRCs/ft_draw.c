/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 17:55:48 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_image(t_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->player, (*j)
		* 60, (*i) * 60);
	data->x = *j;
	data->y = *i;
}

void	ft_paste(t_map *data, int *i, int *j)
{
	if (data->map[*i][*j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images->floor, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == 'P')
		player_image(data, j, i);
	else if (data->map[*i][*j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->images->object, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == 'E' && data->count != 0)
		mlx_put_image_to_window(data->mlx, data->win, data->images->exit, (*j)
			* 60, (*i) * 60);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->images->win, (*j)
			* 60, (*i) * 60);
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
			ft_paste(data, &i, &j);
			j++;
		}
		i++;
	}
}
// pega cada imagen en su lugar corespondiente
