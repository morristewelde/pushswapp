/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:53:49 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 22:32:30 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "../gnl/get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	operate(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		ft_error();
}

void	get_operations(t_stack **lst_a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !(*line))
			break ;
		operate(line, lst_a, b);
		free (line);
	}
}

/*void	push_swap(t_stack **a)
{
	t_stack	**b;

	b = malloc(sizeof(t_stack *));
	if (!b)
		return ;
	*b = NULL;
	if (ft_stack_len(*a) == 2)
		sa(a);
	else if (ft_stack_len(*a) == 3)
		sort_three(a);
	else
		sort_big(a, b);
	free_stack(b);
	free(b);
}*/

int	main(int ac, char *av[])
{
	t_stack	**a;
	t_stack	**b;

	if (ac > 1)
	{
		if (valid_av(av))
			ft_error();
		b = malloc(sizeof(t_stack *));
		if (!b)
			ft_error();
		*b = NULL;
		a = initialize(av);
		if (!a)
			ft_error();
		get_operations(a, b);
		if (check_sorted(a) && *b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack(a);
		free_stack(b);
		free(a);
		free(b);
	}
}
