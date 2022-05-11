/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 12:07:43 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct	Node
{
	int 	val;
	int		index;
	struct 	Node *next;
}	Node;

Node *stack_init(char **list, int len);
void index_list(Node *head);
int list_len(Node **head);
int is_sorted(Node *head, int size);
void ra(Node **head);
void pb(Node **a, Node **b);
void pa(Node **a, Node **b);
void sort_list(Node *a, Node *b);
void	append(Node **head, int data);
#endif
