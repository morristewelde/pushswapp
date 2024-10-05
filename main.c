/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:54:32 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/05 17:56:38 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"
#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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

t_stack_node	*ft_last_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_append_stack(t_stack_node **a, t_stack_node *b)
{
	if (!a)
		return ;
	if (!*a)
		*a = b;
	else
		(ft_last_node(*a))->next = b;
}

t_stack_node	*ft_create_singlenode(int nb)
{
	t_stack_node	*res;
	res = malloc(sizeof (t_stack_node));
	if (!res)
		ft_error();
	res->value = nb;
	res->next = NULL;
	return (res);
}

t_stack_node	*ft_create_stack(int ac, char **av)
{
	int				i;
	int				nb;
	t_stack_node	*new;
	t_stack_node	*temp;

	i = 1;
	new = NULL;
	while (i < ac)
	{
		nb = ft_atol(av[i]);
		temp = ft_create_singlenode(nb);
		ft_append_stack(&new, temp);
		i++;
	}
	return (new);
}

void	ft_print_stack(t_stack_node *a)
{
	if(!a)
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
	ft_print_stack(a);
}
