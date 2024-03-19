/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:51:08 by rohidalg          #+#    #+#             */
/*   Updated: 2024/03/19 18:32:45 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

# define PLAYER "./imag/player.xpm"
# define WALL "./imag/wall.xpm"
# define OBJECT "./imag/object.xpm"
# define FLOOR "./imag/floor.xpm"
# define EXIT "./imag/exit.xpm"
# define WIN "./imag/win.xpm"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_images
{
	int				*player;
	int				*wall;
	int				*object;
	int				*floor;
	int				*exit;
	int				*win;
}					t_images;

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
}					t_map;

typedef struct s_checker
{
	int				**map;
	int				coins_treasure;
}					t_checker;

void				ft_map_size(t_map *data);
void				ft_maplloc(t_map *data);
void				ft_move_w(t_map *data);
void				ft_move_a(t_map *data);
void				ft_move_s(t_map *data);
void				ft_move_d(t_map *data);
int					ft_press(int keycode, t_map *data);
// char				*ft_strcpy(char *s1, char *s2);
// char				*ft_strdup(char *s);
int					ft_strcmp(char *s1, char *s2);
void				ft_itoa(unsigned int n);
int					ft_exit(t_map *data);
void				ft_finish(t_map *data);
void				wall_image(t_map *data, int *i, int *j);
void				floor_image(t_map *data, int *i, int *j);
void				player_image(t_map *data, int *i, int *j);
void				ft_draw(t_map *data);
void				ft_check_outline(t_map *data);
void				ft_check_ber(t_map *data);
void				ft_check_char(t_map *data);
void				ft_check_double(t_map *data);
void				ft_check_pirate(t_map *data);
void				ft_malloc_map(t_checker *c, t_map *data);
void				ft_free_checker(t_checker *c, int hight);
void				ft_treasure_hunter(t_checker *c, t_map *data, int i, int j);
void				ft_is_posible(t_map *data, int i, int j, int treasure);

#endif