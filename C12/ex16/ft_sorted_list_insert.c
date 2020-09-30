/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:51:51 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/29 12:06:15 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	my_list_push_front(t_list **begin_elem, void *data)
{
	t_list	*elem;

	if (!(*begin_elem))
		*begin_elem = ft_create_elem(data);
	else
	{
		elem = ft_create_elem(data);
		elem->next = *begin_elem;
		*begin_elem = elem;
	}
}

void	my_ft_swap(void **data1, void **data2)
{
	void *temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void	my_ft_list_sort(t_list **begin_list, int (*cmp)())
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
				my_ft_swap(&(elem1->data), &(elem2->data));
				flag_loop = 1;
			}
			elem1 = elem1->next;
			elem2 = elem2->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	my_list_push_front(begin_list, data);
	my_ft_list_sort(begin_list, cmp);
}
