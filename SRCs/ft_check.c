/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:52:31 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 17:47:23 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_malloc_map(t_checker *c, t_map *data)
{
	int	i;
	int	j;

	c->map = malloc(sizeof(int *) * data->hight);
	i = -1;
	while (++i < data->hight)
		c->map[i] = malloc(sizeof(int *) * data->width);
	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			c->map[i][j] = 0;
	}
}

void	ft_free_checker(t_checker *c, int hight)
{
	int	i;

	i = -1;
	while (++i < hight)
		free(c->map[i]);
	free(c->map);
	c->map = 0;
}

void	ft_treasure_hunter(t_checker *c, t_map *data, int i, int j)
{
	if (c->coins_treasure == 0)
		return ;
	if (c->map[i][j] == 0 && data->map[i][j] != '1')
	{
		c->map[i][j] = 1;
		if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			c->coins_treasure--;
		if (data->map[i][j] == 'E')
			return ;
		ft_treasure_hunter(c, data, i + 1, j);
		ft_treasure_hunter(c, data, i - 1, j);
		ft_treasure_hunter(c, data, i, j + 1);
		ft_treasure_hunter(c, data, i, j - 1);
	}
}

void	ft_is_posible(t_map *data, int j, int i, int treasure)
{
	t_checker	c;

	c.coins_treasure = treasure;
	ft_malloc_map(&c, data);
	ft_treasure_hunter(&c, data, j, i);
	if (c.coins_treasure != 0)
	{
		write(2, "\n\nMAP_IS_IMPOSIBLE\n\n", 21);
		exit(EXIT_FAILURE);
	}
	ft_free_checker(&c, data->hight);
}
