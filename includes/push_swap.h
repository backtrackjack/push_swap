/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/07 16:30:18 by jsellars         ###   ########.fr       */
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
void	index_list(Node *head);
void	print_list(Node *head);
int		list_len(Node **head);
void	print_list_index(Node *head);
int		is_sorted(Node *head);
#endif
