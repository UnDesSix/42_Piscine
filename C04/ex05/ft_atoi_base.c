/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:58:09 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/12 14:11:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
						|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_position_base(char *base, char c)
{
	int i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
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
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
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

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	result = 0;
	if (!ft_base_is_ok(base))
		return (0);
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_position_base(base, str[i]) != -1)
	{
		result = ft_position_base(base, str[i]) + result * ft_strlen(base);
		i++;
	}
	return (sign * result);
}
