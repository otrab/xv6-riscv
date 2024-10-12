#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64 
sys_getppid(void){
 struct proc *p = myproc();
 return p->parent->pid;
}


uint64
sys_getancestor(void) {
    int n = 0;
    argint(0, &n);  // Asignamos el primer argumento de la llamada al sistema a n

    struct proc *p = myproc();
    if (p == 0) {
        return -1;  // Si no hay proceso, retornar -1
    }

    switch(n) {
        case 0:
            return p->pid;  // Retornar PID del proceso actual
        case 1:
            if (p->parent)
                return p->parent->pid;  // Retornar PID del padre
            else
                return -1;  // No hay padre
        case 2:
            if (p->parent && p->parent->parent)
                return p->parent->parent->pid;  // Retornar PID del abuelo
            else
                return -1;  // No hay abuelo
        default:
            return -1;  // Para cualquier otro caso, retornar -1
    }
}

