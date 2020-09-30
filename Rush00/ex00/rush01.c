/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:36:29 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/12 13:26:28 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x, char a, char b, char c)
{
	int i;

	i = 1;
	if (x > 0)
		ft_putchar(a);
	while (i < x - 1)
	{
		ft_putchar(b);
		i++;
	}
	if (x > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	if (y > 0)
		ft_print_line(x, '/', '*', '\\');
	while (i < y - 1)
	{
		ft_print_line(x, '*', ' ', '*');
		i++;
	}
	if (y > 1)
		ft_print_line(x, '\\', '*', '/');
}
