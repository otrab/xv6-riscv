
# Implementación de Permisos Básicos en xv6 (RISC-V)

## Objetivo

Implementar un sistema de permisos básicos en xv6 que permita:

1. Configurar archivos como de solo lectura o lectura/escritura.
2. Agregar un nuevo permiso especial para marcar archivos como inmutables.

---

## Detalles

Cuando un archivo se abre (ver `sys_open` en `sysfile.c`), actualmente se pasa un modo de apertura (`omode`) que define si el archivo será de lectura, escritura o ambos. La implementación debe asegurar que este modo de apertura sea compatible con los permisos asignados al `inode`. Es decir, si el `inode` indica que el archivo es de solo lectura, no se podrá abrir como escritura, o viceversa.

---

## Modificaciones necesarias

### Primera parte

1. **Modificación de la estructura de `inode` (1 punto):**
   - Añadir un campo en el `inode` para los bits de permisos:
     - `0`: Sin permisos (ni lectura ni escritura).
     - `1`: Permiso de solo lectura.
     - `2`: Permiso de solo escritura.
     - `3`: Permisos de lectura y escritura.
   - Al crear un nuevo archivo, el valor por defecto será `3`.

2. **Respetar permisos en las operaciones de apertura, lectura y escritura (2 puntos):**
   - Modificar las funciones correspondientes para que sigan los permisos definidos en el `inode`.
   - Ejemplo: Si un archivo está marcado como solo lectura, no debe permitir abrirlo en modo escritura y debe devolver un error.

3. **Implementación de la llamada al sistema `chmod` (1 punto):**
   - Crear una llamada al sistema `chmod(char *archivo, int modo)` para cambiar los permisos de un archivo al valor indicado por `modo`.

4. **Pruebas (0.5 puntos):**
   - Crear un programa que verifique el funcionamiento de los permisos:
     - Crear un archivo con permisos de lectura y escritura.
     - Escribir datos en el archivo y cerrarlo.
     - Cambiar los permisos a solo lectura y verificar que no se puede escribir en él.
     - Cambiar los permisos de vuelta a lectura/escritura y confirmar que se puede escribir nuevamente.

### Segunda parte

1. **Agregar permiso de inmutabilidad (1 punto):**
   - Introducir el permiso `5`, que marque un archivo como inmutable.
   - Un archivo inmutable:
     - Solo puede ser leído.
     - No puede modificar sus permisos nunca más (llamadas a `chmod` deben fallar).

2. **Pruebas (0.5 puntos):**
   - Extender el programa de pruebas:
     - Marcar el archivo como inmutable.
     - Verificar que no se puede escribir en él.
     - Intentar cambiar los permisos a otro estado y confirmar que la operación falla.

---

## Archivos Modificados

- `sysfile.c`
- `fs.c`
- `stat.h`
- `inode.h`

---

## Pruebas

- **Creación y permisos iniciales:** Crear un archivo con permisos de lectura/escritura y verificar que se puede leer y escribir en él.
- **Cambio a solo lectura:** Usar `chmod` para cambiar los permisos a solo lectura y verificar que no se puede escribir.
- **Permiso inmutable:** Marcar un archivo como inmutable y confirmar que no se puede escribir ni cambiar sus permisos.

---

## Compilación

Para compilar el sistema después de realizar las modificaciones, ejecutar:

```bash
make clean
make qemu
```

---

## Recursos adicionales

- [Documentación xv6](https://pdos.csail.mit.edu/6.828/2021/xv6.html)
- [Referencia sobre permisos de archivos Unix](https://en.wikipedia.org/wiki/File_system_permissions)
