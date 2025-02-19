/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:41 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 16:07:41 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bad_malloc(void)
{
	write(2, "Error\nMALLOC_ERROR_MAP\n\n", 25);
	exit(EXIT_FAILURE);
}

void	ft_bad_size(void)
{
	write(2, "Error\nMAP_SIZE_ERROR\n\n", 23);
	exit(EXIT_FAILURE);
}

void	ft_map_size(t_map *data)
{
	char	*gnl;
	int		fd;
	int		strlen;

	fd = open(data->txt, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
	{
		write(2, "Error\nERROR_READ_MAP\n\n", 23);
		exit(EXIT_FAILURE);
	}
	strlen = ft_strlen(gnl) - 1;
	data->width = strlen;
	data->hight = 0;
	while (gnl)
	{
		if (strlen != data->width)
			ft_bad_size();
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
