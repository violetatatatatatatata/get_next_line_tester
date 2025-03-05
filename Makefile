# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avelandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 12:30:28 by avelandr          #+#    #+#              #
#    Updated: 2025/03/05 16:35:17 by avelandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Nombre del ejecutable de pruebas
TESTER = tester

# Directorio del código fuente
SRC_DIR = ..
SRC_FILES = $(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c
HEADERS = $(SRC_DIR)/get_next_line.h

# Archivos objeto
OBJS = $(SRC_FILES:.c=.o)

# Archivo de prueba
MAIN = main.c

# Regla por defecto
all: $(TESTER)

# Compilar el tester con get_next_line
$(TESTER): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) -o $(TESTER)

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)

# Limpiar todo
fclean: clean
	rm -f $(TESTER)

# Recompilar desde cero
re: fclean all

# Regla para ejecutar el tester
test: $(TESTER)
	./$(TESTER)

.PHONY: all clean fclean re test

