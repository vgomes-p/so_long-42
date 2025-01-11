/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:34 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:09:34 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map path>\n", 1);
		return (1);
	}
	if (init_game(&game, argv[1]))
	{
		ft_putendl_fd("Error starting game!", 1);
		return (1);
	}
	game.moves = 1;
	sl_render(&game);
	mlx_hook(game.window.window, 17, 0, sl_quit, &game);
	mlx_hook(game.window.window, 2, 1L << 0, key_cmd, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
