/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:00:21 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/20 15:17:40 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscrapper.h"

int		ft_put_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_size_of_n_from_char(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len != 23 && len != 31 && len != 39)
		return (0);
	return ((len + 1) / 8);
}

int		ft_is_valid_pov(char c, int n)
{
	if (c >= '1' && c <= (n + '0'))
		return (1);
	return (0);
}

int		*check_n_convert_views(char *str)
{
	int i;
	int sq_size;
	int	*views;

	if (!(sq_size = ft_size_of_n_from_char(str)))
		return (0);
	if (!(views = malloc(sizeof(int) * (sq_size * 4 + 1))))
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(i % 2) && !ft_is_valid_pov(str[i], sq_size))
			return (0);
		else if ((i % 2) && str[i] != ' ')
			return (0);
		if (!(i % 2) && ft_is_valid_pov(str[i], sq_size))
			views[i / 2] = str[i] - 48;
		i++;
	}
	views[sq_size * 4] = 0;
	return (views);
}

int		ft_sky_scrapper(int argc, char **argv)
{
	int	*views;

	if (argc != 2)
		return (ft_put_error());
	if (!(views = check_n_convert_views(argv[1])))
		return (ft_put_error());
	if (!generate_and_check(views))
		return (ft_put_error());
	free(views);
	return (0);
}
