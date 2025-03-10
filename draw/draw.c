/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:50:29 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/10 17:35:03 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"

//#include "../minilibx_macos/mlx.h"

int	get_scale(int width, int height)
{
	int	scale_x;
	int	scale_y;

	scale_x = 800 / (width + height);
	scale_y = 600 / (width + height);
	if (scale_x < scale_y)
		return (scale_x);
	else
		return (scale_y);
}

int	ft_isometric_x(int x, int y, int scale)
{
	return (((x - y) * cos(0.523599)) * scale + 800 / 2);
}

int	ft_isometric_y(int x, int y, int z, int scale)
{
	return ((((x + y) * sin(0.523599)) - z) * scale + 600 / 2);
}

int	ft_bresenham_dx(int x1, int x2, int *sx)
{
	if (x1 < x2)
		*sx = 1;
	else
		*sx = -1;
	return (abs(x2 - x1));
}

int	ft_bresenham_dy(int y1, int y2, int *sy)
{
	if (y1 < y2)
		*sy = 1;
	else
		*sy = -1;
	return (abs(y2 - y1));
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < 800 && y >= 0 && y < 600)
	// Vérifie que le pixel est dans la fenêtre
	{
		index = (y * img->size_line) + (x * (img->bpp / 8));
		// Trouve l’index du pixel
		*(int *)(img->data + index) = color;
		// Écrit la couleur dans l’image
	}
}

void	ft_draw_line(t_map *map, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = ft_bresenham_dx(x1, x2, &sx);
	dy = ft_bresenham_dy(y1, y2, &sy);
	err = dx - dy;
	while (1)
	{
		put_pixel_to_image(&map->image, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;
	int	proj_x1;
	int	proj_y1;
	int	proj_x2;
	int	proj_y2;
	int	scale;

	x = 0;
	y = 0;
	scale = get_scale(map->width, map->height);
	while (y < map->height)
	{
		while (x < map->width)
		{
			proj_x1 = ft_isometric_x(x, y, scale);
			proj_y1 = ft_isometric_y(x, y, map->map[y][x], scale);
			if (x + 1 < map->width) // verifie pas fin ligne
			{
				proj_x2 = ft_isometric_x(x + 1, y, scale);
				proj_y2 = ft_isometric_y(x + 1, y, map->map[y][x + 1], scale);
				ft_draw_line(map, proj_x1, proj_y1, proj_x2, proj_y2, 0xFFFFFF);
			}
			if (y + 1 < map->height) // verifie pas fin colonne
			{
				proj_x2 = ft_isometric_x(x, y + 1, scale);
				proj_y2 = ft_isometric_y(x, y + 1, map->map[y + 1][x], scale);
				ft_draw_line(map, proj_x1, proj_y1, proj_x2, proj_y2, 0xFFFFFF);
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(map->mlx, map->windows, map->image.img_ptr, 0, 0);
}
