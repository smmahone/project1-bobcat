#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// source
// https://stackoverflow.com/questions/3866217/how-can-i-make-the-system-call-write-print-to-the-screen
// https://stackoverflow.com/questions/15883568/reading-from-stdin
int main(int argc, char *argv[]) {
  int fptr;
  int readPtr;
  char total[4096];
  int success_check = 0;
  for (int x = 1; x < argc; x++) {
    if (strcmp(argv[x], "-") == 0) {
      readPtr = read(STDIN_FILENO, total, 4096);
      while (readPtr > 0) {
        write(1, total, readPtr);
        readPtr = read(STDIN_FILENO, total, 4096);
      }
    } else {
      fptr = open(argv[x], 2);
      if (fptr == -1) {
        warn("%s", argv[x]);
        success_check++;
      } else {
        readPtr = read(fptr, total, 4096);
        while (readPtr != 0) {
          write(1, total, readPtr);
          readPtr = read(fptr, total, 4096);
        }
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
// I had a horrible time figuring out how to push this, ask the TAs ^^;, luckily
// I saved my finished project so once I did finally figure it out, I could put
// it back in.
