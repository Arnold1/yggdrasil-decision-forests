// mylib.c
#include "mylib.hh"
#include "cmylib.h"

Foo FooInit()
{
  cxxFoo * ret = new cxxFoo(1);
  return (void*)ret;
}
void FooFree(Foo f)
{
  cxxFoo * foo = (cxxFoo*)f;
  delete foo;
}
void FooBar(Foo f)
{
  cxxFoo * foo = (cxxFoo*)f;
  foo->Bar();
}
