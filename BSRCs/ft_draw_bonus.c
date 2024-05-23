/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:50:25 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/23 17:48:07 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_image(t_map *data)
{
	int	hig;
	int	wid;

	hig = data->hight;
	wid = data->width;
	data->images = malloc(sizeof(t_images));
	ft_load_image_player(data, hig, wid);
	data->images->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &hig, &wid);
	data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &hig, &wid);
	data->images->object = mlx_xpm_file_to_image(data->mlx, OBJECT, &hig, &wid);
	data->images->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &hig, &wid);
	data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &hig, &wid);
	data->images->win = mlx_xpm_file_to_image(data->mlx, WIN, &hig, &wid);
	data->images->monster = mlx_xpm_file_to_image(data->mlx, MONSTER, &hig,
			&wid);
}

void	ft_load_image_player(t_map *data, int hig, int wid)
{
	data->images->pa1 = mlx_xpm_file_to_image(data->mlx, PA1, &hig, &wid);
	data->images->pa2 = mlx_xpm_file_to_image(data->mlx, PA2, &hig, &wid);
	data->images->pa3 = mlx_xpm_file_to_image(data->mlx, PA3, &hig, &wid);
	data->images->pa4 = mlx_xpm_file_to_image(data->mlx, PA4, &hig, &wid);
	data->images->pa5 = mlx_xpm_file_to_image(data->mlx, PA5, &hig, &wid);
	data->images->pa6 = mlx_xpm_file_to_image(data->mlx, PA6, &hig, &wid);
	data->images->pa7 = mlx_xpm_file_to_image(data->mlx, PA7, &hig, &wid);
	data->images->pd1 = mlx_xpm_file_to_image(data->mlx, PD1, &hig, &wid);
	data->images->pd2 = mlx_xpm_file_to_image(data->mlx, PD2, &hig, &wid);
	data->images->pd3 = mlx_xpm_file_to_image(data->mlx, PD3, &hig, &wid);
	data->images->pd4 = mlx_xpm_file_to_image(data->mlx, PD4, &hig, &wid);
	data->images->pd5 = mlx_xpm_file_to_image(data->mlx, PD5, &hig, &wid);
	data->images->pd6 = mlx_xpm_file_to_image(data->mlx, PD6, &hig, &wid);
	data->images->pd7 = mlx_xpm_file_to_image(data->mlx, PD7, &hig, &wid);
	data->images->pm1 = mlx_xpm_file_to_image(data->mlx, PM1, &hig, &wid);
	data->images->pm2 = mlx_xpm_file_to_image(data->mlx, PM2, &hig, &wid);
	data->images->pm3 = mlx_xpm_file_to_image(data->mlx, PM3, &hig, &wid);
	data->images->pm4 = mlx_xpm_file_to_image(data->mlx, PM4, &hig, &wid);
	data->images->pud = mlx_xpm_file_to_image(data->mlx, PUD, &hig, &wid);
	data->images->pud1 = mlx_xpm_file_to_image(data->mlx, PUD1, &hig, &wid);
	data->images->pud2 = mlx_xpm_file_to_image(data->mlx, PUD2, &hig, &wid);
	data->images->pud3 = mlx_xpm_file_to_image(data->mlx, PUD3, &hig, &wid);
	data->images->pud4 = mlx_xpm_file_to_image(data->mlx, PUD4, &hig, &wid);
}

void	ft_player_image(t_map *data, int *j, int *i)
{
	ft_spritep(data, j, i);
	data->x = *j;
	data->y = *i;
}

void	ft_paste(t_map *data, int *i, int *j)
{
	if (data->map[*i][*j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images->floor, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == 'P')
		ft_player_image(data, j, i);
	else if (data->map[*i][*j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->images->object, (*j)
			* 60, (*i) * 60);
	else if (data->map[*i][*j] == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->images->monster,
			(*j) * 60, (*i) * 60);
	else if (data->map[*i][*j] == 'E' && data->count != 0)
		mlx_put_image_to_window(data->mlx, data->win, data->images->exit, (*j)
			* 60, (*i) * 60);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->images->win, (*j)
			* 60, (*i) * 60);
}

void	ft_draw(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_paste(data, &i, &j);
			j++;
		}
		i++;
	}
}
