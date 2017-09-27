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

#include "wolf3d.h"
#include <stdio.h>

int		main(void)
{
	t_image	im;
	t_pos	pos;

	im.pos = &pos;
	im.mlx = mlx_init();
	init_all(&pos);
	im.win = mlx_new_window(im.mlx, LENGHT, HEIGHT, "Wold3D");
	im.img = mlx_new_image(im.mlx, LENGHT, HEIGHT);
	im.data = mlx_get_data_addr(im.img, &im.bpp, &im.size_line, &im.endian);
	mlx_expose_hook(im.win, gere_expose, &im);
	mlx_key_hook(im.win, key_hook, &im);
	mlx_hook(im.win, KeyPress, KeyPressMask, key_hook, &im);
	mlx_loop_hook(im.mlx, mlxloop, &im);
	mlx_loop(im.mlx);
	return (0);
}

void	init_all(t_pos *pos)
{
	pos->posx = 2;
	pos->posy = 3;
	pos->angle = -30;
	map(pos);
}

void	map(t_pos *pos)
{
	static int	lap[MAPWIDTH][MAPHEIGHT] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	map_next(pos, lap);
}

void	map_next(t_pos *pos, int lap[MAPWIDTH][MAPHEIGHT])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!(pos->lap = (int **)malloc(sizeof(int *) * MAPHEIGHT)))
		return ;
	while (x <= MAPHEIGHT)
	{
		if (!(pos->lap[x] = (int *)malloc(sizeof(int) * MAPWIDTH)))
			return ;
		x++;
	}
	x = 0;
	while (x < MAPHEIGHT)
	{
		y = 0;
		while (y < MAPWIDTH)
		{
			pos->lap[x][y] = lap[x][y];
			y++;
		}
		x++;
	}
}

int		mlxloop(t_image *im)
{
	distance_mur(im->pos, im);
	return (0);
}
