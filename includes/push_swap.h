/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/14 15:58:26 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef	struct	s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

void	sx(t_stack stack);

#endif
