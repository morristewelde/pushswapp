/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:51:14 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/08 23:16:06 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**ft_split(char *av, char sep);

//create the stack
t_stack_node	*ft_last_node(t_stack_node *a);
t_stack_node	*ft_create_singlenode(int nb);
t_stack_node	*ft_create_stack(int ac, char **av);
t_stack_node	*ft_create_stack_av2(char *av2);
void			ft_append_stack(t_stack_node **a, t_stack_node *b);

//checking the stack order and repetition
int				ft_check_repetition(t_stack_node *a);
int				ft_check_order(t_stack_node *a);

//utils for stack related sub-operation
int				ft_stack_len(t_stack_node *a);

//swap functions
void	sa(t_stack_node **a, int i);

//freeing and error functions
void			ft_error(void);
void			ft_free_stack(t_stack_node **a);

int				ft_atol(char *str);

#endif
