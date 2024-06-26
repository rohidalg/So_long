/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:23:56 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 17:47:31 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_map *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

void	ft_finish(t_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	printf("\n\n-------------------YOU WIN-------------------\n\n\n");
	exit(EXIT_FAILURE);
}
