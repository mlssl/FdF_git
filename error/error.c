/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:06 by mathildelau       #+#    #+#             */
/*   Updated: 2025/03/06 16:21:52 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(char *msg, int e)
{
	perror(msg);
	exit(e);
}

int    open_fd(char **argv)
{
    int fd; 
    
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        close (fd);
        error("Error openning file", 1);
    }
    return (fd);
}