/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:32 by ybong             #+#    #+#             */
/*   Updated: 2021/02/08 20:36:43 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_save(char *str, char *read_sofar, char leftover[]) //첫번쩌 '\n' 기준으로 split 하는 함수
{
	int	i;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!(leftover = ft_stdup(str[i + 1])))
				return (-1);
			str[i] = '\0';
			if (!(read_sofar = ft_strjoin(read_sofar, str)))
				return (-1);
			return (0);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX];
	char		*read_sofar;
	char		*temp;
	char		buf[BUFFER_SIZE];
	static int	fin;

	fin = 0;
	while (1)
	{
		if (strchr(leftover[fd], '\n')) // '\n'이 있으면 
		{
			temp = strdup(leftover[fd]);
			if (ft_save(temp, read_sofar, leftover[fd]) == -1) //save로 split
				return (-1);
			*line = read_sofar;
			return (1);
		}
		else // 남은 문자열에 '\n'이 없으면
		{
			if (fin) // EOF 있는 라인이라면
			{
				*line = leftover[fd];
				return (0);
			}
			if (!(read_sofar = strdup(leftover[fd])))
				return (-1);
			free(leftover[fd]);
		} //여기까지 이전 read의 leftover에 있는 값을 처리하는 과정
		while (!fin && (read(fd, buf, BUFFER_SIZE) = BUFFER_SIZE )) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
		{
			if (strchr(leftover[fd], '\n') == 0)
			{
				if (!(read_sofar = strjoin(read_sofar, buf)))
					return (-1);
			}
			else
			{
				if (ft_save(buf, read_sofar, leftover[fd]) == -1)
					return (-1);
				*line = read_sofar;
				return (1);
			}
		} // EOF 있는 마지막 line을 읽은 상태
		fin = 1;
		leftover[fd] = strdup(buf);
	}
	return (0);
}