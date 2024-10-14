<<<<<<< HEAD
--------------------------Tarea0--------------------------------------------
=======
Tarea 0


Para la instalacion de sv6, primero se tuvo que instalar un maquina virtual y 
luego ubuntu para la terminal de linux, luego se clono el repositorio de xv6 y qemu. 
No se tuvo complicaciones para la instalación de qemu, se intentó hacer por windows pero 
no se logró, por lo que se trabajará en la maquina virtual

-----------------------------------------------------

Tarea 1

Para la llamada getppid se agrego a:
-sysprc.c
-proc.h
-syscall.h
-syscall.c
-user.h
-usys.S
Se creó la carpeta yosoytupadre.c para probar el funcionamiento de la llamada
Por ultimo se incluyo yosoytupadre en el makefile.

---------------------------------------------------------------------------------
Tarea 2

Se agrega priority y boost a los archivos de syscall.c, syscall.h,user.h, usys.S, proc.h.
Se crea el manejor de estos elementos en proc.c ( seccion de allocproc , schedule y al final del codigo), y sysproc.c. 
Aqui se ejustar las prioridades y como se manejan cuando se crea un proceso.
Por ultimo se cambia la cantidad de CPU, la cual estaba en 3 y pasa a 1.

