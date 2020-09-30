/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:47:56 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/28 21:32:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **data1, void **data2)
{
	void *temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*elem1;
	t_list	*elem2;
	int		flag_loop;

	if (!(*begin_list) || !((*begin_list)->next))
		return ;
	flag_loop = 1;
	while (flag_loop)
	{
		elem1 = *begin_list;
		elem2 = (*begin_list)->next;
		flag_loop = 0;
		while (elem2)
		{
			if ((*cmp)(elem1->data, elem2->data) > 0)
			{
				ft_swap(&(elem1->data), &(elem2->data));
				flag_loop = 1;
			}
			elem1 = elem1->next;
			elem2 = elem2->next;
		}
	}
}
