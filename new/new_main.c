/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:29:36 by ybong             #+#    #+#             */
/*   Updated: 2021/03/01 15:50:40 by ybong            ###   ########.fr       */
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
		printf(">>line = %s<<\n", line);
	}
	if (gnlreturn == 0)
		printf(">>line = %s<<\n", line);
	free(line);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
