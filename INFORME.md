Configuración del Entorno

Paso 1: Instalación de Ubuntu en WSL
Instalé WSL (Windows Subsystem for Linux) en mi computadora Windows siguiendo los pasos oficiales de Microsoft.
Luego, descargué e instalé Ubuntu desde Chrome.

Paso2: Configurara VScode
Configuré VSCode para trabajar con el entorno de desarrollo WSL, instalando las extensiones necesarias para la integración.

Paso 3: Instalación de Herramientas de Desarrollo
En Ubuntu, instalé las herramientas de desarrollo necesarias para compilar y ejecutar Xv6

Paso4: Clonar repositorio
Cloné el repositorio de Xv6 desde GitHub en mi directorio de trabajo.
----------------------------------------------------------------------------------------------------------------------------
Problemas Encontrados y Soluciones

Problema 1: Incompatibilidad con Funciones de Temporización

Al intentar compilar y ejecutar Xv6, encontré problemas de compatibilidad con las siguientes funciones en el archivo riscv.h:
r_stimecmp()
w_stimecmp(uint64 x)
r_menvcfg()
w_menvcfg(uint64 x)

Solución:

Comenté temporalmente las funciones mencionadas en riscv.h para evitar que causen errores durante la compilación.

Problema 2: Incompatibilidad en el Archivo start.c

También encontré un problema al inicializar la interrupción del temporizador en el archivo start.c en la siguiente línea:
w_stimecmp(r_time() + 1000000);

Solución:

Comenté la línea mencionada para evitar el error, lo que permitió que Xv6 se ejecutara sin problemas.
----------------------------------------------------------------------------------------------------------------------------
Con las funciones comentadas, Xv6 se compila y se ejecuta correctamente en mi entorno configurado en WSL.