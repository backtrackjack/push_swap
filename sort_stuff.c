/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:00:56 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:00:58 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

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
		while (b)
			pa(&a, &b);
	}
}
