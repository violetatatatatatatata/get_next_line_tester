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
	char		*new_line;
	char		*linea;

	if (fd < 0 || BUFF_SIZE <= 0)				// si el error con fd o buffer negativo
		return (NULL);
	new_line = ft_strchr(cache, '\n');			// buscar si la línea tiene un salto de línea, retorna nulo si no
	while (new_line == NULL)					// mientras que no se encuentre el salto de línea
	{
        leido = read(fd, texto, BUFF_SIZE);		// leer conforme el buffer lo permita
		if (leido <= 0)							// si EOF (0) o error (-1)
		{
			if (leido == 0 && cache != NULL)	// si es EOF y la caché N0 está vacía
			{
				linea = ft_strdup(cache);		// copiar la caché a la línea
				free(cache);					// liberar caché
				cache = NULL;	// por qué ??
				return (linea)					// retornar la línea
			}
			return (NULL);						// caso contrario, la caché sí estaba vacía y EOF
		}
		texto[leido] = '\0';					// añadir carácter nulo al final del texto leido
		cache = ft_strjoin(cache, texto);		// concatenar caché y texto
		if (!cache)
			return (NULL);
		new_line = ft_strchr(cache, '\n');	// Buscar salto de línea nuevamente
		
	return (linea);
	free(cache);
}