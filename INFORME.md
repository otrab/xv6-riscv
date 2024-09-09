<<<<<<< HEAD
--------------------------Tarea0--------------------------------------------

Para la instalacion de sv6, primero se tuvo que instalar un maquina virtual y 
luego ubuntu para la terminal de linux, luego se clono el repositorio de xv6 y qemu. 
No se tuvo complicaciones para la instalación de qemu, se intentó hacer por windows pero 
no se logró, por lo que se trabajará en la maquina virtual

--------------------------Tarea1-------------------------------------

Para la llamada getppid se agrego a:
los archivos correspondiente sobre su instalación y la definición de la llamada se hizo en proc.c,
para el funcionamiento de esta llamada se creo el archivo yosoytupadre, el cual quedo comentado 
debido a que se creó la llamada de getancestor. Para el funcionamiento de la llamada, luego de
ejecutar el qemu, se debe ingresar en la terminal "yosoytupadre" y se retornará el id del padre del
proceso actual.
Para la llamada getancestor se agregó a:
los archivos correspondientes, se tuvo que tomar en cuenta que habia una complicación para la 
definición de la llamada, ya que se debia ingresar un entero en la terminal, por lo cual se queria utilizar 
argint, pero esta tenía complicaciones de entero, ya que estaba como void, además la llamada debía 
estar como uint64, por lo que habia que hacer 2 cambios de variables. Por la complicaciones que esto tenia,
se tomó la decisión de cambiar la función y se utilizó otra función, por último para el funcionamiento de 
la llamada, se utilizó el archivo yosoytupadre, cuando se este corriendo el qemu, se tiene que ingresar
en la terminal se debe ingresar "yosoytupadre n", en donde n sera el ancestro que se quiera saber, en el caso 
de 0 se retornará el proceso actual, si es 1 se retorna el proceso padre, y si es 2 se retorna el proceso abuelo
, en caso de que no tenga un ancestro, se retorna -1.

