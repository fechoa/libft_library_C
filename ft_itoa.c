/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:37:50 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 17:13:44 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_check(int n, size_t *count, int *flag)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		(*count)++;
		(*flag) = -1;
		num = -n;
	}
	if (num >= 0 && num <= 9)
		(*count)++;
	else
	{
		(*count)++;
		ft_putnbr_check(num / 10, count, flag);
	}
}

static char	*ft_create(size_t count)
{
	char	*result;

	result = (char *) malloc(count + 1);
	return (result);
}

static long int	ft_abso(int num)
{
	if (num >= 0)
		return ((long int)(num));
	return ((long int) num * -1);
}

static void	ft_fillarr(char *result, long int num, size_t count, int flag)
{
	size_t	i;

	if (count == 12)
		count--;
	if (flag == -1)
		result[0] = '-';
	i = count - 1;
	if (num == 0)
		result[i] = (char)(0 + 48);
	else
	{
		while (num > 0)
		{
			result[i] = (char)(num % 10 + 48);
			num /= 10;
			i--;
		}	
	}	
}

char	*ft_itoa(int n)
{
	size_t		count;
	size_t		i;
	long int	num;
	int			flag;
	char		*result;

	count = 0;
	i = 0;
	flag = 1;
	ft_putnbr_check(n, &count, &flag);
	num = ft_abso(n);
	result = ft_create(count);
	if (result == NULL)
		return (result);
	ft_fillarr(result, num, count, flag);
	result[count] = '\0';
	return (result);
}
