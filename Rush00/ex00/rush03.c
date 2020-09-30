/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:34:58 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/12 13:27:04 by mlarboul         ###   ########.fr       */
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
		ft_print_line(x, 'A', 'B', 'C');
	while (i < y - 1)
	{
		ft_print_line(x, 'B', ' ', 'B');
		i++;
	}
	if (y > 1)
		ft_print_line(x, 'A', 'B', 'C');
}
