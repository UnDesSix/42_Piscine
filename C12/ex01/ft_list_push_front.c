/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:54:36 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/29 11:35:32 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_elem, void *data)
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
