# Informe - Tarea 0 - Sistemas Operativos

## Introducción

Este informe detalla los pasos seguidos para configurar y ejecutar el sistema operativo `xv6-riscv` en un entorno `WSL` (Windows Subsystem for Linux) utilizando `Ubuntu 20.04`.

## Pasos Realizados

### 1. **Eliminación de Distribución Ubuntu-20.04 en WSL**

Para asegurar un entorno limpio, primero se eliminó la distribución existente de `Ubuntu-20.04` en `WSL`:

```bash
wsl --list
wsl --unregister Ubuntu-20.04

### 2. **Instalación de una Nueva Distribución de Ubuntu-20.04 en WSL**
Posteriormente, se reinstaló la distribución:
```bash
wsl --install -d Ubuntu-20.04

### 3. **Actualización del Entorno y Preparación para 'xv6-riscv'**
Una vez instalada la nueva distribución, se actualizó el entorno y se instalaron las herramientas necesarias:

```bash
sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install build-essential gdb qemu-system-misc git -y

### 4. **Clonación del Repositorio 'xv6-riscv'**

El siguiente paso fue clonar el repositorio de xv6-riscv:
```bash
git clone https://github.com/03matig/xv6-riscv-03matig.git
cd xv6-riscv

### 5. **Instalación del Toolchain RISC-V**

Para compilar el proyecto, fue necesario instalar el toolchain de RISC-V:
```bash
sudo apt-get install gcc-riscv64-unknown-elf
sudo apt-get install binutils-riscv64-unknown-elf

### 6. **Compilación y Ejecución de 'xv6-riscv'**

Después de instalar las herramientas necesarias, se procedió a compilar y ejecutar xv6-riscv:

```bash
make clean
make qemu

### 7. **Solución de problemas**
Durante la compilación, se encontraron errores relacionados con registros de estado de control (CSR) no reconocidos. Para solucionar este problema, se realizaron los siguientes pasos:
- Instalación de QEMU:
```bash
sudo apt-get update
sudo apt-get install qemu qemu-kvm qemu-system-x86 qemu-system-riscv64

- Modificación temporal del código: Se intentó comentar las funciones relacionadas con menvcfg y stimecmp, pero debido a la dependencia de estas funciones, se decidió revertir los cambios.

### 8. **Conclusiones**
Finalmente, el sistema xv6-riscv fue compilado y ejecutado correctamente en el entorno WSL después de instalar las herramientas y dependencias necesarias, y de resolver los problemas de compilación relacionados con los registros CSR.

### **Referencias**
Repositorio de xv6-riscv: https://github.com/otrab/xv6-riscv
Documentación y pasos realizados en el archivo T0.md del repositorio.
