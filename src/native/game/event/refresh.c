/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:00:34 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:46:09 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void		check_key_on(t_cub3d *cub)
{
	if (cub->move.w_on == 1)
		move_w_s(cub, W);
	if (cub->move.s_on == 1)
		move_w_s(cub, S);
	if (cub->move.a_on == 1)
		move_a_d(cub, A);
	if (cub->move.d_on == 1)
		move_a_d(cub, D);
	if (cub->move.g_on == 1)
		rotate_g_dr(cub, G);
	if (cub->move.dr_on == 1)
		rotate_g_dr(cub, DR);
}

int			refresh(t_cub3d *cub)
{
	check_key_on(cub);
	mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
	ray_cast(cub);
	return (0);
}
