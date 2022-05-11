/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:01:17 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:45:56 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

int	get_index(t_Node *head, int val)
{
	int		count;
	t_Node	*iterator;

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

void	index_list(t_Node *head)
{
	t_Node	*iterator;

	iterator = head;
	if (head == NULL)
		return ;
	while (iterator->next != NULL)
	{
		iterator->index = get_index(head, iterator->val);
		iterator = iterator->next;
	}
	iterator->index = get_index(head, iterator->val);
}

t_Node	*stack_init(char **list, int len)
{
	t_Node	*head;
	t_Node	*temp;
	int		i;

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
