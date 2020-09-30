/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:59:31 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/27 22:29:04 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/libft.h>

int				ft_check_key(char *key)
{
	int			i;
	static char	*keys[] = {"0", "1", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
		"17", "18", "19", "20", "30", "40", "50", "60", "70", "80",
		"90", "100", "1000", "1000000", "1000000000",
		"1000000000000", "1000000000000000", "1000000000000000000",
		"1000000000000000000000", "1000000000000000000000000",
		"1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"};

	i = 0;
	while (i < 41)
	{
		if (ft_strcmp(key, keys[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				ft_inside(t_key_number *tmp_tab, char *key, int tmp_size)
{
	int	i;

	i = 0;
	while (i < tmp_size)
	{
		if (ft_strcmp(key, tmp_tab[i].key) == 0)
			return (0);
		i++;
	}
	return (1);
}

int				ft_key_valide_fin(char *key, int *nb_zero)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(key);
	if (len != *nb_zero + 1)
		return (0);
	if (key[0] == '1')
	{
		while (i < len)
		{
			if (key[i] != '0')
				return (0);
			i++;
		}
		*nb_zero += 3;
		return (1);
	}
	return (0);
}

int				ft_check(t_key_number *tab, t_key_number *tmp_tab, int size)
{
	int	i;
	int	k;
	int	nb_zero;

	i = -1;
	k = 0;
	nb_zero = 39;
	while (++i < size)
	{
		if (ft_inside(tmp_tab, tab[i].key, k) == 0)
			return (1);
		if (((ft_check_key(tab[i].key) && (ft_inside(tmp_tab, tab[i].key, k)))
					|| (ft_key_valide_fin(tab[i].key, &nb_zero))))
			tmp_tab[k++] = tab[i];
	}
	if (k < 41)
		return (1);
	i = -1;
	k++;
	while (++i < size)
	{
		if (!(ft_check_key(tab[i].key)))
			tmp_tab[k++] = tab[i];
	}
	return (0);
}

t_key_number	*ft_sort_in_tab(t_key_number *tab, int size)
{
	t_key_number	tmp;
	int				i;
	t_key_number	*tmp_tab;

	i = -1;
	if (!(tmp_tab = malloc((size + 1) * sizeof(t_key_number))))
		return (0);
	while (++i < size - 1)
	{
		if (ft_struct_cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
	if (ft_check(tab, tmp_tab, size))
	{
		write(1, "Dict Error\n", 11);
		ft_free_final_tab(tmp_tab, size + 1);
		return (0);
	}
	free(tab);
	return (tmp_tab);
}
