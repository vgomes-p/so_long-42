/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:41 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:41 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mk_ground(char **map, int x, int y, t_valid *valid)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		valid->collectable++;
	if (map[y][x] == 'E')
		valid->exit = 1;
	map[y][x] = 'V';
	mk_ground(map, x + 1, y, valid);
	mk_ground(map, x - 1, y, valid);
	mk_ground(map, x, y + 1, valid);
	mk_ground(map, x, y - 1, valid);
}

static void	sl_close(t_game *game, t_valid *valid, int x0, int y0)
{
	char		**temp;
	int			x1;
	int			y1;

	y1 = 0;
	temp = malloc(sizeof(char *) * (game->map.heigth + 1));
	while (y1 < game->map.heigth)
	{
		x1 = 0;
		temp[y1] = ft_strdup(game->map.grid[y1]);
		while (x1++ < game->map.width)
		{
			if (temp[y1][x1] == 'P')
			{
				x0 = x1;
				y0 = y1;
			}
			if (temp[y1][x1] == 'C')
				valid->all_collectable++;
		}
		y1++;
	}
	temp[y1] = NULL;
	mk_ground(temp, x0, y0, valid);
	sl_free(temp, game->map.heigth);
}

int	validpath(t_game *game)
{
	t_valid	valid;
	int		x0;
	int		y0;

	x0 = -1;
	y0 = -1;
	valid.all_collectable = 0;
	valid.exit = 0;
	valid.collectable = 0;
	sl_close(game, &valid, x0, y0);
	if (valid.all_collectable != valid.collectable)
	{
		ft_putendl_fd("Error: Not able to collect all collectibles", 1);
		return (1);
	}
	if (!valid.exit)
	{
		ft_putendl_fd("Error: Exit is not accessible!", 1);
		return (1);
	}
	return (0);
}
