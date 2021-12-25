/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:37:45 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:20:28 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;
	size_t	maxlen;

	maxlen = ft_strlen(s1);
	if (maxlen > 0)
		result = (char *) ft_calloc(maxlen + 1, 1);
	else
	{
		result = (char *) malloc(1);
		result[0] = '\0';
		return (result);
	}
	if (result == NULL)
	{
		errno = ENOMEM;
		return ((void *)(0));
	}
	i = -1;
	while (++i < maxlen)
		result[i] = (char) s1[i];
	return (result);
}
