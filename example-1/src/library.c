#include "library.h"
#include <stdio.h>

void method1(void)
{
  printf("method1\n");
}
void method2(int arg)
{
  printf("method2: %d\n", arg);
}

const struct library Library = {
  .method1 = method1,
  .method2 = method2,
  .some_value = 36,
};