#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char unused_string[16] = "UNUSED STRING";
  char name[16] = "NO NAME";

  printf("Enter your name: ");
  gets(name);
  
  printf("Hello, %s\n", name);
  printf("unused_string: %s\n", unused_string);
}
