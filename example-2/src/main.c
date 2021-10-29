/**
 * @brief The documenation is partly copied from https://opensource.com/article/19/5/how-write-good-c-main-function
 */
#include <stdio.h>  // Supplies FILE, stdin, stdout, stderr, and the fprint() family of functions
#include <stdlib.h> // Supplies malloc(), calloc(), and realloc()
#include <string.h> // Supplies memcpy(), memset(), and the strlen() family of functions
#include <stdint.h> // Typedef shortcuts like uint32_t and uint64_t

#include "library.h"

/**
 * @brief The main function is called at program startup after initialization of the non-local objects with static storage duration.
 * See also https://en.cppreference.com/w/c/language/main_function
 * @param argc Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.
 * @param argv Pointer to the first element of an array of argc + 1 pointers, of which the last one is null and the previous ones,
 * if any, point to strings that represent the arguments passed to the program from the host environment.
 * If argv[0] is not a null pointer (or, equivalently, if argc > 0), it points to a string that represents the program name,
 * which is empty if the program name is not available from the host environment.
 * @return The values zero and EXIT_SUCCESS indicate successful termination, the value EXIT_FAILURE indicates unsuccessful termination.
 */
int main(int argc, char *argv[])
{
  printf("Hello World!\n");
  Library.method1();
  Library.method2(5);
  return EXIT_SUCCESS;
}