/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:00:56 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 13:53:41 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

void	sort_list(t_Node *a, t_Node *b)
{
	int	size;
	int	i;
	int	j;
	int	num;

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
		while (b)
			pa(&a, &b);
	}
}

int		index_of(int val, t_Node *stack)
{
	t_Node	*iterator;
	int		count;

	count = 0;
	iterator = stack;
	while (iterator)
	{
		if (iterator->val == val)
			return (count);
		count++;
		iterator = iterator->next;
	}
	return (-1);
}

int		get_max(t_Node *stack)
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

int		get_min(t_Node *stack)
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

void	val_swap(int *a, int *b)
{
	int	i;
	i = *a;
	*a = *b;
	*b = i;
}

void	sa(t_Node **a)
{
	t_Node	*temp;
	
	temp = *a;
	if (temp && temp->next)
	{
		val_swap(&temp->val, &temp->next->val);
		val_swap(&temp->index, &temp->next->index);
		ft_putstr_fd("sa\n", 1);
	}
}

void	rra(t_Node **a)
{
	t_Node	*temp;
	t_Node	*prev;
	t_Node	*stack;

	stack = *a;
	if (!(stack && stack->next))
		return ;
	temp = stack;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = stack;
	prev->next = NULL;
	*a = temp;
	ft_putstr_fd("rra\n", 1);
	return ;
}

void	sort_three(t_Node *a)
{
	int	max;
	int	min;
	
	max = get_max(a);
	min = get_min(a);
	if (index_of(min, a) == 1 && index_of(max, a) == 2)
		sa(&a);
	else if (index_of(min, a) == 2 && index_of(max, a) == 1)
		rra(&a);
	else if (index_of(min, a) == 1 && index_of(max, a) == 0)
		ra(&a);
	else if (index_of(min, a) == 2 && index_of(max, a) == 0)
	{
		ra(&a);
		sa(&a);
	}
	else if (index_of(min, a) == 0 && index_of(max, a) == 1)
	{
		sa(&a);
		ra(&a);
	}
}

void	sort_five(t_Node *a, t_Node *b)
{
	int	max;
	int	min;

	max = get_max(a);
	min = get_min(a);
	while (list_len(&a) > 3)
	{
		if (index_of(get_min(a), a) == 0)
			pb(&a, &b);
		else if (index_of(get_min(a), a) == 3 || index_of(get_min(a), a) == 4)
			rra(&a);
		else if (index_of(get_min(a), a) == 1 || index_of(get_min(a), a) == 2)
			ra(&a);
	}
	sort_three(a);
	pa(&a, &b);
	pa(&a, &b);
}