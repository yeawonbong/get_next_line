/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:48:36 by ybong             #+#    #+#             */
/*   Updated: 2021/02/18 02:24:13 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
int		ft_save(int fd, char *str, char **read_sofar, char **leftover);

#endif
