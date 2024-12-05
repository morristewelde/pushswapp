/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:30:58 by mtewelde          #+#    #+#             */
/*   Updated: 2024/10/16 19:12:47 by mtewelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_extract(int fd, char *line, char *buff)
{
	int			ft_fd;

	ft_fd = 1;
	while (ft_fd && ft_check_line(line) == 0)
	{
		ft_fd = read(fd, buff, BUFFER_SIZE);
		if (ft_fd < 0)
			return (ft_bzero(buff), free(line), NULL);
		buff[ft_fd] = 0;
		line = ft_strjoin(line, buff);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1] = "\0";
	char		*read_line;

	read_line = ft_strdup(read_buffer);
	if (read_line == NULL)
		return (NULL);
	read_line = ft_extract(fd, read_line, read_buffer);
	if (read_line == NULL)
		return (free(read_line), NULL);
	ft_set_next_line(read_buffer);
	if (read_line[0] == 0)
		return (free(read_line), NULL);
	return (read_line);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd;
    char *line;
    fd = open("morris.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error");
        return 1;
    }
	
	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);

	printf("%s\n", line);
	
	
    free(line);
    close(fd);
    return 0;
}*/
