/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:55:30 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:10:20 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	ra(Node **head)
{
	Node	*tmp_first;
	Node	*tmp_last;
	Node	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return ;
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

void	pb(Node **a, Node **b)
{
	Node	*tmp;
	Node	*to;
	Node	*from;

	to = *b;
	from = *a;
	if (!from)
	{
		*b = NULL;
		return ;
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

void	pa(Node **a, Node **b)
{
	Node	*tmp;
	Node	*to;
	Node	*from;

	to = *a;
	from = *b;
	if (!from)
	{
		*b = NULL;
		return ;
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
