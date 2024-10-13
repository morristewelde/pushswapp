/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:09:24 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:37:28 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to check if the argument values are valid, particularly signs
int	valid_value(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j - 1] && av[i][j - 1] != ' ')
					return (1);
				if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
					return (1);
			}
		}
	}
	return (0);
}

// Main validation function to check for valid arguments
int	valid_args(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		if (!av[i][0])
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') 
				|| av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' '))
				return (1);
			j++;
		}
	}
	if (valid_value(av))
		return (1);
	return (0);
}
