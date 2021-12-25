/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:50:16 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:30:26 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const ch, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_altresult(void)
{
	char	*result;

	result = (char *) malloc(1);
	if (result == NULL)
		return (result);
	result[0] = '\0';
	return (result);
}

static char	*ft_fillcreate(char const *s1, size_t startIndex, size_t endIndex)
{
	size_t	i;
	char	*result;

	i = 0;
	if (s1[0] == '\0' || startIndex == endIndex)
		result = (char *) malloc(2);
	else
		result = (char *) malloc(endIndex - startIndex + 2);
	if (result == NULL)
		return (result);
	while (startIndex <= endIndex && s1[startIndex])
		result[i++] = s1[startIndex++];
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	i;	

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_checkset(s1[i], set) == 1)
		i++;
	start_index = i;
	if (start_index >= end_index)
		return (ft_altresult());
	i = end_index;
	while (i >= 0 && ft_checkset(s1[i], set) == 1)
		i--;
	end_index = i;
	return (ft_fillcreate(s1, start_index, end_index));
}
