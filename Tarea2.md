# Informe: Implementación de Sistema de Prioridades en xv6

## Funcionamiento y Lógica del Sistema de Prioridades
El sistema de prioridades fue implementado modificando la estructura `proc` para incluir un campo de **prioridad** y **boost**. Los procesos inician con prioridad 0 (máxima prioridad) y boost en 1. Cada vez que un proceso ingresa, las prioridades de los procesos **RUNNABLE** aumentan de acuerdo al valor de su boost. Cuando la prioridad llega a 9, el boost se cambia a -1 para reducir la prioridad; si llega a 0, el boost vuelve a 1.

El scheduler selecciona el proceso con menor prioridad (mayor urgencia) para ejecutarse.

## Modificaciones Realizadas
- Se incluyeron los cambios no abordados en la tarea 1 no entregada.
- **proc.c**: Se añadieron los campos de prioridad y boost a la estructura `proc`, y la lógica para gestionar estos campos en la función `allocproc()`. El scheduler fue modificado para elegir procesos con base en la prioridad.
- **proc.h**: Se añadieron los campos `priority` y `boost` a la estructura `proc`.
- **priority_test.c**: Programa que utiliza `fork()` para crear 20 procesos. Cada proceso muestra un mensaje con su nombre y PID, y su ejecución está escalonada con un retraso de `sleep()` para simular una diferencia de prioridad.

## Dificultades Encontradas y Soluciones Implementadas
Inicialmente, la implementación generaba problemas al ejecutar los procesos forkeados en simultáneo. Se empleó un ajuste con `sleep(i);` para escalonar las ejecuciones y asegurar que los mensajes en consola fueran legibles. Al ejecutar en WSL, fue necesario comentar algunas líneas de código relacionadas con registros de estado de control (CSR) en `kernel/riscv.h`, para que QEMU pudiera ejecutarse sin errores en el entorno de WSL.

## Conclusión
El sistema de prioridades y boost implementado en xv6 funciona correctamente, permitiendo un mejor control sobre el scheduler y la ejecución de procesos. El programa de prueba demostró la funcionalidad de la modificación con la creación de 20 procesos forkeados con prioridades diferenciadas.
