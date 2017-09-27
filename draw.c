/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <shazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:35:34 by shazan            #+#    #+#             */
/*   Updated: 2015/12/02 14:35:44 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel_to_image(t_image *im, int x, int y, int color)
{
	if (x < LENGHT && y < HEIGHT && x >= 0 && y >= 0)
	{
		ft_memcpy(&(im->data[(x * (im->bpp / 8)) + \
			(y * im->size_line)]), &color, sizeof(int));
	}
}

void	draw_col(t_pos *pos, t_image *im)
{
	int			i;
	int			y;
	static	int x = 0;

	i = 0;
	y = (HEIGHT - pos->size_col) / 2;
	while (i < pos->size_col)
	{
		color_wall(im, x, y);
		y++;
		i++;
	}
	x++;
	if (x == LENGHT)
		x = 0;
}

void	input_font(t_image *im)
{
	int	i;
	int	color;

	i = 0;
	while (i < LENGHT * HEIGHT)
	{
		color = (i > (HEIGHT * LENGHT) / 2) ? 0x856D4D : 0x77B5FE;
		put_pixel_to_image(im, i % LENGHT, i / LENGHT, color);
		i++;
	}
}

int		gere_expose(t_image *im)
{
	mlx_put_image_to_window(im->mlx, im->win, im->img, 0, 0);
	return (0);
}
