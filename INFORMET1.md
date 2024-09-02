# Tarea 1


## 1. Dirección y nueva rama:


### 1.1. En primer lugar nos aseguramos de estar en “/home/nico/Escritorio/Sistemas_Operativos/xv6-riscv” con el comando “pwd”. 

### 1.2. Luego creamos la nueva rama llamada Tarea_1 para empezar la modificación solicitada con el comando “git checkout -b Tarea_1”, para verificar que estámos en la rama Tarea_1, usamos “git branch” (Efectivamente estamos dentro).

## 2. Busqueda de información sobre llamada a sistema:

### 2.1. Investigación sobre cómo y dónde se crea la llamada a sistema getpid() y para qué sirve para poder relaciónarlo y obtener la máxima información posible para aplicar nuestra nueva llamada a Sistema llamada getpidd(void).

## 3. Implementación de la llamada a sistema “getppid()”:

### 3.1. Definimos la llamada de sistema en el Kernel:

-    **Modificamos “syscall.h”**

    - Abriendo el archivo desde el kernel y añadimos una definición para “SYS_getppid” al final de la lista (es importante respetar el número de cada función y su orden).

-   **Añadimos la implementación de la función en el archivo “sysproc.c”** 

    - Que está dentro del kernel, la gracia es que esta función será llamada cuando se invoque “getppid” desde el terminal. Siendo esta la función que obtiene el proceso actual y devuelve el ID del proceso padre.

-   **Modificamos el archivo “syscall.c”**

    - Para registrar la nueva llamada a sistema, añadiendo la ceclaración de la función en la lista de funciones de llamadas, “extern uint64 sys_getppid(void); “, luego agregamos “sys_getppid” en el arreglo “syscalls”.

-   **Modificamos el espacio de usuario**

    - Para poder invocar la nueva llamada al sistema, por lo que abrimos el archivo user.h dentro de user y añadimos la declaración de la función “getppid” al final de las funciones que existen, en conjunto de agregar unas librerias que permiten el funcionamiento del cambio.

-   **Luego abrimos el archivo ulib.c**

    - Dentro de user para añadir la implementación de la función “getppid”, función que el código del usuario llamará.

-   **Agregamos la definición de nuestra función getppid dentro del archivo “sysproc.c”**

    - Para que quede de esta forma constatado y disponible para su llamada.

-   **yosoytupadre.c**

    - Ahora para poder probar la nueva llamada en la carpeta “user” creamos un archivo llamado “yosoytupadre.c” que devuelva su propio ID y el de su “padre”, llamando a getpid y getppid.

    -Para que esto funcione (luego de encontrar y solucionar un error), es necesario actualizar el archivo “usys.pl” agregando la entrada para que sea reconocida, llamada getppid. Por otro lado también fue necesario actualizar las librerias que hereda ulib.c, específicamente de syscalls.

    - A su vez, es necesario modificar el archivo “usys.s” , donde es necesario agregar el syscall de la función getppid() al final del archivo.

    - Para que esto funcione debemos modificar el archivo Makefile para añadir nuestro nuevo archivo “yosoytupadre” a la lista “UPROGS” para que se compile automaticámente.

-   **Test**

    - Ahora probamos usando “make clean” y luego “make qemu” y luego en el terminal de XV6 usamos “yosoytupadre”. Obteniendo una salida del tipo:

				    Padre PID : [Id padre]


### 3.2. Problematicas: 

-   Especificamente me tope con la problematica de que el archivo creado “yosoytupadre.c” no era reconocido por el programa, lo cual me llevó a investigar y darme cuenta que ciertas conexiónes no habian sido realizadas, como por ejemplo la actualización del archivo “usys.pl” en donde se agregaba efectivamente la entrada del getppid para que funcionase efectivamente la compilación y retornara el valor un valor de id padre. Por otro lado también tuve problemas con las Syscalls, ya que por alguna razón que desconocia en su momento, no estaba logrando generar las llamadas a sistema necesarios para compilar, lo que no me permitia ni siquiera utilizar make qemu, para ello encontré la solución de actualizar las librerias que estaba utilizando el archivo ulib.c.

## 4. Implementación Avanzada ( int getancestor(int) ):

-   **Recreamos lo realizado con getppid()**

-   Para continuar con la implementación avanzada repetimos todos los pasos que realizamos con la llamada a sistema getppid() pero con la diferencia de que necesitamos modificar la funcionalidad de esta, cumpliendo que podamos retornar los ancestros solicitados por la tarea misma. Desde el 0 al 2, siendo 0 el mismo proceso, 1 su padre y 2 su abuelo. Teniendo en cuenta que si el número no es válido, se coloque como retorno un -1. Por lo tanto generamos los cambios en los archivos necesarios, agregando a “getancestor(int)” cómo llamada número 23 luego de “getppid()” y modificamos el archivo yosoytupadre.c para que pueda consultar tanto a getppid() como getancestor() probando todas sus funciones y obteniendo un resultado de la forma:


			Padre PID: <id_del_padre>

            Ancestro 0 (mismo proceso): <id_del_proceso_actual>

            Ancestro 1 (padre): <id_del_padre>

            Ancestro 2 (abuelo): <id_del_abuelo>

            Ancestro 10 (inválido): -1
