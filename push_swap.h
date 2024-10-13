/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:37:10 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/13 23:44:56 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nb;
	int				rank;
	struct s_list	*next;
}	t_list;


void	show_error(void);
int		ft_atol(char *str);
t_list	*lst_new(char *n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

int		valid_args(char **av);
t_list	**initialize(char **av);
char	**ft_split(char *s, char c);
void	set_rank(t_list **lst_a);
t_list	*get_max(t_list **lst);


void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);

int		is_sorted(t_list **lst);
void	sort_three(t_list **lst);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	sort_x(t_list **lst_a, t_list **lst_b);

#endif