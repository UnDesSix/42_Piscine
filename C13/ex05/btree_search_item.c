/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:13:06 by mlarboul          #+#    #+#             */
/*   Updated: 2020/09/29 18:35:29 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
												int (*cmpf)(void *, void *))
{
	t_btree *found_itm;

	if (!root || !data_ref)
		return (0);
	if ((found_itm = btree_search_item(root->left, data_ref, cmpf)))
		return (found_itm);
	if (!((*cmpf)(root->item, data_ref)))
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
