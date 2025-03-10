/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:41 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/10 17:39:30 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

typedef struct s_img
{
	void *img_ptr; // pointeur vers l'image dans la mémoire
	char *data;    // données brutes de l'image
	int bpp;       // bits par pixels
	int size_line; // taille en octets de chaque ligne de l'image
	int		endian;

}			t_img;

/*Par exemple, si vous avez une image de 800x600
pixels en RGB (24 bits par pixel),
la taille d'une ligne sera de 800 * 3 = 2400 octets
(car chaque pixel occupe 3 octets).
Si l'image a un padding (espaces supplémentaires pour l'alignement mémoire),
la size_line sera plus grande.*/

/*endian représente l'ordre des octets dans lequel les couleurs sont stockées.
Cela dépend du système utilisé :
	Big-endian : les octets les plus significatifs sont stockés en premier.
	Little-endian : les octets les moins significatifs
	sont stockés en premier.*/

typedef struct map
{
	int		**map;
	int		width;
	int		height;
	void	*mlx;
	void	*windows;
	t_img	image;
}			t_map;

/*utils*/
char		**ft_split(const char *s, char c);
int			ft_atoi(const char *str);
char		*get_next_line(int fd);

/*error*/
void		error(char *msg, int e);
int			open_fd(char **argv);

/*parsing*/
int			read_map(char **argv, t_map *map);
void		parsing(t_map *map, char **argv);
int			count_width(t_map *map, int fd);
void		count_height(t_map *map, int fd);

/*draw*/
void		draw_map(t_map *map);

#endif
