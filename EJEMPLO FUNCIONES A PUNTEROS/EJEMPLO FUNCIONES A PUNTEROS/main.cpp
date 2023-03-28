//DIEGO MÁRQUEZ GÓMEZ
//ID 245119

// FUENTES = http://www.it.uc3m.es/pbasanta/asng/course_notes/pointers_to_functions_es.html

#include <stdio.h>
void imprime(){
  printf("Imprimiendo un message\n");
}
int  main(){
  void (*ptr_funct)(void)=imprime;
  ptr_funct();
  return 0;
 }

