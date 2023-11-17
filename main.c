#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  int fd = open("fuse-dir/hello", O_RDONLY);
  char *data = mmap(NULL, 10, PROT_READ, MAP_PRIVATE, fd, 0);

  printf("waiting\n");

  char *lineptr = NULL;
  size_t n;
  getline(&lineptr, &n, stdin);
  free(lineptr);

  // It's a simple dereference!
  char c = *data;
  printf("%c\n", c);

  return close(fd);
}
