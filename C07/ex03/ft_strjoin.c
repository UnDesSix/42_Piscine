/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:06:30 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/14 11:31:17 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_stlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_compute_final_size(int size, char **strs, char *sep)
{
	int i;
	int tot;

	i = 0;
	tot = 0;
	while (i < size)
	{
		tot = tot + ft_stlen(strs[i]);
		i++;
	}
	if (!size)
		return (1);
	tot = tot + ft_stlen(sep) * (size - 1) + 1;
	return (tot);
}

char	*ft_strcat(char *dst, char *src)
{
	int i;
	int j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*final_str;

	i = 0;
	str_len = ft_compute_final_size(size, strs, sep);
	if (!(final_str = malloc(sizeof(char) * str_len)))
		return (0);
	final_str[0] = '\0';
	while (i < size)
	{
		ft_strcat(final_str, strs[i]);
		if (i < size - 1)
			ft_strcat(final_str, sep);
		i++;
	}
	return (final_str);
}
