/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:00:57 by jyurrita          #+#    #+#             */
/*   Updated: 2022/12/16 10:18:40 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h> 

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *s1);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
void	fill_stash(char **stash, int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*get_line_from_stash(char **stash);
void	clear_stash(char **stash, size_t i);
void	fill_stash_from_buf(char **stash, char *buf);

#endif