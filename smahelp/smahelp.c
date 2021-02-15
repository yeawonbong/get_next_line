#include "smahelp.h"
int		ft_save(int fd, char *str, char **read_sofar, char **leftover)
{
	//printf("inside_save!\n");
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
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX + 1];
	char		*read_sofar[1];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
//	static int	fin;
	int			readbyte;

	*read_sofar = ft_strdup("");
//	fin = 0;
//	while (1)
//	{//printf(">>>>>start\n");
		if (leftover[fd])
		{
			if (ft_strchr(leftover[fd], '\n')) // '\n'이 있으면 
			{//printf("findenter=1");
				if (!(temp = ft_strdup(leftover[fd])))
					return (-1);
				if (ft_save(fd, temp, read_sofar, leftover) == -1) //save로 split
					return (-1);
				*line = *read_sofar;
				return (1);
			}
			else // 남은 문자열에 '\n'이 없으면
			{
/*				if (fin) // EOF 있는 라인이라면
				{
					*line = ft_strdup("");
					return (0);
				}
*/				if (!(*read_sofar = ft_strdup(leftover[fd])))
					return (-1);
				free(leftover[fd]);
			} //여기까지 이전 read의 leftover에 있는 값을 처리하는 과정
		}
		while ((readbyte = read(fd, buf, BUFFER_SIZE)) > 0) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
		{
			buf[readbyte] = 0;
			//printf(">>>>>inside\n");/////////
			if (ft_strchr(buf, '\n')) // '\n' 있는 경우 
			{
				//printf("<<<<<YES_enter\n");/////////
				//printf("[buf is : %s]\n", buf);
				if (ft_save(fd, buf, read_sofar, leftover) == -1)
					return (-1);
				//printf("out_save");
				*line = *read_sofar;
				return (1);
			}
			else // '\n' 없는 경우
			{//printf("<<<<<NO_enter\n");/////////
				if (!(*read_sofar = ft_strjoin(*read_sofar, buf)))
					return (-1);
			//printf("[[[read_sofar: %s]]]\n", *read_sofar);
			}
		} // EOF 있는 마지막 line을 읽은 상태
		printf("fin\n");/////////
//		fin = 1;
		printf("buf : %s\n", buf);
		if (!(leftover[fd] = ft_strdup(buf)))
			return (-1);
//	}
	return (0);
}

int main(void)
{
	char* line;
	int fd;
	int gnl;
	int i;
	i = 0;
	fd = open("./plztest.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("line = %s\n", line);
		free(line);
		i++;
	}
	free(line);
	return (0);
}

/*int	find_enter(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{//printf("---------enter_return(1)------\n");
			return (1);
		}
		str++;
	}//printf("---------enter_return(0)------\n");
	return (0);
}
int		ft_save(int fd, char *str, char **read_sofar, char **leftover) //첫번째 '\n' 기준으로 split 하여 저장하는 함수
{
	int		i;
	//printf("inside_save\n");
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
	char		buf[BUFFER_SIZE + 1];
	static int	fin;
    size_t      byte;
	*read_sofar = ft_strdup("");
	fin = 0;
	while (1)
	{//printf(">>>>>start\n");
		if (leftover[fd])
		{
			if (find_enter(leftover[fd])) // '\n'이 있으면 
			{//printf("findenter=1");
				if (!(temp = ft_strdup(leftover[fd])))
					return (-1);
				if (ft_save(fd, temp, read_sofar, leftover) == -1) //save로 split
					return (-1);
				*line = *read_sofar;
				return (1);
			}
			else // 남은 문자열에 '\n'이 없으면
			{
				if (fin) // EOF 있는 라인이라면
				{
					*line = ft_strdup("");
					return (0);
				}
				if (!(*read_sofar = ft_strdup(leftover[fd])))
					return (-1);
				free(leftover[fd]);
			} //여기까지 이전 read의 leftover에 있는 값을 처리하는 과정
		}
		while ((byte = read(fd, buf, BUFFER_SIZE)) > 0) // EOF를 만나기 전의 경우 (EOF 읽으면 while문 종료)
		{
            buf[byte] = 0;
            //printf("byte = %zu\n", byte);/////////
			if (find_enter(buf))
			{
				//printf("<<<<<YES_enter\n");/////////
				//printf("[buf is : %s]\n", buf);
				if (ft_save(fd, buf, read_sofar, leftover) == -1)
					return (-1);
				*line = *read_sofar;
				return (1);
			}
			else
			{//printf("<<<<<NO_enter\n");/////////
				if (!(*read_sofar = ft_strjoin(*read_sofar, buf)))
					return (-1);
			//printf("[[[read_sofar: %s]]]\n", *read_sofar);
			}
		} // EOF 있는 마지막 line을 읽은 상태
		//printf("fin\n");/////////
		fin = 1;
		if (!(leftover[fd] = ft_strdup(buf)))
			return (-1);
	}
	return (0);
}
int main(void)
{
	char* line;
	int fd;
	int gnl;
	int i;
	i = 0;
	fd = open("./plztest.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("line = %s\n", line);
		free(line);
		i++;
	}
	printf("line = %s\n", line);
	free(line);
	return (0);
}



//------------save 다시 짜기

int		ft_save(int fd, char *str, char **read_sofar, char **leftover)
{
	printf("inside_save!");
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
	return (0);
}

//////////////ex-save backup////////////

int		ft_save(int fd, char *str, char **read_sofar, char **leftover) //첫번째 '\n' 기준으로 split 하여 저장하는 함수
{
	printf("inside_save");
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
}*/