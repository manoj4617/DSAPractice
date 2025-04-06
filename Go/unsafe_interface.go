package main

import (
	"fmt"
	"reflect"
	"unsafe"
)

type geometry interface {
	area() float64
}

type rect struct {
	width, height float64
}

func (r rect) area() float64 {
	return r.width * r.height
}

func main() {
	var g geometry = rect{9, 8}

	iface := (*[2]uintptr)(unsafe.Pointer(&g))
	fmt.Printf("itab: 0x%x\n", iface[0])
	fmt.Printf("itab: 0x%x\n", iface[1])

	method := reflect.ValueOf(g).MethodByName("area")
	fmt.Printf("Area method address; 0x%x\n", method.Pointer())
}
