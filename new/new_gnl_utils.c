/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:26:16 by ybong             #+#    #+#             */
/*   Updated: 2021/02/20 15:28:18 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_gnl.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(ft_strlen(str) + 1)))
		return (0);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	printf("JOIN\n");
	if (!(dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	if (!s1)
		return (s2);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
