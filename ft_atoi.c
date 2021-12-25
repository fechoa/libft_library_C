/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:11:15 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 16:55:31 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char ch)
{
	if (ch == 32 || ch == '\r' || ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f')
		return (1);
	return (0);
}

static int	ft_isnumch(char ch)
{
	return (ch >= '0' && ch <= '9');
}

static void	ft_cycle(const char *str, long long *result)
{
	while (ft_isnumch(*str))
	{
		*result = *result * 10 + *str - 48;
		str++;
	}
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			flag;
	int			count;

	while (ft_iswhitespace(*str))
		str++;
	flag = 1;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	count = 0;
	ft_cycle(str, &result);
	if (flag == -1)
		result = -result;
	if (result <= 2147483647 && result >= -2147483648)
		return ((int)result);
	else if (flag == 1)
		return (-1);
	return (0);
}
