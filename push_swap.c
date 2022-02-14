/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:12:08 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/15 09:23:19 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"

int	checkargs(int ac, char **av)
{
	while(ft_atoi(av[--ac]))
	{
		if (!ac - 1)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if(ac < 2 || checkargs(ac, av))
	{
		ft_putstr_fd("Error\n", 1);
	}
	return (1);
	return (0);
}
