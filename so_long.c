/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:55 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/08 17:33:11 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_image(t_map *data)
{
	int	hig;
	int	wid;

	data->images = malloc(sizeof(t_images));
	data->images->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &hig, &wid);
	data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &hig, &wid);
	data->images->object = mlx_xpm_file_to_image(data->mlx, OBJECT, &hig, &wid);
	data->images->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &hig, &wid);
	data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &hig, &wid);
}

void ft_reset(t_map *data, char *name)
{
    data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->count = 0;
	data->finish = 0;
	data->move = 0;
	data->txt = name;
	ft_load_image(data);
}

void ft_check_general(t_map *data)
{
	ft_check_ber(data);
	ft_check_outline(data);
}

int main (/*int words, char **arguments*/)
{
	t_map data;
	int i;
	
	i = 0;
	if (/*words == 2*/i == 0)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, data.width * 40, data.hight * 40, "so_long");
		
		mlx_loop(data.mlx);
	}
	return(0);
}