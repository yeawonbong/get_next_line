/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:28:57 by ybong             #+#    #+#             */
/*   Updated: 2021/02/21 17:59:37 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_gnl.h"

int		ft_read(int readsize, int fd, char *buf, char **backup)
{printf("ㅡ[READ]ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("| my backup input is : %s\n", backup[fd]);
	if ((readsize = read(fd, buf, BUFFER_SIZE)) <= 0)
		return (-1);
	buf[readsize] = '\0';
	printf("| my backup input is : %s\n", backup[fd]);
	printf("| buf is : %s\n", buf);
	backup[fd] = ft_strjoin(backup[fd], buf);
	printf("| THIS_IS_READ_readsize is : %d\n| THIS_IS_READ_backup is: %s\n", readsize, backup[fd]);
printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ[READ]ㅡ\n\n");
	
	return (readsize);
}

int		ft_find_enter(char *str)
{printf("ㅡ[find_enter]ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			printf("| enter idx is : %d\n", i);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ[find_enter]ㅡ\n\n");
			return (i);
		}
		i++;
	}
	printf("| return : no_enter\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ[find_enter]ㅡ\n\n");
	return (-1);
}

int		ft_split_str(int fd, char **backup, char **line, int enter_idx)
{printf("ㅡ[split_str]ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	char	*temp;

	temp = ft_strdup(backup[fd]);
	printf("| -temp is : %s\n", temp);
	free(backup[fd]);
	backup[fd] = ft_strdup(&temp[enter_idx + 1]);
	temp[enter_idx] = '\0';
	*line = temp;
	printf("| -line is: %s\n| -backup is : %s\n", *line, backup[fd]);
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ[split_str]ㅡ\n\n");
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			readsize;
	int			enter_idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || fd > OPEN_MAX)
		return (-1);
	enter_idx = 0;
	readsize = 0;
	while ((readsize = ft_read(readsize, fd, buf, backup)) > 0)
	{printf("--------------------------------------------------start_of_while\n");
		if (readsize  == -1)
			return (-1);		
		if ((enter_idx = ft_find_enter(backup[fd])) >= 0)
			return ((ft_split_str(fd, backup, line, enter_idx)));
		printf("#####backup is: %s\n", backup[fd]);
			printf("#####BUFFER_SIZE: %d, readsize : %d\n", BUFFER_SIZE, readsize);
			*line = backup[fd];
		if (readsize < BUFFER_SIZE)
		{
			printf ("#####FIN_line: %s\n", *line);
			printf("#####return_0\n");
			return (0);
		}
		printf("--------------------------------------------------end_of_while\n");
	}
	printf("#####return_fin0\n");
	return(0);
}
