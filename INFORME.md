# INFORME DE INSTALACIÓN DE xv6

## Pasos Seguidos para Instalar xv6

1. **Clonar el Repositorio de xv6:**
    ```bash
    git clone https://github.com/aliturriaga/xv6-riscv.git
    cd xv6-riscv
    ```

2. **Crear una Nueva Rama:**
    ```bash
    git checkout -b tarea0
    ```

3. **Instalar Dependencias Necesarias:**
    Instalación de GCC y binutils para la arquitectura RISC-V:
    ```bash
    sudo apt install gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
    sudo apt install qemu-system-misc
    ```

4. **Compilar xv6:**
    ```bash
    make
    ```

5. **Ejecutar xv6:**
    ```bash
    make qemu
    ```

## Problemas Encontrados y Soluciones

### Problema 1: Error al encontrar GCC/binutils para RISC-V
- **Mensaje de error:** "Couldn't find a riscv64 version of GCC/binutils."
- **Solución:** Se instalaron los paquetes `gcc-riscv64-linux-gnu` y `binutils-riscv64-linux-gnu` con `apt`.

### Problema 2: Error "qemu-system-riscv64: No such file or directory"
- **Mensaje de error:** "make: qemu-system-riscv64: No such file or directory"
- **Solución:** Se instaló QEMU con soporte para RISC-V utilizando `sudo apt install qemu-system-misc`.

## Confirmación de que xv6 está Funcionando Correctamente

El sistema operativo xv6 ha iniciado correctamente en el emulador QEMU para RISC-V. Se observa el siguiente mensaje de inicio:
xv6 kernel is booting hart 1 starting hart 2 starting init: starting sh
Se pudo interactuar con el sistema utilizando comandos en la consola de xv6, como `ls`, `echo`, y `cat`. La instalación ha sido exitosa y el sistema operativo está funcionando correctamente.
