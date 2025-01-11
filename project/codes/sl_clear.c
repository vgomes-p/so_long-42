/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:11:16 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:11:16 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cls_sprites(t_game *game)
{
	if (game->sprites.wall)
	{
		mlx_destroy_image(game->window.mlx, game->sprites.wall);
		game->sprites.wall = NULL;
	}
	if (game->sprites.ground)
	{
		mlx_destroy_image(game->window.mlx, game->sprites.ground);
		game->sprites.ground = NULL;
	}
	if (game->sprites.collectable)
	{
		mlx_destroy_image(game->window.mlx, game->sprites.collectable);
		game->sprites.collectable = NULL;
	}
	if (game->sprites.exit)
	{
		mlx_destroy_image(game->window.mlx, game->sprites.exit);
		game->sprites.exit = NULL;
	}
	if (game->sprites.player)
	{
		mlx_destroy_image(game->window.mlx, game->sprites.player);
		game->sprites.player = NULL;
	}
}

void	cls_game(t_game *game)
{
	cls_sprites(game);
	if (game->window.window)
	{
		mlx_destroy_window(game->window.mlx, game->window.window);
		game->window.window = NULL;
	}
	if (game->map.grid)
	{
		sl_free(game->map.grid, game->map.heigth);
		game->map.grid = NULL;
	}
	if (game->window.mlx)
	{
		mlx_destroy_display(game->window.mlx);
		free(game->window.mlx);
		game->window.mlx = NULL;
	}
}
