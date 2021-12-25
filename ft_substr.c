/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:47:56 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:29:17 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = (char *) malloc(1);
		result[0] = '\0';
		return (result);
	}
	if (ft_strlen(s) - (size_t)start < len)
		result = (char *) malloc((ft_strlen(s) - (size_t)start + 1));
	else
		result = (char *) malloc(len + 1);
	if (result == NULL)
		return (result);
	i = -1;
	while (++i < len && s[start] != '\0')
	{
		result[i] = s[start];
		start++;
	}
	result[i] = '\0';
	return (result);
}
