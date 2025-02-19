/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:31 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 17:52:37 by rohidalg         ###   ########.fr       */
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
//comprueba las primmeras y ultimas columnas y filas

void	ft_check_ber(t_map *data)
{
	if (ft_strcmp(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0
		|| ft_strlen(data->txt) <= 4)
	{
		write(2, "Error\n.ber_FAILED\n\n", 16);
		exit(EXIT_FAILURE);
	}
}
//comprueba si termina en .ber o si no se llama solo asi

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
				&& data->map[j][i] != 'C')
			{
				write(2, "Error\nCHAR_ERROR\n\n", 19);
				exit(EXIT_FAILURE);
			}
			else
				i++;
		}
		j++;
	}
}
//comprueba que solo hay esas letras

void	ft_check_double(t_map *data)
{
	int	i;
	int	j;
	int	end;

	j = -1;
	end = 0;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
				data->player++;
			if (data->map[j][i] == 'E')
				end++;
			if (data->map[j][i] == 'C')
				data->count++;
		}
	}
	if (data->player != 1 || end != 1 || data->count < 1)
	{
		write(2, "Error\nDOUBLE_ERROR\n\n", 21);
		exit(EXIT_FAILURE);
	}
}
//comrpueba qu eno haay ninguno doble, y que exite algun jugador y final

void	ft_check_pirate(t_map *data)
{
	int	i[2]; // i[0] = fila actual, i[1] = columna actual
	int	j[2]; // j[0] = fila del jugador 'P', j[1] = columna del jugador 'P'
	int	treasure; // Contador de tesoros 'C' y salidas 'E'

	i[0] = -1;
	treasure = 0;
	while (data->map[++i[0]]) // Recorre cada fila
	{
		i[1] = -1;
		while (data->map[i[0]][++i[1]]) // Recorre cada columna
	{
			if (data->map[i[0]][i[1]] == 'P')
			{
				if (data->map[i[0]][i[1]] == 'P')
				{
					j[0] = i[0]; // Guardar fila del jugador
					j[1] = i[1]; // Guardar columna del jugador
				}
			}
			if (data->map[i[0]][i[1]] == 'C' || data->map[i[0]][i[1]] == 'E')
				treasure++; //cuenta todos los c y e
		}
	}
	ft_is_posible(data, j[0], j[1], treasure);
}
//busca la posicion del jugador y cuenta todas las c y e, para ver si es posible
