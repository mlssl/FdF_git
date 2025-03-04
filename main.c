/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:16:28 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/04 19:15:57 by mathildelau      ###   ########.fr       */
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
    int i;
    
    nb_columns = 0;
    nb_lines = 0;
    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error openning file");
        exit(1);
    }
    while ((line = get_next_line(fd)) != NULL)
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
    map->map = malloc(sizeof(int*) * map->height);
    if (!map->map)
    {
        perror("Erreur d'allocation mémoire pour la matrice");
        close(fd);
        return (-1);
    }
    close(fd);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error openning file");
        exit(1);
    }
    nb_lines = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map->map[nb_lines] = malloc(sizeof(int) * map->width);
        if (!map->map[nb_lines])
        {
            perror("Erreur d'allocation mémoire");
            close(fd);
            return (-1);
        }
        map_char = ft_split(line, ' ');
        while (i < map->width)
        {
            map->map[nb_lines][i] = atoi(map_char[i]);
            i++;
        }
        nb_lines++;
        free(line);
    }
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./fdf <map_file>\n");
        return (1);
    }

    t_map map;
    if (read_map(argv, &map) == -1) {
        printf("Erreur lors de la lecture de la carte.\n");
        return (1);
    }

    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            printf("%d ", map.map[y][x]);
        }
        printf("\n");
    }

    return (0);
}