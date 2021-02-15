
#include "get_next_line.h"
int main(void)
{
	char* line=NULL;
	int fd=0;
	int gnl;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{printf("why\n");
		printf("line = %s\n", line);
		i++;
	}
	free(line);
	return (0);
}/*
int main(void)
{
printf("OK\n");
	char **line=NULL;
//	int ret;
	int fd=0;
printf("%d\n", fd);
	fd = open("test.txt", O_RDONLY);
printf("%d\n", fd);
	while ((ret = get_next_line(fd, line)) > 0)
	{
		printf("%s\n", *line);
		free(*line);
	}
	get_next_line(fd, line);
printf("%s\n", *line);
	free(*line);
	return (0);

}
*/
