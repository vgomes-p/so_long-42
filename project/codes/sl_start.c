/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:10:10 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:10:10 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	null_structs(t_game *game)
{
	game->sprites.exit = NULL;
	game->sprites.wall = NULL;
	game->sprites.ground = NULL;
	game->sprites.player = NULL;
	game->sprites.collectable = NULL;
	game->window.mlx = NULL;
	game->window.window = NULL;
	game->map.grid = NULL;
}

static int	mkwindow(t_game *game)
{
	game->window.w_width = game->map.width * DIMENSION;
	game->window.w_height = game->map.heigth * DIMENSION;
	game->window.window = mlx_new_window(game->window.mlx,
			game->window.w_width, game->window.w_height,
			"So Long, a 42 School game");
	if (!game->window.window)
	{
		cls_game(game);
		return (1);
	}
	return (0);
}

int	init_game(t_game *game, char *file)
{
	null_structs(game);
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
		return (1);
	if (load_map(file, game))
	{
		cls_game(game);
		return (1);
	}
	if (validmap(game))
	{
		cls_game(game);
		return (1);
	}
	if (mkwindow(game))
		return (1);
	if (loadsprites(game))
	{
		ft_putendl_fd("Error: Now able to load textures!", 1);
		cls_game(game);
		return (1);
	}
	return (0);
}
