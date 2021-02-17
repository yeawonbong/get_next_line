/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:19:19 by ybong             #+#    #+#             */
/*   Updated: 2021/02/17 23:24:29 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_save(int fd, char *str, char **read_sofar, char **leftover)
{
	char	*temp;

	if ((temp = ft_strchr(str, '\n')))
	{
		if (!(leftover[fd] = ft_strdup(temp + 1)))
			return (-1);
		*temp = '\0';
		if (!(*read_sofar = ft_strjoin(*read_sofar, str)))
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX + 1];
	char		*read_sofar[1];
	char		*buf;
	int			readbyte;

	readbyte = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || fd >= OPEN_MAX)
		return (-1);
	if (leftover[fd])
	{
		buf = ft_strdup(leftover[fd]);
		free(leftover[fd]);
	}
	else
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		readbyte = read(fd, buf, BUFFER_SIZE);
		buf[readbyte] = 0;
	}
	while (readbyte > 0) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
	{
printf("OK0\n");
		if (ft_strchr(buf, '\n')) // '\n' 있는 경우 
		{
			if (ft_save(fd, buf, read_sofar, leftover) == -1)
				return (-1);
			*line = *read_sofar;
			if (*read_sofar)
				free (read_sofar);
			if (*buf)
				free(buf);
printf("OK1\n");
			return (1);
		}
		else // '\n' 없는 경우
		{
			if (!(*read_sofar = ft_strjoin(*read_sofar, buf)))
				return (-1);
			if (*buf)
				free(buf);
		}
	} 
	if (*line)
		return (1);
	if (readbyte < 0)// || !(leftover[fd] = ft_strdup(buf)))
		return (-1);
	return (0);
}