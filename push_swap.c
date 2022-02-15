/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsellars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:12:08 by jsellars          #+#    #+#             */
/*   Updated: 2022/02/16 09:25:47 by jsellars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/push_swap.h"
#include <limits.h>

int	checkoverflow(char *str)
{
	long	result;
	int		sign;
	char	*s;

	s = str;
	sign = 1;
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

int	checkargs(int ac, char **av)
{
	int	i;

	while (--ac)
	{
		i = 0;
		while (av[ac][i])
		{
			if (!ft_isdigit(av[ac][i]) && av[ac][i] != '-')
			{
				ft_putstr_fd("Error\n", 1);
				return (1);
			}
			i++;
		}
		if (checkoverflow(av[ac]))
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
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
