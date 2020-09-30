/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 07:51:14 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/08 08:20:13 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdigit(char digit)
{
	digit += 48;
	write(1, &digit, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_putdigit(a / 10);
			ft_putdigit(a % 10);
			write(1, " ", 1);
			ft_putdigit(b / 10);
			ft_putdigit(b % 10);
			if (a != 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
