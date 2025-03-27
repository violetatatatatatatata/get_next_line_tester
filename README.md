# Tester para Get Next Line con Don Quijote

## Descripción
Este tester evalúa exhaustivamente tu implementación de `get_next_line` utilizando la obra completa de *Don Quijote de la Mancha* como archivo de prueba. Está diseñado para verificar:

- Manejo correcto de archivos muy grandes
- Funcionamiento con diferentes tamaños de buffer
- Gestión adecuada de memoria (sin leaks)
- Comportamiento con líneas de distintas longitudes

## Cómo usar

### Compilación
make
./tester don_quijote.txt
valgrind --leak-check=full --show-leak-kinds=all ./tester don_quijote.txt
