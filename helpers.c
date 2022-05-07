/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:40 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/07 16:33:08 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	append(Node **head, int data)
{
	Node	*new_node;
	Node	*last;

	new_node = (Node *) malloc(sizeof(Node));
	last = *head;
	new_node->val = data;
	new_node->index = 0;
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

int		list_len(Node **head)
{
	int	i;
	Node *iterator;

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

int		is_sorted(Node *head)
{
	Node	*iterator;

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

int		get_index(Node *head, int val)
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

void	index_list(Node *head)
{
	Node	*iterator;

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

void	print_list(Node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->val, 1);
		head = head->next;
	}
}

void	print_list_index(Node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->index, 1);
		head = head->next;
	}
}

Node	*stack_init(char **list, int len)
{
	Node *head;
	int	i;

	head = NULL;
	i = 0;
	while(++i < len)
		append(&head, ft_atoi(list[i]));
	return (head);
}
