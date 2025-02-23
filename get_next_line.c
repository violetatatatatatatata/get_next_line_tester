/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:32:41 by avelandr          #+#    #+#             */
/*   Updated: 2025/02/21 15:46:12 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*content;
	char	*new_cache;
	char	*line;
	int	len;

	len = 0;
	content = memory_cache(fd);
	if (!content || *content == '\0')
		return (NULL);
	while (content[len] && content[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, content, len + 1);
	if (content[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	if (content[len] == '\0')
		new_cache = NULL;
	else
		new_cache = ft_strdup(content + len);
	free(content);
	content = new_cache;
	return (line);
}

char	*update_cache(char *cache, char *buffer)
{
	char	*temp;

	if (!cache)
		return ft_strdup(buffer);
	temp = ft_strjoin(cache, buffer);
	free(cache);
	return (temp);
}

char	*memory_cache(int fd)
{
	ssize_t		line_len;
	static char	*cache;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0)
		return (NULL);
	line_len = read(fd, buffer, BUFF_SIZE);
	while (line_len > 0)
	{
		buffer[line_len] = '\0';
		cache = update_cache(cache, buffer);
		line_len = read(fd, buffer, BUFF_SIZE);
	}
	if (line_len == -1)
	{
		free(cache);
		cache = NULL;
	}
	return (cache);
}
