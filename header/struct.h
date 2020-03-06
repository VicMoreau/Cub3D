/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:06 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/06 16:12:00 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_print
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		y;
	int		start;
	int		color_sky;
	int		color_floor;
	double	wall_dist;
}				t_print;

typedef struct	s_speed
{
	double rot_spe;
	double mov_spe;
}				t_speed;
typedef struct	s_move
{
	int w_on;
	int s_on;
	int a_on;
	int d_on;
	int g_on;
	int dr_on;
	int dm;
}				t_move;
typedef struct	s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		**map;
	double	pos_x;
	double	pos_y;
	char	dir;
}				t_map;
typedef struct	s_path
{
	int		scrwidth;
	int		scrheight;
	int		save;
	char	*pars_no;
	char	*pars_so;
	char	*pars_ea;
	char	*pars_we;
	char	*pars_s;
	char	*pars_f;
	char	*pars_c;
	char	*error;
}				t_path;
typedef struct	s_coor_vec
{
	double	x_f;
	double	y_f;
	int		x_i;
	int		y_i;
}				t_coor_vec;
typedef struct	s_cast
{
	t_coor_vec	dir;
	t_coor_vec	plane;
	t_coor_vec	ray_dir;
	t_coor_vec	side_dist;
	t_coor_vec	delta_dist;
	t_coor_vec	map;
	t_coor_vec	step;
	t_coor_vec	pos_tex;
	double		wall_dist;
}				t_cast;
typedef struct	s_image
{
	void	*img;
	void	*adr;
	int		*iadr;
	int		**tiadr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_h;
	int		img_w;
	double	dist;
}				t_image;
typedef struct	s_tex
{
	t_image tex_no;
	t_image tex_so;
	t_image tex_ea;
	t_image tex_we;
	t_image tex_s;
}				t_tex;
typedef struct	s_cub3d
{
	t_map	map;
	t_path	pars;
	t_cast	cast;
	t_image img;
	t_tex	tex;
	t_move	move;
	t_speed spe;
	int		bool;
}				t_cub3d;

#endif
