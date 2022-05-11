/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 13:43:25 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct Node
{
	int			val;
	int			index;
	struct Node	*next;
}	t_Node;

t_Node	*stack_init(char **list, int len);
void	index_list(t_Node *head);
int		list_len(t_Node **head);
int		is_sorted(t_Node *head, int size);
void	ra(t_Node **head);
void	pb(t_Node **a, t_Node **b);
void	pa(t_Node **a, t_Node **b);
void	sort_list(t_Node *a, t_Node *b);
void	append(t_Node **head, int data);
void	sort_three(t_Node *a);
void	sort_five(t_Node *a, t_Node *b);
#endif
