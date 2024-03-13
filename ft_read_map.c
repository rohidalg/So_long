/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:41 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/13 17:23:31 by rohidalg         ###   ########.fr       */
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
	gnl = get_next_line(fd);
	strlen = ft_strlen(gnl) - 1;
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

void ft_maplloc(t_map *data)
{
	int fd;
	char *gnl;
	int i;
	
	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight + 1));
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
