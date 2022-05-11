/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:40 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 11:58:09 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	append(Node **head, int data)
{
	Node	*new_node;
	Node	*last;

	new_node = (Node *)malloc(sizeof(Node));
	last = *head;
	new_node->val = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

int	list_len(Node **head)
{
	int		i;
	Node	*iterator;

	i = 0;
	iterator = *head;
	while (iterator->next != NULL)
	{
		i++;
		iterator = iterator->next;
	}
	i++;
	return (i);
}

int	is_sorted(Node *head, int size)
{
	Node	*iterator;

	if (list_len(&head) < size)
		return (0);
	iterator = head;
	while (iterator)
	{
		if (iterator->next == NULL)
			return (1);
		if (iterator->val > iterator->next->val)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}
