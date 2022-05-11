/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:55:30 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:45:16 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	ra(t_Node **head)
{
	t_Node	*tmp_first;
	t_Node	*tmp_last;
	t_Node	*stack;

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

void	pb(t_Node **a, t_Node **b)
{
	t_Node	*tmp;
	t_Node	*to;
	t_Node	*from;

	to = *b;
	from = *a;
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

void	pa(t_Node **a, t_Node **b)
{
	t_Node	*tmp;
	t_Node	*to;
	t_Node	*from;

	to = *a;
	from = *b;
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
