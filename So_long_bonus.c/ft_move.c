/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:22:47 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/16 20:24:24 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_w(t_map *data)
{
	if (data->map[data->y - 1][data->x] != '1' && data->map[data->y
		- 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'M')
			ft_dead(data);
		else if (data->map[data->y - 1][data->x] == 'C' || data->map[data->y
			- 1][data->x] == '0')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		data->y--;
		data->move++;
		ft_write(data->move);
	}
	else if (data->map[data->y - 1][data->x] == 'E' && data->count == 0)
		data->finish = 1;
	data->frame = 0;
}

void	ft_move_a(t_map *data)
{
	if (data->map[data->y][data->x - 1] != '1' && data->map[data->y][data->x
		- 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'M')
			ft_dead(data);
		else if (data->map[data->y][data->x - 1] == 'C' || data->map[data->y][data->x
			- 1] == '0')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		data->x--;
		data->move++;
		ft_write(data->move);
	}
	else if (data->map[data->y][data->x - 1] == 'E' && data->count == 0)
		data->finish = 1;
	data->frame = 0;
}

void	ft_move_s(t_map *data)
{
	if (data->map[data->y + 1][data->x] != '1' && data->map[data->y
		+ 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'M')
			ft_dead(data);
		else if (data->map[data->y + 1][data->x] == 'C' || data->map[data->y
			+ 1][data->x] == '0')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		data->y++;
		data->move++;
		ft_write(data->move);
	}
	else if (data->map[data->y + 1][data->x] == 'E' && data->count == 0)
		data->finish = 1;
	data->frame = 0;
}

void	ft_move_d(t_map *data)
{
	if (data->map[data->y][data->x + 1] != '1' && data->map[data->y][data->x
		+ 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'M')
			ft_dead(data);
		else if (data->map[data->y][data->x + 1] == 'C' || data->map[data->y][data->x
			+ 1] == '0')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		data->x++;
		data->move++;
		ft_write(data->move);
	}
	else if (data->map[data->y][data->x + 1] == 'E' && data->count == 0)
		data->finish = 1;
	data->frame = 0;
}

int	ft_press(int keycode, t_map *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W && data->finish == 0)
		ft_move_w(data);
	else if (keycode == A && data->finish == 0)
		ft_move_a(data);
	else if (keycode == S && data->finish == 0)
		ft_move_s(data);
	else if (keycode == D && data->finish == 0)
		ft_move_d(data); 
	return (0);
}
