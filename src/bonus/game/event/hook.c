/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:27:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:45:53 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			key_release(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 0;
	if (keycode == S)
		move->s_on = 0;
	if (keycode == A)
		move->a_on = 0;
	if (keycode == D)
		move->d_on = 0;
	if (keycode == G)
		move->g_on = 0;
	if (keycode == DR)
		move->dr_on = 0;
	if (keycode == 49)
		move->shot = 0;
	return (0);
}

int			key_push(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 1;
	if (keycode == S)
		move->s_on = 1;
	if (keycode == A)
		move->a_on = 1;
	if (keycode == D)
		move->d_on = 1;
	if (keycode == G)
		move->g_on = 1;
	if (keycode == DR)
		move->dr_on = 1;
	if (keycode == 17 && move->dm == 0)
		move->dm = 1;
	else if (keycode == 17 && move->dm == 1)
		move->dm = 0;
	if (keycode == 49)
		move->shot = 1;
	return (0);
}

int			key_hook(int keycode, t_cub3d *cub)
{
	key_push(keycode, &cub->move);
	if (keycode == 53)
		close_prog(cub);
	if (keycode == 78 && cub->spe.rot_spe + RS > 0.0051)
		cub->spe.rot_spe -= 0.005;
	if (keycode == 69 && cub->spe.rot_spe + RS < 0.25)
		cub->spe.rot_spe += 0.005;
	if (keycode == 125 && cub->spe.mov_spe + MS > 0.05)
		cub->spe.mov_spe -= 0.01;
	if (keycode == 126 && cub->spe.mov_spe + MS < 0.5)
		cub->spe.mov_spe += 0.01;
	if (keycode == F)
		save(cub);
	return (0);
}

static int	count_sprit(t_map map)
{
	int x;
	int y;
	int ret;

	y = 0;
	ret = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (map.map[y][x] == 2 || map.map[y][x] == 3)
				ret++;
			x++;
		}
		y++;
	}
	return (ret);
}

int			mouse_hook(int button, int x, int y, t_cub3d *cub)
{
	int w;
	int h;
	int tmp;

	tmp = cub->map.nb_sprit;
	w = (int)(cub->pars.scrwidth / 4.5);
	h = (int)(cub->pars.scrheight / 4.5);
	if (y < h - 1 && x < w - 1 && check_wall(x, y, cub) == 1 &&
		cub->pars.scrheight > 300 && cub->pars.scrwidth > 300)
	{
		if (button == 1)
			cub->map.map[(y * cub->map.y) / h][(x * cub->map.x) / w] = 1;
		if (button == 2)
			cub->map.map[(y * cub->map.y) / h][(x * cub->map.x) / w] = 0;
		if (button == 3)
			cub->map.map[(y * cub->map.y) / h][(x * cub->map.x) / w] = 2;
	}
	cub->map.nb_sprit = count_sprit(cub->map);
	if (tmp != cub->map.nb_sprit)
	{
		free(cub->map.sprit);
		cub->map.sprit = fill_sprit(&cub->map, cub->map.nb_sprit);
	}
	return (0);
}
