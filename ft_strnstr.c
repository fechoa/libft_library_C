/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:45:34 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/05 16:32:08 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (i < len && haystack[i] != '\0' && ft_strlen(needle) + i <= len)
	{
		j = 0;
		tmp = i;
		while (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[tmp]);
			j++;
			i++;
		}
		i = tmp;
		i++;
	}
	return (NULL);
}
