
# Implementación de Permisos Básicos en xv6 (RISC-V)

## Objetivo:
Implementar un sistema de permisos básicos en xv6 (risc) que permita modificar archivos para tener acceso de solo lectura o lectura/escritura, y agregar un nuevo permiso especial para hacerlo inmutable.

## Detalles:
Cuando un archivo se abre (ver `sys_open` en `sysfile.c`), se puede pasar un modo de apertura (`omode`). Actualmente, el modo define si el archivo va a ser de lectura, escritura o ambos. Pero queremos que el modo de apertura sea compatible con los permisos que tiene asignado el inode. Es decir, si el inode dice que el archivo es solo lectura, entonces no se puede abrir como escritura, o viceversa.

## Modificaciones necesarias:
## Primera parte:

1. **(1 punto) Modificación de la estructura de inode:**
   - Añadir un campo en el inode que contenga bits de permisos para definir si el archivo es de solo lectura o de lectura/escritura. Use un `int`, donde 0 significa que no tiene permiso ni de lectura ni escritura, 1 significa permiso de lectura, 2 de escritura, y 3 que tiene ambos. El valor al crear el inode debe ser 3.

2. **(2 puntos) Modificar las operaciones de apertura, lectura y escritura:**
   - Modificar las funciones que gestionan operaciones de archivos para que respeten estos permisos. Por ejemplo: Si un archivo está marcado como de solo lectura, no debe permitir que se abra en modo de escritura y devolver un error.

3. **(1 punto) Crear la llamada al sistema `chmod(archivo:char*, modo:int)`:**
   - Implementar `chmod` para cambiar los permisos para cualquier archivo, dado el `int` que se recibe como parámetro.

4. **(0.5 puntos) Pruebas:**
   - Crear un programa que cree un archivo y cambie sus permisos.
   - El programa debe:
     - **Creación del Archivo:** Se crea un archivo con permisos de lectura y escritura (`O_CREATE | O_RDWR`).
     - **Escritura Inicial:** Se escribe en el archivo para asegurar que la creación y escritura funcionan en modo lectura/escritura. Cerrar el archivo.
     - **Cambio de Permisos a Solo Lectura:** Se usa `chmod(filename, 1)` para cambiar los permisos a solo lectura.
     - **Prueba de Escritura con Solo Lectura:** El programa intenta abrir el archivo en modo escritura (`O_WRONLY`). Se verifica que no sea posible escribir en el archivo.
     - **Cambio de Permisos de Vuelta a Lectura/Escritura:** Con `chmod(filename, 3)`, se cambian los permisos de vuelta a lectura/escritura.
     - **Escritura Final:** El programa vuelve a escribir en el archivo para confirmar que los permisos de escritura han sido restaurados. Cerrar el archivo.

## Segunda parte:

1. **(1 punto) Agregar un permiso especial (el número 5), que marque un archivo como inmutable. Al tener este permiso habilitado:**
    - El archivo debe ser considerado como solo lectura, y 
    - NO se puede modificar el permiso nunca más con `chmod` (es decir, `chmod` debe fallar si el archivo está marcado como inmutable).

2. **(0.5 puntos) Pruebas:**
    - Modificar el programa anterior. Después de la escritura final,
     - **Cambio de Permisos a inmutable:** Se usa `chmod(filename, 5)`.
     - **Prueba de Escritura con Solo Lectura:** El programa intenta abrir el archivo en modo escritura (`O_WRONLY`). Se verifica que no sea posible escribir en el archivo.
     - **Cambio de Permisos de Vuelta a Lectura/Escritura:** Con `chmod(filename, 3)`, se tratan de cambiar los permisos de vuelta a lectura/escritura, pero debe fallar.

---
## Consejos (Hints)

   -  Revisar el código existente en xv6 para entender cómo se gestionan las tablas de páginas.
   - Documentar adecuadamente las modificaciones realizadas.

## Entrega

   -  Código fuente modificado de xv6.
    - Programa de prueba.
   -  Informe (archivo "README.md") detallando:
    -    Funcionamiento y lógica.
    -    Explicación de las modificaciones realizadas.
- Dificultades encontradas y soluciones implementadas.

## Instrucciones de Entrega

   - Crear una nueva rama en tu fork de xv6 para esta tarea.
    - Realizar cambios y commits en esta rama.
  -   Subir la rama a tu fork en GitHub.
  -  Proporcionar en el buzón de WebC:
  -  El enlace a tu rama en GitHub (https://github.com/tu_usuario/xv6-riscv/tree/nombre_apellido_t4)
  -  Tu informe debe ser el archivo README.
## Evaluación

- **(1 punto)** Modificación de `inode`: Agregar un campo para permisos (lectura, escritura, ambos), con valor inicial 3 (lectura/escritura).
- **(2 puntos)** Operaciones con permisos: Modificar apertura, lectura y escritura para respetar los permisos definidos en el `inode`.
- **(1 punto)** Implementación de `chmod`: Crear una llamada al sistema para cambiar los permisos de un archivo.
- **(0.5 puntos)** Pruebas básicas: Programa que valide creación, cambio de permisos y restricciones en operaciones según permisos.
- **(1 punto)** Permiso inmutable: Agregar el permiso especial (5) para marcar un archivo como inmutable, evitando modificaciones y cambios de permisos.
- **(0.5 puntos)** Pruebas inmutabilidad: Validar que un archivo inmutable no permita escritura ni cambios de permisos.


---

## Recursos adicionales

- [Documentación xv6](https://pdos.csail.mit.edu/6.828/2021/xv6.html)
- [Referencia sobre permisos de archivos Unix](https://en.wikipedia.org/wiki/File_system_permissions)
