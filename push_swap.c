/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:12:08 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/15 16:20:21 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"

int	checkargs(int ac, char **av)
{
	int	i;

	while (--ac)
	{
		i = 0;
		if ((ft_strlen(av[ac]) > 10 && av[ac][i] != '-')
				|| (ft_strlen(av[ac]) > 11))
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		while (av[ac][i])
		{
			if (!ft_isdigit(av[ac][i]))
			{
				ft_putstr_fd("Error\n", 1);
				return (1);
			}
			i++;
		}
		if (!ac - 1)
			return (0);
	}
	ft_putstr_fd("Error\n", 1);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2 || checkargs(ac, av))
		return (1);
	return (0);
}
