/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:40 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 14:01:57 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	append(t_Node **head, int data)
{
	t_Node	*new_node;
	t_Node	*last;

	new_node = (t_Node *)malloc(sizeof(t_Node));
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

int	list_len(t_Node **head)
{
	int		i;
	t_Node	*iterator;

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

int	is_sorted(t_Node *head, int size)
{
	t_Node	*iterator;

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

int	get_max(t_Node *stack)
{
	int		i;
	t_Node	*iterator;

	iterator = stack;
	i = iterator->val;
	while (iterator)
	{
		if (iterator->val > i)
			i = iterator->val;
		iterator = iterator->next;
	}
	return (i);
}

int	get_min(t_Node *stack)
{
	int		i;
	t_Node	*iterator;

	iterator = stack;
	i = iterator->val;
	while (iterator)
	{
		if (iterator->val < i)
			i = iterator->val;
		iterator = iterator->next;
	}
	return (i);
}
