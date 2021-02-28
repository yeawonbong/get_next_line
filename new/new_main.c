/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:29:36 by ybong             #+#    #+#             */
/*   Updated: 2021/02/22 23:04:50 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_gnl.h"

int	main(void)
{
	char	*line = NULL;
	int		fd = 0;
	int		gnlreturn;

	fd = open("test copy.txt", O_RDONLY);
	while ((gnlreturn = get_next_line(fd, &line)) > 0)
	{
		printf("\n\n>>line = %s<<\n\n\n", line);
	}
	if (gnlreturn == 0)
		printf("\n\n>>line = %s<<\n\n", line);
	free(line);

/*
	while (gnlreturn > 0)
	{
		gnlreturn = read(fd, line, BUFFER_SIZE);
		line[gnlreturn] = 0;		
		printf("line = %s\n", line);
		gnlreturn = read(fd, line, BUFFER_SIZE);
		line[gnlreturn] = 0;
		printf("line = %s\n", line);
	}
*/
	return (0);
}

