/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:31:09 by mtewelde          #+#    #+#             */
/*   Updated: 2023/12/02 13:33:27 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
int		ft_check_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_set_next_line(char *str);

#endif