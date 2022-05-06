/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:24:40 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/06 17:02:10 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"

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

//TODO this function bruv
void	index_list(Node **head)
{
	Node	*iterator;
	int		min;
	int		l_index;

	iterator = *head;
	min = iterator->data;
	if (*head == NULL)
		return ;
	while (iterator->next != NULL)
	{
		if (iterator->)
		iterator = iterator->next;
	}
}

void	print_list(Node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->val, 1);
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
