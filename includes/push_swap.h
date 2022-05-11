/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <jsellars@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:16:19 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/11 14:01:09 by jsellars         ###   ########.fr       */
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
int		get_max(t_Node *stack);
int		get_min(t_Node *stack);
void	sa(t_Node **a);
#endif
