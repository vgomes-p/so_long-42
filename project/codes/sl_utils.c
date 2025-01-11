/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:10:02 by vgomes-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:10:02 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_quit(t_game *game)
{
	cls_game(game);
	exit(0);
	return (0);
}

void	sl_free(char **map, int height)
{
	int	cnt;

	cnt = 0;
	if (!map)
		return ;
	while (cnt < height)
	{
		if (map[cnt])
			free(map[cnt]);
		cnt++;
	}
	free(map);
}
