/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:11:04 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:11:04 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(char *file, t_game *game)
{
	int		fd;

	map_sz(file, &game->map);
	game->map.grid = malloc(sizeof(char *) * game->map.heigth);
	if (!game->map.grid)
		return (1);
	if (ini_grid(game))
		return (1);
	if (exten_chk(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		sl_free(game->map.grid, game->map.heigth);
		game->map.grid = NULL;
		return (1);
	}
	game->map.collectable = 0;
	game->map.collected = 0;
	game->map.has_exit = 0;
	game->map.has_player = 0;
	game->map.has_collectable = 0;
	chkmap(game, fd);
	close(fd);
	return (0);
}

int	loadsprites(t_game *game)
{
	game->sprites.wall = mlx_xpm_file_to_image(game->window.mlx,
			"texture/wall.xpm", &game->sprites.wid_img,
			&game->sprites.heig_img);
	game->sprites.ground = mlx_xpm_file_to_image(game->window.mlx,
			"texture/ground.xpm", &game->sprites.wid_img,
			&game->sprites.heig_img);
	game->sprites.player = mlx_xpm_file_to_image(game->window.mlx,
			"texture/player.xpm", &game->sprites.wid_img,
			&game->sprites.heig_img);
	game->sprites.collectable = mlx_xpm_file_to_image(game->window.mlx,
			"texture/collect.xpm", &game->sprites.wid_img,
			&game->sprites.heig_img);
	game->sprites.exit = mlx_xpm_file_to_image(game->window.mlx,
			"texture/exit.xpm", &game->sprites.wid_img,
			&game->sprites.heig_img);
	if (!game->sprites.wall || !game->sprites.ground || !game->sprites.player
		|| !game->sprites.collectable || !game->sprites.exit)
		return (1);
	return (0);
}
