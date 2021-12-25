/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:07:14 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/06 16:19:09 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = (long int)n * -1;
	}
	if (num >= 0 && num <= 9)
		ft_putchar_fd((char)(num + 48), fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((char)(num % 10 + 48), fd);
	}
}
