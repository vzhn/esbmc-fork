#include <assert.h>

/* A file-scope asm declaration, as in GCC 14's <iostream>: no effect on
 * the program's behaviour */
__asm__(".globl file_scope_asm_marker");

int main()
{
  int x = 1;
  assert(x == 2);
  return 0;
}
