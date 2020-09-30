/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:03:37 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/09 13:34:34 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_uppercase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	ft_lowercase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

int		ft_is_a_separator(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
											|| (c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int		ft_is_first_letter(char *str, int i)
{
	if (i == 0)
		return (1);
	if (ft_is_a_separator(str[i - 1]) && !ft_is_a_separator(str[i]))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_first_letter(str, i))
			ft_uppercase(&str[i]);
		else
			ft_lowercase(&str[i]);
		i++;
	}
	return (str);
}
