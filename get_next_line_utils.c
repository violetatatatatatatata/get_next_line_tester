/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:18 by avelandr          #+#    #+#             */
/*   Updated: 2025/02/21 15:09:56 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	size_t			i;
	unsigned char	*dst_aux;
	unsigned char	*src_aux;

	src_len = 0;
	i = 0;
	dst_aux = (unsigned char *) dst;
	src_aux = (unsigned char *) src;
	if (!dst || !src)
		return (0);
	while (src_aux[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < (size - 1) && src_aux[i] != '\0')
	{
		dst_aux[i] = src[i];
		i++;
	}
	dst_aux[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3rtn;
	int		i;
	int		j;

	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	s3rtn = s3;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3rtn);
}

char	*ft_strdup(char *s)
{
	int		i;
	char		*strdup;

	i = 0;
	strdup = (char *)malloc((ft_strlen(s) + 1));
	if (!strdup)
		return (NULL);
	while (s[i] != '\0')
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
