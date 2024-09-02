# INFORME DE INSTALACIÓN DE xv6


## 1. Pasos seguidos para Instalar Xv6


### 1.1. Preparación del Entorno:

- **Instalación de Oracle VirtualBox**:

	- Descargué e instalé Oracle VirtualBox en mi sistema operativo Windows principal.

- **Creación de una Máquina Virtual**:

	- Configuré una máquina virtual en VirtualBox con Ubuntu 24.04 como sistema operativo.

### 1.2. Configuración de Ubuntu:

- **Descarga de paquetes y aplicaciónes**: 

	- En este paso descargué y actualicé todos los paquetes necesarios para su uso, en conjunto de VisualStudioCode para tener un entorno más agíl a la hora de usar el terminal, además descargué git para  poder luego clonar el repositorio necesario. 

### 1.3 Clonación y descarga del Repositorio:

- **Realizar fork y Clonar**:

	- Anteriormente se realizó en Github un Fork del repositorio principal del profesor, luego cloné mi repositorio dentro de ubuntu.

### 1.4 Compilación y pruebas de Xv6:

	- Ejecutamos y probamos Xv6 con "make qemu" , al ver que funciona usamos "ls" y un "echo" conjunto de ver el "README" para verificar que todo esté en orden.


## 2. Problemas de instalación:

-**Intento de Ubuntu 22.04 en Windows 11** :

	- En un principio realicé el proceso completo de descarga de Xv6 pero dentro de Ubuntu sin una virtual box que lo "Separara" de mi sistema operativo principal Windows 11, esto me llevó a tener problemas con el ToolChain de compilación para el Sistema operatico Xv6, ya que este no funcionaba de ninguna forma.

-**Solución**:

	- La solución implementada luego de investigación, fue la implementación de una VirtualBox (Oracle) que permitiera generar un sistema hermético para poder compilar con un nuevo Ubuntu el sistema Xv6.

