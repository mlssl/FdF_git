/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:36:53 by mlaussel          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:11 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

static int	is_charc(char sentence, char set)
{
	if (sentence == set)
		return (0);
	return (1);
}

static int	count_word(const char *sentence, char set)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (sentence[i] != '\0')
	{
		while (sentence[i] != '\0' && is_charc(sentence[i], set) == 0)
			i++;
		if (sentence[i] != '\0')
			word++;
		while (sentence[i] != '\0' && is_charc(sentence[i], set) == 1)
			i++;
	}
	return (word);
}

static char	*space_and_copy_line(const char *sentence, char set, int i)
{
	char	*dest;
	int		len;
	int		j;
	int		save_i;

	len = 0;
	j = 0;
	save_i = i;
	while (sentence[save_i] != '\0' && is_charc(sentence[save_i], set))
	{
		save_i++;
		len++;
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (sentence[i] != '\0' && is_charc(sentence[i], set) == 1)
	{
		dest[j] = sentence[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	**ft_all_copy(char **dest, const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_charc(s[i], c) == 0)
			i++;
		if (s[i] != '\0')
		{
			dest[j] = space_and_copy_line(s, c, i);
			if (dest[j] == NULL)
			{
				while (j >= 0)
					free(dest[j--]);
				free(dest);
				return (NULL);
			}
			j++;
		}
		while (s[i] != '\0' && is_charc(s[i], c) == 1)
			i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		word;
	int		i;

	i = 0;
	word = count_word(s, c);
	if (s == NULL)
		return (NULL);
	word = count_word(s, c);
	dest = malloc(sizeof(char *) * (word + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_all_copy(dest, s, c, i);
	return (dest);
}