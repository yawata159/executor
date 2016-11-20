//Seiji Yawata+Felix Rieg-Baumhauer pd 5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
      
  char input[100];//where we deposit our strings, only 100 bytes allowed
  printf("Prompt: ");
  fgets(input, sizeof(input), stdin);
  input[strlen(input)-1] = 0; //remove newline

  //printf("%s\n", input);
  
  //char input[] = "ls -l\n";

  char * command[100];
  char *s = input;
  char *p;

  //how we turn our input into an array
  int i = 0;
  while (s) {
    command[i] = strsep(&s, " ");
    i++;
  }
  command[i] = 0;// the termnating null

  //a way to print the array//
  /*
  int q = 0;
  while (command[q]) {
    printf("++%s\n", command[q]);
    q++;
  }
  */
  
  execvp(command[0], command);
  return 0;
}
