/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:33:43 by mlaussel          #+#    #+#             */
/*   Updated: 2025/03/04 19:15:42 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	is_white_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

static	int	what_sign(const char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	nb;

	sign = 1;
	nb = 0;
	i = is_white_space(str);
	sign = what_sign(str[i]);
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			if (sign == (-1))
				return (0);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * nb));
}