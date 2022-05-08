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

int empty(Node *stack)
{
	if (!stack)
		return (1);
	return (0);
}

void prepend(Node **head, int val, int index)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->val = val;
	newNode->index = index;

	if (*head != NULL)
		newNode->next = *head;
	else
		newNode->next = NULL;
	head = &newNode;
}

void append(Node **head, int data)
{
	Node *new_node;
	Node *last;

	new_node = (Node *)malloc(sizeof(Node));
	last = *head;
	new_node->val = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

int list_len(Node **head)
{
	int i;
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

int is_sorted(Node *head, int size)
{
	Node *iterator;
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

int get_index(Node *head, int val)
{
	int count;
	Node *iterator;

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

void print_list(Node *head)
{
	if (!head)
	{
		ft_putstr_fd("NULL LIST\n", 1);
		return;
	}
	while (head->next != NULL)
	{
		ft_putnbr_fd(head->val, 1);
		ft_putstr_fd(" ", 1);
		head = head->next;
	}
	ft_putnbr_fd(head->val, 1);
	ft_putstr_fd("\n", 1);
}

void print_list_index(Node *head)
{
	while (head != NULL)
	{
		ft_putnbr_fd(head->index, 1);
		head = head->next;
	}
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

void ra(Node **head)
{
	Node *tmp_first;
	Node *tmp_last;
	Node *stack;

	stack = *head;
	if (!(stack && stack->next))
		return;
	tmp_first = stack;
	stack = stack->next;
	tmp_last = stack;
	while (tmp_last->next)
		tmp_last = tmp_last->next;
	tmp_last->next = tmp_first;
	tmp_first->next = NULL;
	*head = stack;
	ft_putstr_fd("ra\n", 1);
}

void pb(Node **a, Node **b)
{
	Node *tmp;
	Node *to;
	Node *from;

	to = *b;
	from = *a;
	if (!from)
	{
		*b = NULL;
		return;
	}
	tmp = from;
	from = from->next;
	*a = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*b = to;
	}
	else
	{
		tmp->next = to;
		*b = tmp;
	}
	ft_putstr_fd("pb\n", 1);
}

void pa(Node **a, Node **b)
{
	Node *tmp;
	Node *to;
	Node *from;

	to = *a;
	from = *b;
	if (!from)
	{
		*b = NULL;
		return;
	}
	tmp = from;
	from = from->next;
	*b = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*a = to;
	}
	else
	{
		tmp->next = to;
		*a = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}

void sort_list(Node *a, Node *b)
{
	int size;
	int i;
	int j;
	int num;

	i = 0;
	size = list_len(&a);
	while (!is_sorted(a, size))
	{
		j = 0;
		while (j < size)
		{
			num = a->index;
			if ((num >> i) & 1)
				ra(&a);
			else
				pb(&a, &b);
			j++;
		}
		i++;
		while (!empty(b))
			pa(&a, &b);
	}
	print_list(a);
}