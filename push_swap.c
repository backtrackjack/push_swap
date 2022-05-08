/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:12:08 by jsellars          #+#    #+#             */
/*   Updated: 2022/05/08 15:21:19 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

int checkoverflow(char *str)
{
	long result;
	int sign;
	char *s;

	s = str;
	sign = 1;
	result = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		result = 10 * result + *s - '0';
		s++;
	}
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
		return (1);
	return (0);
}

int checkargs(int ac, char **av)
{
	int i;

	while (--ac)
	{
		i = 0;
		if ((!ft_isdigit(av[ac][i]) && av[ac][i] != '-') && (ft_strlen(av[ac]) <= 1))
			return (1);
		while (av[ac][++i])
		{
			if (!ft_isdigit(av[ac][i]))
				return (1);
		}
		if (checkoverflow(av[ac]))
			return (1);
	}
	return (0);
}

int checkdups(int ac, char **av)
{
	int i;
	int j;
	size_t size;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
		{
			if (ft_strlen(av[j]) > ft_strlen(av[i]))
				size = ft_strlen(av[j]);
			else
				size = ft_strlen(av[i]);
			if (!ft_memcmp(av[j], av[i], size))
				return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	Node *stack_a;
	Node *stack_b;

	if (ac < 2 || checkargs(ac, av) || checkdups(ac, av))
	{
		if (ac < 2)
			ft_putstr_fd("Please enter a list of numbers\n", 1);
		else
			ft_putstr_fd("Error\n", 1);
		return (1);
	}

	stack_a = stack_init(av, ac);
	stack_b = NULL;
	index_list(stack_a);
	// print_list(stack_a);
	sort_list(stack_a, stack_b);
	print_list(stack_a);
	return (0);
}
