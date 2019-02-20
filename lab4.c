/* lab4.c */
/* Warning: This program contains a security vulnerability. For academic use only. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln(char *data) {
  char small_buffer[12];

  memcpy(small_buffer, data, 40);
}

int main(int argc, char **argv) {
  char input_buffer[40];
  FILE *input_file;

  input_file = fopen("./lab4file", "r");
  fread(input_buffer, sizeof(char), 40, input_file);
  input_buffer[39] = '\0';
  vuln(input_buffer);
  printf("Returned to main\n");
  return 0;
}
