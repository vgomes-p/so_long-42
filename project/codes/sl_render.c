/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:10:39 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:10:39 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player(t_game *game)
{
	mlx_put_image_to_window(game->window.mlx, game->window.window,
		game->sprites.player, game->player_x * DIMENSION,
		game->player_y * DIMENSION);
}

void	sl_render(t_game *game)
{
	void	*sprite;
	int		x;
	int		y;

	y = 0;
	while (y < game->map.heigth)
	{
		x = 0;
		while (x < game->map.width)
		{
			sprite = game->sprites.ground;
			if (game->map.grid[y][x] == '1')
				sprite = game->sprites.wall;
			else if (game->map.grid[y][x] == 'C')
				sprite = game->sprites.collectable;
			else if (game->map.grid[y][x] == 'E')
				sprite = game->sprites.exit;
			mlx_put_image_to_window(game->window.mlx, game->window.window,
				sprite, x * DIMENSION, y * DIMENSION);
			x++;
		}
		y++;
	}
	player(game);
}
