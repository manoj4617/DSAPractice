package main

import "fmt"

func main() {
	var x int = 10
	y := 20

	fmt.Println("static allocations")
	fmt.Println("x: %d", x)
	fmt.Println("y: %d", y)

	ptr := new(int)
	*ptr = 30

	fmt.Println("Dynamic allocation: %d", *ptr)

	slice := make([]int, 10)
	for i := 0; i < 10; i++ {
		slice[i] = i
	}
	fmt.Println("slice: ", slice[2:8])

}
