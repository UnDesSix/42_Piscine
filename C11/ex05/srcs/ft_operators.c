/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:26:25 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/21 14:52:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	ft_mult(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ft_div(int a, int b)
{
	if (b)
		ft_putnbr(a / b);
	else
		write(1, "Stop : division by zero", 23);
	write(1, "\n", 1);
}

void	ft_mod(int a, int b)
{
	if (b)
		ft_putnbr(a % b);
	else
		write(1, "Stop : modulo by zero", 21);
	write(1, "\n", 1);
}
