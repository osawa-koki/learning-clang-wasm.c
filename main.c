#include <stdio.h>
#include <emscripten/emscripten.h>

void println(char *str)
{
  printf("%s\n", str);
}

int main()
{
  println("Clang Program called.");
  return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE void myFunction(int argc, char **argv)
{
  println("Clang-defined function called.");
}
