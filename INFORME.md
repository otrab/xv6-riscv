*Pasos seguidos para instalar xv6
1.- instale homebrew porque me facilita la instalación de QEMU y el 
toolchain de RISC-V, que son necesarios para compilar y ejecutar xv6.
2.- instla qemu , "brew install qemu"
3.-se instala Toolchain, "brew tap riscv/riscv - brew install riscv-tools"
4.-clonar el repositorio 
5.-se crea una nueva rama "git checkout -b ruth_zanabria"
6.-se debe compilar "make"
7.-ejecutamos "make qemu" para iniciar el sistema 
8.- se ejecutaron algunos comandos para verificar  "$ ls   $ echo "Hola 
xv6"    $ cat README"

*Problemas encontrados y soluciones
1.-Error al intentar instalar riscv-tools debido a que se encontraba en 
distintas carpetas
solucion: usando el comando "brew install 
riscv-software-src/riscv/riscv-gnu-toolchain" se especifico la ubicacion 
concreta de este.
2.-los procesos de instalacion eran lentos.
solucion: Se intentó cancelar el proceso en la terminal y reiniciar la 
instalación.
3.-Al ejecutar make qemu, aparecía el error exec make failed.
solucion:se reinicio ademas se verificó que todas las herramientas 
necesarias estuvieran instaladas correctamente.
4.-Otro problema fue que era necesario instalar el toolchain, pero el 
proceso de instalación tardaba mucho. Por eso, busqué una alternativa como 
Homebrew para hacerlo más rápido.

*Confirmación de que xv6 está funcionando correctamente

$ ls                
 1 1 1024
..             1 1 1024
README         2 2 2403
cat            2 3 35584
echo           2 4 34448
forktest       2 5 16280
grep           2 6 39032
init           2 7 34896
kill           2 8 34368
ln             2 9 34176
ls             2 10 37704
mkdir          2 11 34432
rm             2 12 34408
sh             2 13 57160
stressfs       2 14 35296
usertests      2 15 181208
grind          2 16 50872
wc             2 17 36576
zombie         2 18 33768
console        3 19 0

$ echo "Hola xv6"
"Hola xv6"


$ cat README
xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern RISC-V multiprocessor using ANSI C.

ACKNOWLEDGMENTS....
