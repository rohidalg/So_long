/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:55:27 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/18 20:59:40 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_write(t_map *data)
{
	void number;

	number = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->win,35,35, 0xFFFFFFFF, "Movements: " );
	mlx_string_put(data->mlx, data->win,35,35, 0xFFFFFFFF, number);
}

// void	show_moves(t_game *game)
// {
// 	char	*moves;

// 	moves = ft_itoa(game->steps);
// 	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, "Steps:");
// 	mlx_string_put(game->mlx, game->win, 75, 20, 0xFFFFFF, moves);
// 	free(moves);
// }