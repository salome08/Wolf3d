/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:17:10 by shazan            #+#    #+#             */
/*   Updated: 2015/12/15 14:17:20 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	distance_mur(t_pos *pos, t_image *im)
{
	int	i;

	i = 0;
	input_font(im);
	im->a = -30.0;
	while (i < LENGHT)
	{
		pos->dist = dist_one_ray(pos, im);
		pos->size_col = (1.0 / pos->dist) * 720.0;
		draw_col(pos, im);
		(pos->angle) += (60.0 / LENGHT);
		i++;
	}
	pos->angle = pos->angle - 60;
	mlx_put_image_to_window(im->mlx, im->win, im->img, 0, 0);
}

double	dist_one_ray(t_pos *pos, t_image *im)
{
	double	d;
	float	cosi;
	float	sini;

	pos->tmpx = pos->posx;
	pos->tmpy = pos->posy;
	cosi = cos((pos->angle) / 180.0 * M_PI);
	sini = -sin((pos->angle) / 180.0 * M_PI);
	d = 0.001;
	while (pos->lap[(int)pos->tmpy][(int)pos->tmpx] != 1)
	{
		pos->tmpy = pos->posy + cosi * d;
		if (pos->lap[(int)pos->tmpy][(int)pos->tmpx] != 1)
			im->mur = 1;
		pos->tmpx = pos->posx + sini * d;
		if (pos->lap[(int)pos->tmpy][(int)pos->tmpx] != 1)
			im->mur = 2;
		d += 0.001;
	}
	im->pos2x = pos->tmpx;
	im->pos2y = pos->tmpy;
	d = d * (cos((im->a) / 180.0 * M_PI));
	im->a += 60.0 / LENGHT;
	return (d);
}

int		key_hook(int keycode, t_image *im)
{
	double tmpx;
	double tmpy;

	if (keycode == 124 || keycode == 123 || keycode == 53)
		key_next(keycode, im);
	if (keycode == 126)
	{
		tmpy = im->pos->posy + cos((im->pos->angle + 30) / 180.0 * M_PI);
		tmpx = im->pos->posx - sin((im->pos->angle + 30) / 180.0 * M_PI);
		if (im->pos->lap[(int)tmpy][(int)tmpx] == 1)
			return (0);
		im->pos->posx = tmpx;
		im->pos->posy = tmpy;
	}
	if (keycode == 125)
	{
		tmpy = im->pos->posy - cos((im->pos->angle + 30) / 180.0 * M_PI);
		tmpx = im->pos->posx + sin((im->pos->angle + 30) / 180.0 * M_PI);
		if (im->pos->lap[(int)tmpy][(int)tmpx] == 1)
			return (0);
		im->pos->posx = tmpx;
		im->pos->posy = tmpy;
	}
	return (0);
}

void	key_next(int keycode, t_image *im)
{
	if (keycode == 124)
	{
		im->pos->angle += 3;
	}
	if (keycode == 123)
	{
		im->pos->angle -= 3;
	}
	if (keycode == 53)
		exit(0);
}

void	color_wall(t_image *im, int x, int y)
{
	if (im->mur == 1)
	{
		if (im->pos->posx >= im->pos2x)
			put_pixel_to_image(im, x, y, 0xFF6600);
		else
			put_pixel_to_image(im, x, y, 0xFFCC00);
	}
	else if (im->mur == 2)
	{
		if (im->pos->posy >= im->pos2y)
			put_pixel_to_image(im, x, y, 0x6633FF);
		else
			put_pixel_to_image(im, x, y, 0xCC6699);
	}
}
