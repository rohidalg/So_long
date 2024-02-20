/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:51:08 by rohidalg          #+#    #+#             */
/*   Updated: 2024/02/20 19:27:02 by rohidalg         ###   ########.fr       */
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

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_images
{
    int player;
    int wall;
    int object;
    int floor;
    int exit;
}           t_images;



void ft_draw();


#endif