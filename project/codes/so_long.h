/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:24 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:24 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES */
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../includes/libft/libft.h"
# include <../includes/minilibx/mlx.h>

/* DEFINES */
# define DIMENSION 64

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define ESC 65307
# define ARR_W 65361
# define ARR_N 65362
# define ARR_E 65363
# define ARR_S 65364

/* STRUCTURES */
typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		w_width;
	int		w_height;
	int		max;
}	t_win;

typedef struct s_sprites
{
	void	*wall;
	void	*ground;
	void	*collectable;
	void	*exit;
	void	*player;
	int		wid_img;
	int		heig_img;
}	t_sprites;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		heigth;
	int		collectable;
	int		collected;
	int		exit_x;
	int		exit_y;
	int		has_exit;
	int		has_player;
	int		has_collectable;
}	t_map;

typedef struct s_game
{
	int			player_x;
	int			player_y;
	int			moves;
	t_win		window;
	t_sprites	sprites;
	t_map		map;
}	t_game;

typedef struct s_valid
{
	int	collectable;
	int	all_collectable;
	int	exit;
}	t_valid;

/* FUNCTIONS IN SL_UTILS.C FILE */
int			sl_quit(t_game *game);
void		sl_free(char **map, int height);

/* GENERAL FUNCTIONS */
int			exten_chk(char *file);
int			ini_grid(t_game *game);
int			validmap(t_game *game);
void		cls_game(t_game *game);
void		sl_render(t_game *game);
int			validpath(t_game *game);
int			loadsprites(t_game *game);
void		chkmap(t_game *game, int fd);
void		map_sz(char *file, t_map *map);
int			key_cmd(int key, t_game *game);
int			load_map(char *file, t_game *game);
int			init_game(t_game *game, char *file);

#endif