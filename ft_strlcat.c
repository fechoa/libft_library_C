/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:09:01 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/07 09:32:45 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	j;
	size_t	size_s;
	size_t	size_d;

	size_s = ft_strlen(src);
	size_d = ft_strlen(dst);
	if (dstsize == 0)
		return (size_s);
	if (dstsize > size_d)
	{
		i = -1;
		j = 0;
		while (dst[j])
			j++;
		while (j + 1 < dstsize && src[++i])
		{
			dst[j] = src[i];
			j++;
		}
		dst[j] = '\0';
		return (size_d + size_s);
	}
	return (dstsize + size_s);
}
