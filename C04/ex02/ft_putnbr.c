/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:10:45 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/11 09:10:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdigit(char digit)
{
	digit += 48;
	write(1, &digit, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nbr * -1);
		return ;
	}
	if (nbr < 10)
	{
		ft_putdigit(nbr);
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putdigit(nbr % 10);
}
