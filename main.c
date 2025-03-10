/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:16:28 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/10 17:39:19 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx_macos/mlx.h"
#include "includes/fdf.h"
#include "minilibx/mlx.h"

/*VERIFIER LE PARSING - SUPPRIMER*/
void	check_parsing(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	printf("heigth : %d \n", map->height);
	printf("width : %d \n\n", map->width);
	while (y < map->height)
	{
		while (x < map->width)
		{
			printf("%d ", map->map[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
	printf("\n");
}

int	handle_keypress(int keycode, void *param)
{
	if (keycode == 65307) // Code de la touche ESC
	{
		// Fermer la fenêtre et sortir
		mlx_destroy_window(param, param); // param correspond à la fenêtre
		exit(0);                          // Quitter le programme
	}
	return (0); // Retourner 0 pour indiquer qu'on a bien géré l'événement
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: ./fdf <map_file>\n");
		return (1);
	}
	if (read_map(argv, &map) == -1)
	{
		printf("Erreur lors de la lecture de la carte.\n");
		return (1);
	}
	check_parsing(&map);
	map.mlx = mlx_init(); // init mlx
	if (!map.mlx)
		error("Error init MiniLibX", 1);
	map.windows = mlx_new_window(map.mlx, 800, 600, "FDF"); // créer fenêtre
	if (!map.windows)
		error("Error windows created", 1);
	map.image.img_ptr = mlx_new_image(map.mlx, 800, 600); // initialiser image
	if (!map.image.img_ptr)
		error("Error creating image", 1);
	map.image.data = mlx_get_data_addr(map.image.img_ptr, &map.image.bpp,
			&map.image.size_line, &map.image.endian);
	draw_map(&map);
	mlx_loop(map.mlx);
	mlx_key_hook(map.windows, handle_keypress, map.mlx);
	return (0);
}
