/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_str_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:32:38 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/24 17:23:52 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstr(char *str, int output)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(output, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncpy(char *src, int n)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		special_cmp(char *s1, char *s2, int size)
{
	int i;

	i = 0;
	if (size != 16)
		return (1);
	while (i < 16 && s1[i] == s2[i])
		i++;
	if (i == 16)
		return (0);
	return (1);
}
