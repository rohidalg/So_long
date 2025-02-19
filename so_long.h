/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:51:08 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/19 18:23:34 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER "textures/player60.xpm"
# define WALL "textures/wall60.xpm"
# define OBJECT "textures/object60.xpm"
# define FLOOR "textures/floor60.xpm"
# define EXIT "textures/exit60.xpm"
# define WIN "textures/win60.xpm"
# define MONSTER "textures/monster60.xpm"
# define PA1 "textures/player/playera1.xpm"
# define PA2 "textures/player/playera2.xpm"
# define PA3 "textures/player/playera3.xpm"
# define PA4 "textures/player/playera4.xpm"
# define PA5 "textures/player/playera5.xpm"
# define PA6 "textures/player/playera6.xpm"
# define PA7 "textures/player/playera7.xpm"
# define PD1 "textures/player/playerd1.xpm"
# define PD2 "textures/player/playerd2.xpm"
# define PD3 "textures/player/playerd3.xpm"
# define PD4 "textures/player/playerd4.xpm"
# define PD5 "textures/player/playerd5.xpm"
# define PD6 "textures/player/playerd6.xpm"
# define PD7 "textures/player/playerd7.xpm"
# define PM1 "textures/player/playerm1.xpm"
# define PM2 "textures/player/playerm2.xpm"
# define PM3 "textures/player/playerm3.xpm"
# define PM4 "textures/player/playerm4.xpm"
# define PUD "textures/player/playerud.xpm"
# define PUD1 "textures/player/playerud1.xpm"
# define PUD2 "textures/player/playerud2.xpm"
# define PUD3 "textures/player/playerud3.xpm"
# define PUD4 "textures/player/playerud4.xpm"

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
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
	int				*monster;
	int				*pa1;
	int				*pa2;
	int				*pa3;
	int				*pa4;
	int				*pa5;
	int				*pa6;
	int				*pa7;
	int				*pd1;
	int				*pd2;
	int				*pd3;
	int				*pd4;
	int				*pd5;
	int				*pd6;
	int				*pd7;
	int				*pm1;
	int				*pm2;
	int				*pm3;
	int				*pm4;
	int				*pud;
	int				*pud1;
	int				*pud2;
	int				*pud3;
	int				*pud4;
}					t_images;

typedef struct s_map
{
	int				hight;
	int				width;
	int				x;
	int				y;
	int				updown;
	int				left;
	int				right;
	int				player;
	int				count;
	int				end;
	int				finish;
	int				monster;
	unsigned int	move;
	unsigned int	frame;
	unsigned int	frame_linux;
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
int					ft_strcmp(char *s1, char *s2);
int					ft_numlen(int n, int base);
void				ft_itoa(unsigned int n);
char				*ft_itoa_bonus(int n);
void				ft_write(unsigned int n);
void				ft_write_bonus(t_map *data);
int					ft_exit(t_map *data);
void				ft_finish(t_map *data);
void				ft_dead(t_map *data);
void				ft_player_image(t_map *data, int *i, int *j);
void				ft_draw(t_map *data);
void				ft_check_outline(t_map *data);
void				ft_check_ber(t_map *data);
void				ft_check_char(t_map *data);
void				ft_check_double(t_map *data);
void				ft_check_pirate(t_map *data);
void				ft_malloc_map(t_checker *c, t_map *data);
void				ft_free_checker(t_checker *c, int hight);
void				ft_char_hunter(t_checker *c, t_map *data, int i, int j);
void				ft_is_posible(t_map *data, int i, int j, int treasure);
void				ft_load_image(t_map *data);
void				ft_load_image_player(t_map *data, int hig, int wid);
void				ft_frame_left(t_map *data, int *j, int *i);
void				ft_frame_right(t_map *data, int *j, int *i);
void				ft_stopp(t_map *data, int *j, int *i);
void				ft_spritep(t_map *data, int *j, int *i);
void				ft_reset_dir(t_map *data);

#endif
