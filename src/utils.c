/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:33:50 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/26 14:34:04 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check(t_gameimg *game_img, int i, int j)
{
	if (game_img->map[i][j] != MAP_ENTRY
		&& game_img->map[i][j] != MAP_COLLECTABLE
		&& game_img->map[i][j] != MAP_EXIT
		&& game_img->map[i][j] != MAP_FLOOR)
	{
		if (game_img->map[i][j] != MAP_WALL)
			return (1);
	}
	return (0);
}

int	map_simplecheck(char *buf)
{
	int	i;

	i = 1;
	while (buf && buf[i])
	{
		if (buf[i -1] == '\n' && buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**free_return(char *buf, char *tmp, int fd)
{
	free(buf);
	free(tmp);
	close(fd);
	return (NULL);
}

int	boundary_check(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (map[len])
		len++;
	while (map[++i])
	{
		j = 0;
		if (i == 0 && map[i][0] != MAP_WALL)
			return (1);
		while (map[i][j])
		{
			if ((i == 0 || i == len - 1) && map[i][j] != MAP_WALL)
				return (1);
			j++;
		}
		if (map[i][j - 1] != MAP_WALL)
			return (1);
	}
	return (0);
}
