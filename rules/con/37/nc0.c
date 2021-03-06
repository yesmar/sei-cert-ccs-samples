// CON37-C: Noncompliant Code Example
#include <signal.h>
#include <stddef.h>
#include <threads.h>
  
volatile sig_atomic_t flag = 0;
 
void handler(int signum) {
  flag = 1;
}
 
/* Runs until user sends SIGUSR1 */
int func(void *data) {
  while (!flag) {
    /* ... */
  }
  return 0;
}
 
int main(void) {
  signal(SIGUSR1, handler); /* Undefined behavior */
  thrd_t tid;
   
  if (thrd_success != thrd_create(&tid, func, NULL)) {
    /* Handle error */
  }
  /* ... */
  return 0;
}
