/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:36:16 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/28 21:48:55 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (!begin_list)
		return (0);
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*tmp;

	i = 0;
	size = ft_list_size(begin_list);
	while (i < size / 2)
	{
		tmp = (ft_list_at(begin_list, size - 1 - i))->data;
		(ft_list_at(begin_list, size - 1 - i))->data =
										(ft_list_at(begin_list, i))->data;
		(ft_list_at(begin_list, i))->data = tmp;
		i++;
	}
}
