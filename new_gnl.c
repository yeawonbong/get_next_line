/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:19:19 by ybong             #+#    #+#             */
/*   Updated: 2021/02/18 05:44:59 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_enter_idx(char *str)
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

int		ft_split_str(int enter_idx, char *buf, char *leftover_fd, char **line)
{
	printf("split_in\n");
	leftover_fd = ft_strdup(&buf[enter_idx + 1]);
	buf[enter_idx] = '\0';
	*line = ft_strjoin(*line, buf);
	free(buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			readsize;
	int			enter_idx;

	readsize = 0;
	enter_idx = 0;
	if (!(leftover[fd]))
	{
		if ((readsize = (int)read(fd, buf, BUFFER_SIZE)) <= 0)
			return (-1);
		buf[readsize] = '\0';
		leftover[fd] = ft_strdup(buf);
	}
	while (readsize > 0)
	{
		if ((enter_idx = ft_enter_idx(leftover[fd])) != -1)
			return (ft_split_str(enter_idx, buf, leftover[fd], line));
		else
		{
			*line = ft_strjoin(*line, buf);
			if (readsize < BUFFER_SIZE)
				return (0);
		}
	}
	return (0);
}
