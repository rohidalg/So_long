/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:51:08 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/05 17:19:20 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3

#define PLAYER      "./images/player.xpm"
#define WALL      "./images/wall.xpm"
#define OBJECT      "./images/object.xpm"
#define FLOOR      "./images/floor.xpm"
#define EXIT      "./images/exit.xpm"

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_images
{
    int player;
    int wall;
    int object;
    int floor;
    int exit;
}           t_images;

typedef struct s_map
{
	int				hight;
	int				width;
	int				x;
	int				y;
	int				player;
	int				count;
	int				finish;
	unsigned int	move;
	char			*txt;
	char			**map;
	void			*mlx;
	void			*win;
	t_images		*images;
}			t_map;

void ft_map_size(t_map *data);



#endif