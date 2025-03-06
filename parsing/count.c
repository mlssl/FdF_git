/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:14:37 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/06 20:23:36 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int count_width(t_map *map, int fd)
{
    char   *line;
    char **map_char;
    int nb_columns;
    int save;

    nb_columns = 0;
    save = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map_char = ft_split(line, ' ');
        while (map_char[nb_columns] != NULL)
            nb_columns++;
        if (save == 0)
            save = nb_columns;
        else if (save != nb_columns || nb_columns < 2)
        {
            free(line);
            //return (-1);
            return (1);
        }   
        free(line);
    }
    map->width = nb_columns;
    return (1);
}

void count_height(t_map *map, int fd)
{
    char   *line;
    int nb_lines;

    nb_lines = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        nb_lines++;
        free(line);
    }
    map->height = nb_lines;
}
