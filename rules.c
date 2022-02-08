/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:48:48 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/08 16:48:20 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sx(t_list **stack)
{
	int	temp;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, tmp);
}
