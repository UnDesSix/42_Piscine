/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:29:53 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/14 15:30:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_base_is_ok(char *base);
int		ft_strlen(char *str);

int		ft_compute_str_size(long int nbr, char *base_to)
{
	int count;

	if (nbr == 0)
		count = 1;
	else
		count = 0;
	while (nbr)
	{
		count++;
		nbr = nbr / ft_strlen(base_to);
	}
	return (count);
}

void	ft_convert_dec_to_base(long int nbr, int size,
											char *base_to, char *nbr_converted)
{
	int i;

	i = 2;
	while (nbr)
	{
		nbr_converted[size - i] = base_to[nbr % ft_strlen(base_to)];
		nbr = nbr / ft_strlen(base_to);
		i++;
	}
	nbr_converted[size - 1] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			size_nbr_converted;
	long int	nbr_int;
	char		*nbr_converted;

	if (!ft_base_is_ok(base_from) || !ft_base_is_ok(base_to))
		return (0);
	nbr_int = (long int)ft_atoi_base(nbr, base_from);
	if (nbr_int < 0)
	{
		nbr_int = -1 * nbr_int;
		size_nbr_converted = 1 + ft_compute_str_size(nbr_int, base_to) + 1;
		if (!(nbr_converted = malloc(sizeof(char) * size_nbr_converted)))
			return (0);
		nbr_converted[0] = '-';
	}
	else
	{
		size_nbr_converted = ft_compute_str_size(nbr_int, base_to) + 1;
		if (!(nbr_converted = malloc(sizeof(char) * size_nbr_converted)))
			return (0);
		nbr_converted[0] = base_to[0];
	}
	ft_convert_dec_to_base(nbr_int, size_nbr_converted, base_to, nbr_converted);
	return (nbr_converted);
}
