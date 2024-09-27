# Tarea 2: Programación de Procesos en xv6

## Objetivo
Modificar el programador de procesos en xv6 para implementar un sistema de prioridades.

### Modificaciones Requeridas
1. **Incorporar Prioridad**
   - Agregar un campo de prioridad.
   - Inicializar prioridad en 0.

2. **Incorporar Boost**
   - Agregar un campo de boost.
   - Inicializar en 1.

### Consejos
- Revisar el código existente en xv6.
- Documentar las modificaciones.

## Detalle Entrega
   - Al código fuente de xv6, agregar un campo de prioridad a la estructura de proceso.
   - Inicializar la prioridad de cada proceso en 0 (menor número = mayor prioridad).
   - Agregar un campo de boost a la estructura de proceso.
   - Inicializar el boost en 1.
   - Cada vez que un proceso ingresa, aumentar la prioridad de todos los procesos existentes que puedan ser ejecutados (no zombies).
   - Implementar la lógica: `Prioridad += Boost`.
   - Si la prioridad alcanza 9, cambiar el boost a -1.
   - Si la prioridad llega a 0, cambiar el boost a 1.
   - Crear programa de prueba.

## Pruebas
### Crear un programa que:
- Utilice `fork` para crear al menos 20 procesos.
- Cada proceso muestre un mensaje en pantalla al ejecutarse, con el formato: “Ejecutando proceso <nombre> <pid>”.
- Incluya un `sleep` para hacer que los procesos se detengan unos segundos.

## Consejos (Hints)
- Revisar el código del programador de procesos existente para entender cómo se gestionan los procesos.
- Asegurarse de que los cambios no afecten negativamente el funcionamiento general del sistema.
- Documentar adecuadamente las modificaciones realizadas.

## Entrega
- Código fuente modificado de xv6.
- Programa de prueba.
- Informe (archivo "README") detallando:
  - Funcionamiento y lógica del sistema de prioridades.
  - Explicación de las modificaciones realizadas.
  - Dificultades encontradas y soluciones implementadas.

## Instrucciones de Entrega
1. Crear una nueva rama en tu fork de xv6 para esta tarea.
2. Realizar cambios y commits en esta rama.
3. Subir la rama a tu fork en GitHub.
4. Proporcionar en el buzón de WebC:
   - El enlace a tu rama en GitHub (https://github.com/tu_usuario/xv6-riscv/tree/nombre_apellido_t2)
   - Tu informe debe ser el archivo README

## Recursos
- [Documentación de xv6](https://pdos.csail.mit.edu/6.828/2020/xv6.html)
- [Libro de xv6 (PDF)](https://pdos.csail.mit.edu/6.828/2020/xv6/book-riscv-rev1.pdf)
- [Repositorio de xv6 en GitHub](https://github.com/otrab/xv6-riscv)

## Fecha de Entrega
14/10/2024 23:59

## Evaluación (Rúbrica)

### Implementación (60 puntos)
- Correcta implementación de la estructura de prioridad y boost: 40 puntos
- Programa de prueba y su integración: 20 puntos


### Calidad general (considerado en la puntuación de las implementaciones) (10 puntos)
- Claridad del código y comentarios
- Calidad de la documentación en README


**Total: 70 puntos (máximo)**

¡Buena suerte con tu tarea!
