/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:32 by ybong             #+#    #+#             */
/*   Updated: 2021/02/15 16:35:10 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_save(int fd, char *str, char **read_sofar, char **leftover)
{
	int		i;
	char	*temp;
	i = 0;
	
	if ((temp = ft_strchr(str, '\n')) != 0)
	{
		if (!(leftover[fd] = ft_strdup(temp + 1)))
			return (-1);
		*temp = '\0';
		if (!(*read_sofar = ft_strjoin(*read_sofar, str)))
			return (-1);
	}
	else
		leftover[fd] = ft_strdup(str);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX + 1];
	char		*read_sofar[1];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			readbyte;

	*read_sofar = ft_strdup("");
	if (leftover[fd])
	{
		if (ft_strchr(leftover[fd], '\n')) // '\n'이 있으면 
		{
			if (!(temp = ft_strdup(leftover[fd])))
				return (-1);
			if (ft_save(fd, temp, read_sofar, leftover) == -1) //save로 split
				return (-1);
			*line = *read_sofar;
			return (1);
		}
		else // 남은 문자열에 '\n'이 없으면
		{
			if (!(*read_sofar = ft_strdup(leftover[fd])))
				return (-1);
			free(leftover[fd]);
		} 
	}
	//여기까지 이전 read의 leftover에 있는 값을 처리하는 과정
	while ((readbyte = read(fd, buf, BUFFER_SIZE)) > 0) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
	{
		buf[readbyte] = 0;
		if (ft_strchr(buf, '\n')) // '\n' 있는 경우 
		{
			if (ft_save(fd, buf, read_sofar, leftover) == -1)
				return (-1);
			*line = *read_sofar;
			return (1);
		}
		else // '\n' 없는 경우
		{
			if (!(*read_sofar = ft_strjoin(*read_sofar, buf)))
				return (-1);
		}
	} // EOF 있는 마지막 line을 읽은 상태
	*line = *read_sofar;
	if (!(leftover[fd] = ft_strdup(buf)))
		return (-1);
	return (0);
}