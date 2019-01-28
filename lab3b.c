/* lab3b.c */
/* Warning: This program contains a security vulnerability. For academic use only. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln(char *data) {
  char small_buffer[12];

  strcpy(small_buffer, data);

  return;
}

int main(int argc, char **argv) {
  char input_buffer[500];
  FILE *input_file;

  input_file = fopen("./exploit_b", "r");
  fread(input_buffer, sizeof(char), 499, input_file);
  input_buffer[499] = '\0';
  vuln(input_buffer);
  printf("Returned to main\n");
  return 0;
}
