/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:28:57 by ybong             #+#    #+#             */
/*   Updated: 2021/02/28 14:40:24 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_gnl.h"

int		ft_read(int readsize, int fd, char *buf, char **backup)
{
	char *tempr;

	if ((readsize = read(fd, buf, BUFFER_SIZE)) <= 0)
		return (-1);
	buf[readsize] = '\0';
	tempr = ft_strjoin(backup[fd], buf);
	backup[fd] = ft_strdup(tempr);
	free (buf);
	return (readsize);
}

int		ft_find_enter(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_split_str(int fd, char **backup, char **line, int enter_idx)
{
	char	*temp;

	temp = ft_strdup(backup[fd]);
	free(backup[fd]);
	backup[fd] = ft_strdup(&temp[enter_idx + 1]);
	temp[enter_idx] = '\0';
	*line = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[FOPEN_MAX];
	char		*buf;
	int			readsize;
	int			enter_idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || fd > FOPEN_MAX)
		return (-1);
	enter_idx = 0;
	readsize = 0;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((readsize = ft_read(readsize, fd, buf, backup)) > 0)
	{
		if (readsize  == -1)
			return (-1);		
		if ((enter_idx = ft_find_enter(backup[fd])) >= 0)
			return ((ft_split_str(fd, backup, line, enter_idx)));
		*line = backup[fd];
		if (readsize < BUFFER_SIZE)
			return (0);
	}
	*line = backup[fd];
	return(0);
}
