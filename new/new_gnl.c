/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:28:57 by ybong             #+#    #+#             */
/*   Updated: 2021/02/20 16:09:30 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_gnl.h"

int		ft_find_enter(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			printf("enter idx is : %d", i);
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_fill_backup(size_t readsize, int fd, char *buf, char **backup)
{
	if ((readsize = read(fd, buf, BUFFER_SIZE)) <= 0)
		return (-1);
	buf[readsize] = '\0';
	backup[fd] = ft_strdup(buf);
	return (0);
}

int		ft_split_str(int fd, char **backup, char **line, int enter_idx)
{
	char	*temp;

	if (enter_idx == 0)
	{
		*line = ft_strdup("");
		return (1);
	}
	temp = ft_strdup(backup[fd]);
	free(backup[fd]);
	backup[fd] = ft_strdup(&temp[enter_idx + 1]);
	temp[enter_idx] = '\0';
	*line = ft_strjoin(*line, temp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	size_t		readsize;
	int			enter_idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || fd > OPEN_MAX)
		return (-1);
	readsize = 0;
	enter_idx = 0;
	if (!(backup[fd]))
		ft_fill_backup(readsize, fd, buf, backup);
	while (readsize > 0)
	{
		if ((enter_idx = ft_find_enter(backup[fd])) != -1)
			return (ft_split_str(fd, backup, line, enter_idx));
		else
		{
			*line = ft_strjoin(*line, backup[fd]);
			if (readsize < BUFFER_SIZE)
				return (0);
		}
	}
	return (0);
}
