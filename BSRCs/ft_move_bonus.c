/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:22:47 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 17:48:26 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_w(t_map *data)
{
	ft_reset_dir(data);
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
	}
	else if (data->map[data->y - 1][data->x] == 'E' && data->count == 0)
		data->finish = 1;
	data->updown = 1;
	data->frame = 0;
}

void	ft_move_a(t_map *data)
{
	ft_reset_dir(data);
	if (data->map[data->y][data->x - 1] != '1' && data->map[data->y][data->x
		- 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'M')
			ft_dead(data);
		else if (data->map[data->y][data->x - 1] == 'C'
			|| data->map[data->y][data->x - 1] == '0')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		data->x--;
		data->move++;
	}
	else if (data->map[data->y][data->x - 1] == 'E' && data->count == 0)
		data->finish = 1;
	data->left = 1;
	data->frame = 0;
}

void	ft_move_s(t_map *data)
{
	ft_reset_dir(data);
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
	}
	else if (data->map[data->y + 1][data->x] == 'E' && data->count == 0)
		data->finish = 1;
	data->updown = 1;
	data->frame = 0;
}

void	ft_move_d(t_map *data)
{
	ft_reset_dir(data);
	if (data->map[data->y][data->x + 1] != '1' && data->map[data->y][data->x
		+ 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'M')
			ft_dead(data);
		else if (data->map[data->y][data->x + 1] == 'C'
			|| data->map[data->y][data->x + 1] == '0')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		data->x++;
		data->move++;
	}
	else if (data->map[data->y][data->x + 1] == 'E' && data->count == 0)
		data->finish = 1;
	data->right = 1;
	data->frame = 0;
}

int	ft_press(int keysym, t_map *data)
{
	if (keysym == XK_Escape)
		ft_exit(data);
	else if (keysym == XK_w && data->finish == 0)
		ft_move_w(data);
	else if (keysym == XK_a && data->finish == 0)
		ft_move_a(data);
	else if (keysym == XK_s && data->finish == 0)
		ft_move_s(data);
	else if (keysym == XK_d && data->finish == 0)
		ft_move_d(data);
	return (0);
}
