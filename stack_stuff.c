/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:01:17 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:01:19 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

int	get_index(Node *head, int val)
{
	int		count;
	Node	*iterator;

	iterator = head;
	count = 0;
	while (iterator)
	{
		if (iterator->val < val)
			count++;
		iterator = iterator->next;
	}
	return (count);
}

void index_list(Node *head)
{
	Node *iterator;

	iterator = head;
	if (head == NULL)
		return;
	while (iterator->next != NULL)
	{
		iterator->index = get_index(head, iterator->val);
		iterator = iterator->next;
	}
	iterator->index = get_index(head, iterator->val);
}

Node *stack_init(char **list, int len)
{
	Node *head;
	Node *temp;
	int i;

	head = NULL;
	i = 0;
	while (++i < len)
		append(&head, ft_atoi(list[i]));
	temp = head;
	while (temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
	return (head);
}
