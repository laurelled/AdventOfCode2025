#include <stdio.h>
#include <stdlib.h>

int move_R(int dial, int num);
int move_L(int dial, int num);

#define MAX_ROTATION 100

int main() {
  FILE *file_ptr;

  file_ptr = fopen("input", "r");

  if (file_ptr == NULL) {
    printf("error while creating a file pointer to input file\n");
    exit(1);
  }

  char line[256];
  int dial = 50;
  int pwd_p1 = 0;
  int pwd_p2 = 0;

  while (fgets(line, sizeof(line), file_ptr) != NULL) {
    int num = atoi(line + 1);
    if (num == 0) {
      printf("something went wrong with the conversion of a number\n");
      exit(1);
    }
    switch (line[0]) {
    case 'L':
      for (register int i = 0; i < num; i++) {
        dial--;
        if (dial < 0) {
          dial = 99;
        } else if (dial == 0) {
          pwd_p2++;
        }
      }

      if (dial == 0)
        pwd_p1++;
      break;
    case 'R':
      for (register int i = 0; i < num; i++) {
        dial++;
        if (dial > 99) {
          dial = 0;
          pwd_p2++;
        }
      }

      if (dial == 0)
        pwd_p1++;
      break;
    default:
      printf("what? %c\n", line[0]);
      exit(1);
    }
  }
  printf("Password 1 is %i\n", pwd_p1);
  printf("Password 2 is %i\n", pwd_p2);
  fclose(file_ptr);
}