
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/22 13:40:13 by ciclo-d          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*temp;
	int		rd;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	rd = 1;
	while (!ft_strchr(temp, '\n') && rd != 0)
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[rd] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);

	//str = ft_read (fd);
	//while (str != 0)
	line = ft_read(fd, str);
	return (line);
}

int	main(void)
{
	int		fd;

	fd =  open("txt/fd.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf ("%s", s);
	close(fd);
}
