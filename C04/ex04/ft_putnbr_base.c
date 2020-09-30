/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:18:19 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/13 11:11:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_base_is_ok(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	if (!ft_base_is_ok(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(2147483648 / base_len, base);
		ft_putnbr_base(2147483648 % base_len, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < base_len)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	ft_putnbr_base(nbr / base_len, base);
	ft_putnbr_base(nbr % base_len, base);
}
