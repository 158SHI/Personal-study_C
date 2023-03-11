#include <stdio.h>

static int x1 = 0;
static int x2 = 1;

void func1(int x)
{
  printf("%d\n", x);
}

__attribute__((section("FOO"))) int global = 10;//为全局变量自定义段名

int main()
{
  func1(1);
  return 0;
}
