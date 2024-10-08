/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:54:32 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 23:17:48 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
			ft_error();
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		ft_error();
	return (res * sign);
}

void	ft_print_stack(t_stack_node *a)
{
	if (!a)
		exit(1);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;

	a = ft_create_stack(argc, argv);
	if (!a || !ft_check_repetition(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!ft_check_order(a))
	{
		if (ft_stack_len(a) == 2)
		{
			sa(&a, 0);
			ft_print_stack(a);
		}
		else if(ft_stack_len(a) == 3)
			printf("%d\n", ft_stack_len(a));
		else 
			printf("%d\n", ft_stack_len(a));

	}
}
