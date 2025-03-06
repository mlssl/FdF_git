/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:14:05 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/06 16:56:52 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parsing(t_map *map, char **argv)
{
	char *line;
	char **map_char;
	int fd;
	int i;

	fd = open_fd(argv);
	while ((line = get_next_line(fd)) != NULL)
	{
        i = 0;
		map->map[map->height] = malloc(sizeof(int) * map->width);
		if (map->map[map->height] == NULL)
		{
			free(line);
			close(fd);
			error("Memory allocation failed", 1);
		}
		map_char = ft_split(line, ' ');
		while (i < map->width)
		{
			map->map[map->height][i] = atoi(map_char[i]);
			i++;
		}
		map->height++;
		//free(line); //ne fonctionne pas mais je dois bien libérer
	}
	close(fd);
}

int	read_map(char **argv, t_map *map)
{
	int		fd;

    fd = open_fd(argv);
	if (count_width(map, fd) == -1)
	{
		close(fd);
		error("Error width map", -1);
	}
	count_height(map, fd);
	map->map = malloc(sizeof(int *) * map->height);
	if (!map->map)
	{
		close(fd);
		error("Memory allocation failed", 1);
	}
	close(fd); // car on veut rouvrir depuis le début
	parsing(map, argv);
	close(fd);
	return (0);
}
