/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_cast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:04:00 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/10 11:24:28 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	sort_sprites(int *ord, double *dist, int nb_sp)
{
	int		i;
	int		tmp;
	double	tmp_d;

	i = 0;
	while (i < nb_sp)
	{
		if (i + 1 < nb_sp && dist[i] < dist[i + 1])
		{
			tmp = ord[i + 1];
			tmp_d = dist[i + 1];
			ord[i + 1] = ord[i];
			dist[i + 1] = dist[i];
			ord[i] = tmp;
			dist[i] = tmp_d;
			i = -1;
		}
		i++;
	}
}

void		find_sp_dst(t_cub3d *cub, int *ord, double *dst)
{
	int i;

	i = 0;
	while (i < cub->map.nb_sprit)
	{
		ord[i] = i;
		dst[i] = ((cub->map.pos_x - cub->map.sprit[i].x) *
					(cub->map.pos_x - cub->map.sprit[i].x) +
					(cub->map.pos_y - cub->map.sprit[i].y) *
					(cub->map.pos_y - cub->map.sprit[i].y));
		i++;
	}
	sort_sprites(ord, dst, cub->map.nb_sprit);
}