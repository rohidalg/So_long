/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:22:47 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 18:04:12 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_w(t_map *data)
{
	if (data->map[data->y - 1][data->x] != '1' && data->map[data->y
		- 1][data->x] != 'E') //verificamos que no se mueva encima de paredes o salidas
	{
		if (data->map[data->y - 1][data->x] == 'C' || data->map[data->y
			- 1][data->x] == '0') //mueve al jugador
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->count--; //diminuye el contador y actuaiza posiciones
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		data->y--;
		data->move++;
		ft_write(data->move);
	}
	else if (data->map[data->y - 1][data->x] == 'E' && data->count == 0)
		data->finish = 1; // verificar si el juego ha terminado
}

void	ft_move_a(t_map *data)
{
	if (data->map[data->y][data->x - 1] != '1' && data->map[data->y][data->x
		- 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C' || data->map[data->y][data->x
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
}

void	ft_move_s(t_map *data)
{
	if (data->map[data->y + 1][data->x] != '1' && data->map[data->y
		+ 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C' || data->map[data->y
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
}

void	ft_move_d(t_map *data)
{
	if (data->map[data->y][data->x + 1] != '1' && data->map[data->y][data->x
		+ 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C' || data->map[data->y][data->x
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
// hace el movimineto correspondiennte y comprueba si has terminado
