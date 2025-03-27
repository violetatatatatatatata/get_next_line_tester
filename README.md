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

### Características del tester
Lectura línea por línea del texto completo

Informe de tiempo de ejecución

Conteo de líneas procesadas

Detección de líneas mal formadas

Verificación exhaustiva de memory leaks
