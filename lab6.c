/* lab6.c */
/* Warning: This program contains a security vulnerability. For academic use only. */
#include <stdio.h>
#include <stdlib.h>

int SECRETVALUE;

int main(int argc, char *argv[]) {
  /* Be aware of the local variables on the stack. You will need to 
   * move printf's argument pointer through these
   */
  char format_str[60];
  int *secrets;
  int hex_input;
  volatile int a = 1;
  volatile int b = 2;
  volatile int c = 3;

  /* The secret value will be stored on the heap */
  secrets = (int *) malloc(sizeof(int) * 2);

  /* Generate a random secret value and set it for secrets[0]
   * Your objective will be to set secrets[1] to the secret value also
   */
  time_t t;
  srand((unsigned) time(&t));
  SECRETVALUE = (rand() % 26) + 65;
  secrets[0] = SECRETVALUE;
  secrets[1] = 0;

  /* You won't need these for the attack itself but it may help in
   * understanding the stack layout
   */
  printf("&hex_input = 0x%x\n", (unsigned int)&hex_input);
  printf("&secrets = 0x%x\n", (unsigned int)&secrets);
    
  while(1) {
    printf("Please enter a hexadecimal integer\n");
    scanf("%x", &hex_input); // This may help putting an address on the stack...
    printf("Please enter a string\n");
    scanf("%s", format_str); // This is where your format string is entered

    /* This runs the inputted format string*/
    printf(format_str);
    printf("\n");

    printf("Performing checks...\n");
    /* You should not modify secrets[0]. You only need to change secrets[1] */
    if (secrets[0] != SECRETVALUE) {
      printf("Error! You may not modify secrets[0]\n");
      return -1;
	}
	/* Check if secrets[1] matches the secret value. If it does, success! */
    printf("secrets[1] is 0x%x (%d)\n", secrets[1], secrets[1]);
    if (secrets[1] == SECRETVALUE) {
      printf("Congratulations! secrets[1] matches SECRETVALUE\n");
      break;
    }
  }
  return 0;
}
