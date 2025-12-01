#include <stdio.h>
#include <stdlib.h>

int move_R(int dial, int num);
int move_L(int dial, int num);

int main() {
  FILE *file_ptr;

  file_ptr = fopen("input", "r");

  if (file_ptr == NULL) {
    printf("error while creating a file pointer to input file\n");
    exit(1);
  }

  char line[256];
  int dial = 50;
  int pwd = 0;

  while (fgets(line, sizeof(line), file_ptr) != NULL) {
    int num = atoi(line + 1);
    if (num == 0) {
      printf("something went wrong with the conversion of a number\n");
      exit(1);
    }
    switch (line[0]) {
    case 'L':
      dial = (dial - num) % 100;
      if (dial < 0) {
        dial = 100 - abs(dial);
      }

      if (dial == 0)
        pwd++;
      break;
    case 'R':
      dial = (dial + num) % 100;

      if (dial == 0)
        pwd++;
      break;
    default:
      printf("what? %c\n", line[0]);
      exit(1);
    }
  }
  printf("Password is %i\n", pwd);
  fclose(file_ptr);
}