/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:29:36 by ybong             #+#    #+#             */
/*   Updated: 2021/02/20 17:12:13 by ybong            ###   ########.fr       */
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
	return (0);
}

