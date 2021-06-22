/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:29:36 by ybong             #+#    #+#             */
/*   Updated: 2021/03/02 14:27:29 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line = NULL;
	int		fd = 0;
	int		gnl;

	fd = open("test copy.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("line = %s\n", line);
	}
	printf("line = %s", line);
	free(line);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}

