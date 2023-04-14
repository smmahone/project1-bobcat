#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fptr;
  int readPtr;
  char total[4096];
  int success_check = 0;
  for (int x = 1; x < argc; x++) {
    fptr = open(argv[x], 2);
    if (fptr == -1) {
      warn("%s", argv[x]);
      success_check++;
    } else {
        readPtr = read(fptr, total, 4096);
        while (readPtr != 0) {
          write(readPtr, total, sizeof(total));
          readPtr = read(fptr, total, 4096);
        }
      }
  }
  if (fptr != -1) {
    close(fptr);
  }
  if (success_check != 0) {
    return success_check;
  } else {
    return EXIT_SUCCESS;
  }
}
//I had a horrible time figuring out how to push this, ask the TAs ^^;, luckily I saved my finished project so once I did finally figure
//it out, I could put it back in.
