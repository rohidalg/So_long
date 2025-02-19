/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:31 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 18:17:22 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_outline(t_map *data)
{
	int	i;
	int	fail;

	i = 0;
	fail = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			fail = 1;
		i++;
	}
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			fail = 1;
		i++;
	}
	if (fail != 0)
	{
		write(2, "Error\nOUTLINE_FAILED\n\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_ber(t_map *data)
{
	if (ft_strcmp(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0
		|| ft_strlen(data->txt) <= 4)
	{
		write(2, "Error\n.ber_FAILED\n\n", 20);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_char(t_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'P' && data->map[j][i] != 'E'
				&& data->map[j][i] != 'C' && data->map[j][i] != 'M')
			{
				write(2, "Error\n CHAR_ERROR\n", 19);
				exit(EXIT_FAILURE);
			}
			else
				i++;
		}
		j++;
	}
}

void	ft_check_double(t_map *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
				data->player++;
			if (data->map[j][i] == 'E')
				data->end++;
			if (data->map[j][i] == 'C')
				data->count++;
			if (data->map[j][i] == 'M')
				data->monster++;
		}
	}
	if (data->player != 1 || data->monster < 1 || data->end != 1
		|| data->count < 1)
	{
		write(2, "Error\n DOUBLE_ERROR\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_pirate(t_map *data)
{
	int	i[2];
	int	j[2];
	int	treasure;

	i[0] = -1;
	treasure = 0;
	while (data->map[++i[0]])
	{
		i[1] = -1;
		while (data->map[i[0]][++i[1]])
		{
			if (data->map[i[0]][i[1]] == 'P')
			{
				j[0] = i[0];
				j[1] = i[1];
			}
			if (data->map[i[0]][i[1]] == 'C' || data->map[i[0]][i[1]] == 'E')
				treasure++;
		}
	}
	ft_is_posible(data, j[0], j[1], treasure);
}
