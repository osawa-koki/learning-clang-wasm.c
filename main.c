#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>
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

EXTERN EMSCRIPTEN_KEEPALIVE void myFunction()
{
  println("Clang-defined function called.");
}

EXTERN EMSCRIPTEN_KEEPALIVE char *concat(char *str1, char *str2)
{
  char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1);
  strcpy(result, str1);
  strcat(result, str2);
  return result;
}

EXTERN EMSCRIPTEN_KEEPALIVE void showElement(char *id)
{
  EM_ASM({
    var id = UTF8ToString($0);
    var element = document.getElementById(id);
    console.log(element);
  }, id);
}
