/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:42:42 by avelandr          #+#    #+#             */
/*   Updated: 2025/02/21 15:46:47 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);
char	*memory_cache(int fd);
char	*update_cache(char *cache, char *buffer);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);

#endif
