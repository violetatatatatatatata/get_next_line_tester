/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:25:20 by avelandr          #+#    #+#             */
/*   Updated: 2025/02/26 03:40:48 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	- fd es un entero que identifica el proceso ejecutado, los estandar son
	0(stdin), 1(stdout) y 2(stderr)
	- buffer es un puntero al bloque de memoria donde se almacenan los datos
	ha de ser lo suficientemente grande para contener count, si no, concatenar
	- count es el numero de bytes por leer
	- read() retorna el numero de bytes leidos, -1 (error) o 0 (EOF)
*/

char	*get_next_line(int fd)
{
	static char	*cache;
	int			leido;
	char		texto[BUFF_SIZE + 1];
	char		*linea;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	new_line = ft_strchr(cache, '\n');
	while (new_line = NULL)
	{
        leido = read(fd, texto, BUFF_SIZE);
		if (leido <= 0)
		{
			if (leido == 0 && cache != NULL)
			{
				linea = ft_strdup(cache);
				free(cache);
				cache = NULL;
				return (linea)
			}
			return (NULL);
		}
		texto[leido] = '\0';
		cache = ft_strjoin(cache, texto);
		if (!cache)
		{
			return (NULL);
			free(cache);
		}
		if (is_new_line(&cache))
			linea = ft_strchr(cache, '\n');
	}
	if (!cache)
		return (NULL);
	else
		return (cache);
	return (linea);
	free(cache);
}

int	is_new_line(char str)
{
	if (str == '\n')
		return (0);
	else
		return (1);
}
