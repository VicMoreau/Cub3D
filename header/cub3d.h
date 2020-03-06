/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:13:04 by vmoreau           #+#    #+#             */
/*   Updated: 2020/03/06 16:31:28 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV 0.66
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# define G 123
# define F 3
# define DR 124
# define MS 0.2
# define RS 0.080
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_mms_20191207_beta/mlx.h"
# include "../Libft/header/libft.h"
# include "color.h"
# include "struct.h"
/*
** PARSING
*/
int				parsing_fd(t_path *pars, t_map *map, char *fdm);
int				pars_map(t_map *map, int fd, char *str2, t_path *pars);
void			free_split(char **split);
int				strlen_c(char *str, char c, char d);
void			fill_8(int **map, int x, int y, int max);
void			from_0_to_8(t_map *map, int y, int x);
char			*clean_space(char **str);
int				strisnum(char *str);
int				check_map(t_map *map, t_path *pars);
int				check_closed_map(t_map *map, int y, int x);
void			init_struct_pars(t_path *pars, t_map *map);
/*
** GAME
*/
void			init_dir(t_map map, t_cast *cast);
void			init_plane(t_cast *cast);
void			check_dir_plane(t_cub3d *cub);
void			init_world_color(t_cub3d *cub, int *sky, int *floor);
int				darkness_mode(int color, double wall_dist);
void			start(t_cub3d *cub);
void			init_img_struct(t_cub3d *cub);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
void			put_mini_map(t_cub3d *cub);
void			display(t_cub3d *cub);
/*
** IMAGES
*/
void			set_images(t_cub3d *cub);
void			print_img(double wall_dist, int side, t_cub3d *cub, int x);
void			save(t_cub3d *cub);
int				tab_text(t_image *img);
/*
** EVENT
*/
int				refresh(t_cub3d *cub);
void			event(t_cub3d *cub);
void			check_key_on(t_cub3d *cub);
void			init_move_ev(t_move	*move);
void			init_speed(t_speed *spe);
int				key_hook(int keycode, t_cub3d *cub);
void			move_w_s(t_cub3d *cub, int keycode);
void			move_a_d(t_cub3d *cub, int keycode);
void			rotate_g_dr(t_cub3d *cub, int keycode);
/*
** OTHER
*/
int				close_prog(t_cub3d *cub);
void			init_camera(t_cast *cast, t_path pars, int x);
void			free_struct(t_path *pars, t_map *map);
void			ray_cast(t_cub3d *cub);
/*
** A DEGAGER
*/
void			print(char **split);
void			print_int(t_map *coor);
#endif
