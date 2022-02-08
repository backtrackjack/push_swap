/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:12:08 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/08 16:30:17 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"

int	main(void)
{
	int a = 1;
	int b = 2;

	t_list *list = ft_lstnew(&a);
	ft_lstadd_back(&list, ft_lstnew(&b));
	sx(*list);
	return (0);
}
