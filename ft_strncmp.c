/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:03:45 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/05 15:10:00 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (n == 0)
		return (0);
	while (++i < (n - 1) && s1[i] == s2[i] && s1[i] != '\0')
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
