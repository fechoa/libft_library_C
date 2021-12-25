/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:24:14 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/07 13:51:46 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	flag;
	size_t	count;
	size_t	i;

	flag = 0;
	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (count);
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static void	ft_fill_elem(char const *s, char *str, size_t *j, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = s[*j];
		(*j)++;
		i++;
	}
	str[i] = '\0';
}

static char	*ft_init_elem(char const *s, char c, size_t *j)
{
	char	*elem;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[*j] == c && s[i] != '\0')
		(*j)++;
	i = *j;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		size++;
	}		
	elem = (char *) malloc(size + 1);
	if (elem == NULL)
		return (NULL);
	ft_fill_elem(s, elem, j, size);
	return (elem);
}

static void	ft_clear_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	result = (char **) malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (result == NULL)
		return (result);
	result[ft_countwords(s, c)] = NULL;
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		result[i] = ft_init_elem(s, c, &j);
		if (result[i] == NULL)
		{
			ft_clear_all(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
