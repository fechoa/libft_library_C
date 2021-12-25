/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:43:39 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:35:23 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char const *s1, char const *s2, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (result);
	ft_fill(s1, s2, result);
	return (result);
}
