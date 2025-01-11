/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:11:11 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:11:11 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	iwidth(t_map *map, int wid)
{
	map->heigth++;
	if (wid > map->width)
		map->width = wid;
}

static void	process_map(int fd, t_map *map)
{
	char	ch;
	int		wid;

	map->width = 0;
	map->heigth = 0;
	wid = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
		{
			iwidth(map, wid);
			wid = 0;
		}
		else
			wid++;
	}
	if (wid > 0)
		iwidth(map, wid);
}

void	map_sz(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error: Could not open map file for size calculation", 1);
		return ;
	}
	process_map(fd, map);
	close(fd);
}

int	ini_grid(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.heigth)
	{
		game->map.grid[y] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[y])
		{
			sl_free(game->map.grid, y);
			return (1);
		}
		x = 0;
		while (x < game->map.width)
		{
			game->map.grid[y][x] = ' ';
			x++;
		}
		game->map.grid[y][x] = '\0';
		y++;
	}
	return (0);
}

int	exten_chk(char *file)
{
	char	*exten;

	exten = ft_strrchr(file, '.');
	if (!exten || !ft_strnstr(exten, ".ber", 4))
	{
		ft_putendl_fd("Error: Not able to process the map", 1);
		return (1);
	}
	return (0);
}
