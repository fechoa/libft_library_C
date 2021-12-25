/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:26:21 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:19:13 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	result = (char *) malloc(count * size);
	if (result == NULL)
		return ((void *)(0));
	ft_bzero((void *)result, count * size);
	return ((void *) result);
}
