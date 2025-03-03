/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:16:28 by mathildelau       #+#    #+#             */
/*   Updated: 2025/02/26 14:31:25 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../includes/fdf.h"

int read_map(char **argv, t_map *map)
{
    int fd;
    char  *line;
    char **map_char;
    int nb_columns;
    int nb_lines;
    
    nb_columns = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perrror("Error openning file");
        exit(1);
    }
    while ((line = get_next_line(fd)) ! NULL)
    {
        map_char = ft_split(line, ' ');
        while (map_char[nb_columns] != NULL)
            nb_columns++;
        if (nb_lines == 0)
            map->width = nb_columns;
        nb_lines++;
        free(line);
    }
    map->height = nb_lines;
    map->map = malloc(sizeof(int**) * map->height);
    if (!map->map)
    {
        perror("Erreur d'allocation mémoire pour la matrice");
        close(fd);
        return (NULL);
    }
}

int main() {
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "MiniLibX Test");
    mlx_loop(mlx);
    return 0;
}