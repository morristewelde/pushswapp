/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:23:48 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:36:58 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_list **lst)
{
	t_list	*tmp;

	if (!lst || ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	ra(t_list **lst)
{
	do_rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **lst)
{
	do_rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	do_rotate(lst_a);
	do_rotate(lst_b);
	write(1, "rr\n", 3);
}
