package main

// #cgo LDFLAGS: -Llib -lmylib_a
// #cgo CPPFLAGS: -Ilib
// #include "cmylib.h"
import "C"

import (
	"unsafe"
)

type GoFoo struct {
     foo C.Foo
}
func New() (GoFoo) {
     var ret GoFoo;
     ret.foo = C.FooInit()
     return ret
}
func (f GoFoo) Free(){
     C.FooFree(C.Foo(unsafe.Pointer(f.foo)))
}
func (f GoFoo) Bar(){
     C.FooBar(C.Foo(unsafe.Pointer(f.foo)))
}

func main() {
    mylib := New()
    mylib.Bar()
    mylib.Free()
}
