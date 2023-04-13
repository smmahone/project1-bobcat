#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  FILE *fptr;
  char total[4096];
  int success_check = 0;
  for (int x = 1; x < argc; x++) {
    fptr = fopen(argv[x], "r");
    if (fptr == NULL) {
      fprintf(stderr, "bobcat: %s: No such file or directory\n", argv[x]);
      success_check++;
    } else {
        while (fgets(total, 4096, fptr) != NULL) {
          printf("%s", total);
        }
      }
  }
  if (fptr != NULL) {
    fclose(fptr);
  }
  if (success_check != 0) {
    return success_check;
  } else {
    return EXIT_SUCCESS;
  }
}
//I had a horrible time figuring out how to push this, ask the TAs ^^;, luckily I saved my finished project so once I did finally figure
//it out, I could put it back in.
