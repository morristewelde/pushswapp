/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:30:33 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:36:53 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_b || !(*lst_b) || !lst_a)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_a || !(*lst_a) || !lst_b)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(lst_b, tmp);
	write(1, "pb\n", 3);
}
