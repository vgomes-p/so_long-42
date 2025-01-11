/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:54 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:54 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chkwall(t_game *game)
{
	int	cnt;
	int	y;
	int	x;

	cnt = 0;
	x = game->map.width - 1;
	y = game->map.heigth - 1;
	while (cnt < game->map.width)
	{
		if (game->map.grid[0][cnt] != '1' || game->map.grid[y][cnt] != '1')
			return (1);
		cnt++;
	}
	cnt = 0;
	while (cnt < game->map.heigth)
	{
		if (game->map.grid[cnt][0] != '1' || game->map.grid[cnt][x] != '1')
			return (1);
		cnt++;
	}
	if (x == y)
		return (1);
	return (0);
}

static int	readmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.heigth)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] != '1' && game->map.grid[y][x] != '0'
				&& game->map.grid[y][x] != 'P' && game->map.grid[y][x] != 'C'
				&& game->map.grid[y][x] != 'E')
			{
				ft_putendl_fd("Error: the map file have invalid rules!", 1);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	chkelements(t_game *game)
{
	if (!game->map.has_collectable)
	{
		ft_putendl_fd("Error: The map needs collectable to be valid", 1);
		return (1);
	}
	if (!game->map.has_exit)
	{
		ft_putendl_fd("Error: The map needs a exit to be valid!", 1);
		return (1);
	}
	if (!game->map.has_player)
	{
		ft_putendl_fd("Error: The map needs a player to be valid!", 1);
		return (1);
	}
	return (0);
}

static int	chkstructures(t_game *game)
{
	if (chkwall(game))
	{
		ft_putendl_fd("Error: The map is not valid since it has no wall", 1);
		return (1);
	}
	if (readmap(game))
	{
		ft_putendl_fd("Error: Not able to read the map", 1);
		return (1);
	}
	return (0);
}

int	validmap(t_game *game)
{
	if (game->map.has_player > 1)
	{
		ft_putendl_fd("Error: The map can only have one player", 1);
		return (1);
	}
	if (game->map.has_exit > 1)
	{
		ft_putendl_fd("Error: The map can only have one exit", 1);
		return (1);
	}
	if (chkelements(game))
		return (1);
	if (chkstructures(game))
		return (1);
	if (validpath(game))
		return (1);
	return (0);
}
