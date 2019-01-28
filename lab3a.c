/* lab3a.c */
/* Warning: This program contains a security vulnerability. For academic use only. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void unused_function() {
  printf("This function is not normally executed!\n");
}

void func(void) {
  char buffer[32];
  printf("Reading data into buffer\n");
  gets(buffer);

  return;
}

int main(int argc, char **argv) {
  func();
  printf("Returned to main\n");  
  
  return 0;
}
