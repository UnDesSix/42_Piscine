/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_functions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:38:04 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 19:18:24 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_n(char *str, int n)
{
	char	*dst;
	int		i;

	i = 1;
	if (!(dst = malloc(sizeof(char) * (n + 1))))
		return (0);
	dst[0] = str[0];
	while (i < n)
		dst[i++] = '0';
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(char *str, int n)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
