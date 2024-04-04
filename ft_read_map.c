/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:41 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/04 16:13:16 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bad_malloc(void)
{
	write(2, "\n\nMALLOC_ERROR_MAP\n\n", 21);
	exit(EXIT_FAILURE);
}

void	ft_map_size(t_map *data)
{
	char	*gnl;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
	{
		write(2, "\n\nERROR_READ_MAP\n\n", 19);
		exit(EXIT_FAILURE);
	}
	data->width = ft_strlen(gnl) - 1;
	data->hight = 0;
	while (gnl)
	{
		if ((int)ft_strlen(gnl) - 1 != data->width)
		{
			write(2, "Error\nMap not valid\n", 20);
			exit(EXIT_FAILURE);
		}
		data->hight++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	gnl = 0;
	close(fd);
}

void	ft_maplloc(t_map *data)
{
	int		fd;
	char	*gnl;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
	if (!data->map)
		ft_bad_malloc();
	while (i < data->hight)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			ft_bad_malloc();
		data->map[i] = ft_strdup(gnl);
		if (!data->map[i])
			ft_bad_malloc();
		data->map[i][data->width] = '\0';
		i++;
		free(gnl);
	}
	data->map[i] = 0;
	close(fd);
}
