/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:55 by rohidalg          #+#    #+#             */
/*   Updated: 2024/04/04 18:45:14 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	data->images->win = mlx_xpm_file_to_image(data->mlx, MONSTER, &hig, &wid);
}

void	ft_reset(t_map *data, char *name)
{
	data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->monster = 0;
	data->count = 0;
	data->finish = 0;
	data->move = 0;
	data->txt = name;
	ft_load_image(data);
}

void	ft_check_general(t_map *data)
{
	ft_check_ber(data);
	ft_check_outline(data);
	ft_check_char(data);
	ft_check_double(data);
	ft_check_pirate(data);
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
	t_map	data;

	if (words == 2)
	{
		data.mlx = mlx_init();
		ft_reset(&data, arguments[1]);
		ft_map_size(&data);
		ft_maplloc(&data);
		ft_check_general(&data);
		data.win = mlx_new_window(data.mlx, data.width * 60, data.hight * 60,
				"so_long");
		mlx_hook(data.win, 17, 0, ft_exit, &data);
		mlx_hook(data.win, 02, 0, ft_press, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
