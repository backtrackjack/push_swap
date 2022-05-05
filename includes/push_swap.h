/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/05 15:31:10 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef	struct Node
{
	int				val;
	int				index;
	struct Node		*next;
}	Node;

Node	*stack_init(char **list, int len);
void	print_list(Node *head);
#endif
