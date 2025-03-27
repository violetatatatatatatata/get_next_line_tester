# Tester para Get Next Line con Don Quijote

## Descripción
Este tester evalúa exhaustivamente tu implementación de `get_next_line` utilizando la obra completa de *Don Quijote de la Mancha* como archivo de prueba. Está diseñado para verificar:

- Manejo correcto de archivos muy grandes
- Funcionamiento con diferentes tamaños de buffer
- Gestión adecuada de memoria (sin leaks)
- Comportamiento con líneas de distintas longitudes

## Cómo usar

### Compilación
```bash
cd tester/
make
Ejecución básica
bash
Copy
./tester don_quijote.txt
Ejecución con Valgrind
bash
Copy
valgrind --leak-check=full --show-leak-kinds=all ./tester don_quijote.txt
Con buffer size personalizado
bash
Copy
BUFFER_SIZE=42 ./tester don_quijote.txt
Comandos Makefile
Comando	Descripción
make	Compila el tester
make test	Compila y ejecuta las pruebas
make clean	Elimina archivos objeto
make fclean	Limpieza completa
make re	Recompila desde cero
Requisitos
Compilador C (gcc/clang)

Valgrind (opcional)

Archivo don_quijote.txt en el directorio tester/

Características del tester
Lectura línea por línea del texto completo

Informe de tiempo de ejecución

Conteo de líneas procesadas

Detección de líneas mal formadas

Verificación exhaustiva de memory leaks
