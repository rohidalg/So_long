/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:55 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 18:39:50 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_reset(t_map *data, char *name)
{
	data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->monster = 0;
	data->count = 0;
	data->end = 0;
	data->finish = 0;
	data->move = 0;
	data->frame = 0;
	data->frame_linux = 0;
	ft_reset_dir(data);
	data->txt = name;
	ft_load_image(data);
}

void	ft_reset_dir(t_map *data)
{
	data->updown = 0;
	data->left = 0;
	data->right = 0;
}

void	ft_check_general(t_map *data)
{
	ft_check_ber(data);
	ft_check_outline(data);
	ft_check_char(data);
	ft_check_double(data);
	ft_check_countchar(data);
}

int	ft_frame(t_map *data)
{
	data->frame_linux++;
	if (data->frame_linux == 500)
	{
		ft_draw(data);
		ft_write_bonus(data);
		data->frame++;
		data->frame_linux = 0;
	}
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
		mlx_hook(data.win, DestroyNotify, ButtonPressMask, ft_exit, &data);
		mlx_key_hook(data.win, ft_press, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
