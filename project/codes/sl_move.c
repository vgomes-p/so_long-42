/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:10:48 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:10:48 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	movescnt(t_game *game)
{
	ft_putstr_fd("Moves given: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	game->moves++;
}

static int	chk_key(int key)
{
	if (key != ESC && key != KEY_W && key != KEY_A && key != KEY_S
		&& key != KEY_D && key != ARR_N && key != ARR_S
		&& key != ARR_E && key != ARR_W)
		return (1);
	return (0);
}

static int	chk_moves(t_game *game, int x, int y)
{
	char	pos;

	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.heigth)
		return (0);
	pos = game->map.grid[y][x];
	if (pos == '1')
		return (0);
	if (pos == 'C')
	{
		game->map.grid[y][x] = '0';
		game->map.collected++;
	}
	movescnt(game);
	if (pos == 'E' && game->map.collected == game->map.collectable)
	{
		ft_putendl_fd("You nailed it, Congrats!", 1);
		sl_quit(game);
	}
	return (1);
}

int	key_cmd(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (chk_key(key))
		return (0);
	if (key == ESC)
		return (sl_quit(game));
	else if (key == KEY_W || key == ARR_N)
		y--;
	else if (key == KEY_S || key == ARR_S)
		y++;
	else if (key == KEY_A || key == ARR_W)
		x--;
	else if (key == KEY_D || key == ARR_E)
		x++;
	if (chk_moves(game, x, y))
	{
		game->player_x = x;
		game->player_y = y;
	}
	sl_render(game);
	return (0);
}
