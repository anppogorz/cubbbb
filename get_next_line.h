/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpogorz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:18:29 by anpogorz          #+#    #+#             */
/*   Updated: 2019/11/27 11:57:23 by anpogorz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strdup_since(char *s1, int at);
char	*ft_strdup_until(char *s1, int until);
char	*ft_strchr(const char *s, int c);
int		ft_find_sentence(char **treatstr, char **line);
int		treatment(char **treatstr, char **line, int ret, int fd);
int		get_next_line(int fd, char **line);

#endif
