/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:10:54 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:10:54 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	posverify(t_game *game, char ch, int x, int y)
{
	game->map.grid[y][x] = ch;
	if (ch == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->map.has_player++;
	}
	else if (ch == 'C')
	{
		game->map.collectable++;
		game->map.has_collectable = 1;
	}
	else if (ch == 'E')
	{
		game->map.exit_x = x;
		game->map.exit_y = y;
		game->map.has_exit++;
	}
}

void	chkmap(t_game *game, int fd)
{
	char	ch;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->map.has_player = 0;
	game->map.has_exit = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			y++;
			x = 0;
		}
		else if (x < game->map.width)
		{
			posverify(game, ch, x, y);
			x++;
		}
	}
}
