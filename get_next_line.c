/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:32 by ybong             #+#    #+#             */
/*   Updated: 2021/02/08 18:58:51 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_save(char *str, char *read_sofar, char leftover[])
{
	int	i;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			leftover = ft_stdup(str[i + 1]);
			str[i] = '\0';
			read_sofar = ft_strjoin(read_sofar, str);
			return ;
		}
	}	
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX];
	char		*read_sofar;
	char		*temp;
	char		buf[BUFFER_SIZE];

	if (strchr(leftover[fd]), '\n') != 0)
	{
		temp = strdup(leftover[fd]);
		ft_save(temp, read_sofar, leftover[fd]);
		*line = read_sofar;
		return (1);
	}
	else
	{
		read_sofar = strdup(leftover[fd]);
		free(leftover[fd]);
	}


}