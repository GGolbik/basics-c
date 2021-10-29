#include <stdio.h>
#include "../src/library.h"

int main(int argc, char *argv[])
{
  printf("Run tests!\n");

  Library.method1();
  Library.method2(5);

  return 0;
}