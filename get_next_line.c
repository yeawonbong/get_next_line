/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:32 by ybong             #+#    #+#             */
/*   Updated: 2021/02/13 18:55:54 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_enter(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{printf("---------enter_return(1)------\n");
			return (1);
		}
		str++;
	}printf("---------enter_return(0)------\n");
	return (0);
}

int		ft_save(char *str, char **read_sofar, char **leftover, int fd) //첫번째 '\n' 기준으로 split 하여 저장하는 함수
{	printf("inside_save");
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (!(leftover[fd] = ft_strdup(&str[i + 1])))
				return (-1);
			str[i] = '\0';
			if (!(*read_sofar = ft_strjoin(*read_sofar, str)))
				return (-1);
			return (0);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX + 1];
	char		*read_sofar[1];
	char		*temp;
	char		buf[BUFFER_SIZE];
	static int	fin;

	*read_sofar = NULL;
	fin = 0;
	while (1)
	{printf(">>>>>start\n");
		if (leftover[fd])
		{
			if (find_enter(leftover[fd])) // '\n'이 있으면 
			{printf("findenter=1");
				if (!(temp = ft_strdup(leftover[fd])))
					return (-1);
				if (ft_save(temp, read_sofar, leftover, fd) == -1) //save로 split
					return (-1);
				line = read_sofar;
				return (1);
			}
			else // 남은 문자열에 '\n'이 없으면
			{
				if (fin) // EOF 있는 라인이라면
				{
					*line = leftover[fd];
					return (0);
				}
				if (!(*read_sofar = ft_strdup(leftover[fd])))
					return (-1);
				free(leftover[fd]);
			} //여기까지 이전 read의 leftover에 있는 값을 처리하는 과정
		}
		while (!fin && (read(fd, buf, BUFFER_SIZE) == BUFFER_SIZE)) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
		{
			printf(">>>>>inside\n");/////////
			if (find_enter(buf))
			{
				printf("<<<<<YES_enter\n");/////////
				printf("[buf is : %s]\n", buf);
				if (ft_save(buf, read_sofar, leftover, fd) == -1)
					return (-1);
				printf("out_save");

				line = read_sofar;
				return (1);
			}
			else
			{printf("<<<<<NO_enter\n");/////////
				if (!(*read_sofar = ft_strjoin(*read_sofar, buf)))
					return (-1);
			printf("[[[read_sofar: %s]]]\n", *read_sofar);
			}
		} // EOF 있는 마지막 line을 읽은 상태
		printf("fin\n");/////////
		fin = 1;
		if (!(leftover[fd] = ft_strdup(buf)))
			return (-1);
	}
	return (0);
}