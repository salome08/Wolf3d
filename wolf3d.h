/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:24:16 by shazan            #+#    #+#             */
/*   Updated: 2015/05/19 18:44:18 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include "minilibx_macos/X.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# define MAPWIDTH 14
# define MAPHEIGHT 14
# define LENGHT 800
# define HEIGHT 600

typedef struct	s_pos
{
	double	posx;
	double	posy;
	double	angle;
	double	dist;
	int		size_col;
	double	tmpx;
	double	tmpy;
	int		**lap;
}				t_pos;

typedef struct	s_image
{
	void	*mlx;
	void	*win;
	void	*img;
	double	a;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		mur;
	double	pos2x;
	double	pos2y;
	t_pos	*pos;
}				t_image;

void			color_wall(t_image *im, int x, int y);
int				mlxloop (t_image *im);
int				key_hook(int keycode, t_image *im);
void			distance_mur(t_pos *pos, t_image *im);
double			dist_one_ray(t_pos *pos, t_image *im);
void			input_font(t_image *im);
int				gere_expose(t_image *im);
void			init_all(t_pos *pos);
void			draw_col(t_pos *pos, t_image *im);
void			put_pixel_to_image(t_image *im, int x, int y, int color);
void			map(t_pos *pos);
void			key_next(int keycode, t_image *im);
void			map_next(t_pos *pos, int lap[MAPWIDTH][MAPHEIGHT]);

#endif
