Primero cloné el repositorio y creé una nueva rama con mi nombre.
Al estar utilizando macOS, tuve que ocupar Homebrew para instalar las dependencias, las cuales fueron las siguientes:

brew install qemu gdb
brew tap riscv/riscv
brew install riscv-tools

Tuve que instalar las herramientas de RISC-V usando un tap adicional con brew tap riscv/riscv. Sin esto, los comandos riscv-tools no estaban disponibles.

Aunque QEMU es compatible con macOS, en algunos casos pueden presentarse advertencias al compilar, pero no afectaron la ejecución de xv6.

Al usar GDB en macOS, es posible que necesites otorgar permisos especiales debido a las restricciones de seguridad de macOS. Esto se resolvió otorgando acceso a la terminal en la configuración de Seguridad y Privacidad de macOS.

Una vez instaladas las dependencias correctamente, compilé el proyecto con el comando 'make'
Luego, ejecuté xv6 en QEMU con el comando make qemu.
Y por último, probé los siguientes comandos para verificar que se habia instalado correctamente

$ ls
$ echo "Hola xv6"
$ cat README

El tiempo total para instalar las dependencias fue de aproximadamente 10-15 minutos. La instalación de Homebrew tomó alrededor de 5 minutos, mientras que la instalación de qemu, gdb, y riscv-tools tomó otros 10 minutos, dependiendo de la velocidad de la conexión a internet, la cual, no erea muy buena debido a que ocupé el wifi de la universidad.

Después de ejecutar los comandos en QEMU, pude verificar que xv6 estaba funcionando correctamente. Todos los comandos como ls, echo y cat se ejecutaron sin problemas.