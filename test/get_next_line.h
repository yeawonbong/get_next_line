/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:48:36 by ybong             #+#    #+#             */
/*   Updated: 2021/02/13 17:40:05 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_save(char *str, char **read_sofar, char **leftover, int fd);
int		get_next_line(int fd, char **line);

#endif
