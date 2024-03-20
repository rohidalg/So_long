/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:55 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/20 17:50:51 by rohidalg         ###   ########.fr       */
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
	data->images->win = mlx_xpm_file_to_image(data->mlx, WIN, &hig, &wid);
}

void	ft_reset(t_map *data, char *name)
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

void	ft_check_general(t_map *data)
{
	ft_check_ber(data);
	write(1, "4.1\n", 5);
	ft_check_outline(data);
	write(1, "4.2\n", 5);
	ft_check_char(data);
	write(1, "4.3\n", 5);
	ft_check_double(data);
	write(1, "4.4\n", 5);
	ft_check_pirate(data);
	write(1, "4.5\n", 5);
}

int	ft_frame(t_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_draw(data);
	if (data->count == 0 && data->player == 1 && data->finish == 1)
		ft_finish(data);
	return (0);
}

int	main(int words, char **arguments)
{
	t_map data;
	
	if (words == 2)
	{
		data.mlx = mlx_init();
		write(1, "1\n", 3);
		ft_reset(&data, arguments[1]);
		write(1, "2\n", 3);
		ft_map_size(&data);
		write(1, "3\n", 3);
		ft_maplloc(&data);
		write(1, "4\n", 3);
		ft_check_general(&data);
		write(1, "5\n", 3);
		data.win = mlx_new_window(data.mlx, data.width * 32, data.hight * 32,
			"so_long");
		write(1, "6\n", 3);
		mlx_hook(data.win, 17, 0, ft_exit, &data);
		write(1, "7\n", 3);
		mlx_hook(data.win, 02, 0, ft_press, &data);
		write(1, "8\n", 3);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		write(1, "9\n", 3);
		mlx_loop(data.mlx);
		write(1, "10\n", 3);
	}
	return (0);
}
