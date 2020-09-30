/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:04:42 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 19:58:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_spe_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	i--;
	while (str[i] == ' ')
		i--;
	return (i);
}

char	*ft_strdup_spe2(char *str, int size)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (j < size)
	{
		while (!is_space(str[i]) && j < size)
		{
			dst[j] = str[i];
			j++;
			i++;
		}
		if (is_space(str[i]) && j < size)
			dst[j++] = ' ';
		while (is_space(str[i]) && j < size)
			i++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_str_clear_spaces(char *str)
{
	int		i;
	int		j;
	int		spaces;
	int		length;
	char	*clear_str;

	i = 0;
	j = 0;
	spaces = 1;
	length = ft_spe_strlen(str);
	while (i < length && is_printable(str[i]))
	{
		i++;
		if (is_space(str[i]) && i < length)
			spaces++;
		while (is_space(str[i]) && i < length)
		{
			i++;
			j++;
		}
	}
	if (!(clear_str = ft_strdup_spe2(str, (i - j + spaces))))
		return (0);
	return (clear_str);
}
