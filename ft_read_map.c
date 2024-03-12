/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:41 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/12 16:25:05 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_bad_malloc(void)
{
	write(2, "\n\nMALLOC_ERROR_MAP\n\n", 21);
	exit(EXIT_FAILURE);
}

void	ft_map_size(t_map *data)
{
	char	*gnl;
	char	strlen;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	strlen = ft_strlen(gnl) - 1;
	gnl = get_next_line(fd);
	data->width = strlen;
	data->hight = 0;
	while (gnl)
	{
		data->hight++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	gnl = 0;
	close(fd);
}
