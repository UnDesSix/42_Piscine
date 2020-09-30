/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 09:59:13 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/13 10:55:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11 || nb == 13)
		return (1);
	if (!(nb % 2) || !(nb % 3) || !(nb % 5)
						|| !(nb % 7) || !(nb % 11) || !(nb % 13))
		return (0);
	i = 17;
	while (i <= nb / i)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}
