/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:51:31 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/05 14:15:34 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*t_dst;
	const char	*t_src;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	t_dst = (char *) dst;
	t_src = (const char *) src;
	i = 0;
	if (t_dst < t_src)
	{
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
			t_dst[i] = t_src[i];
	}
	return (dst);
}
