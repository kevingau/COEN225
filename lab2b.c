#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void check(int code) {
  int success_code = 0x434f454e;
  
  if (code == success_code) {
    printf("Success! You got the right code!\n");
  } else {
    printf("Unsucessful. Try again.\n");
  }
}

int main(int argc, char **argv) {
  volatile int secret_int = 0;
  volatile int unused_int = 0;
  char name[16] = "NO NAME";

  printf("Enter your name: ");
  gets(name);
  
  printf("Hello, %s\n", name);
  
  if (unused_int != 0) {
    check(secret_int);
  }
}
