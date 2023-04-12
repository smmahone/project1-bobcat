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
  for (int x = 1; x < argc; x++) {
    fptr = fopen(argv[x], "r");
    while (fgets(total, 4096, fptr) != NULL) {
      printf("%s", total);
    }
  }
  fclose(fptr);
  return EXIT_SUCCESS;
}
//I had a horrible time figuring out how to push this, ask the TAs ^^;, luckily I saved my finished project so once I did finally figure
//it out, I could put it back in.