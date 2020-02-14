/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:43:08 by vmoreau           #+#    #+#             */
/*   Updated: 2020/02/11 13:31:11 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_value(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (!((map->map[y][x] >= 0 && map->map[y][x] <= 2)
			|| map->map[y][x] == 30 || map->map[y][x] == 35
			|| map->map[y][x] == 39 || map->map[y][x] == 21))
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_pos(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 30 || map->map[y][x] == 35
				|| map->map[y][x] == 39 || map->map[y][x] == 21)
			{
				if (map->pos_x == -1 && map->pos_y == -1)
				{
					map->pos_y = y;
					map->pos_x = x;
					map->dir = map->map[y][x] + 48;
					map->map[y][x] = 5;
				}
				else
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	from_8_to_1(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 8)
				map->map[y][x] = 1;
			x++;
		}
		y++;
	}
}

int			check_map(t_map *map, t_path *pars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (check_value(map, y, x) == -1)
	{
		pars->error = ft_strdup("Map ERROR\n");
		return (-1);
	}
	else if (check_pos(map, y, x) == -1)
	{
		pars->error = ft_strdup("Map ERROR\n");
		return (-1);
	}
	else if (check_closed_map(map, y, x) == -1)
	{
		pars->error = ft_strdup("Map ERROR\n");
		return (-1);
	}
	from_8_to_1(map);
	return (0);
}