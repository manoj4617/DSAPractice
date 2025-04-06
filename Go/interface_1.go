package main

import "fmt"

type Shape interface {
	Area() float64
}

type Circle struct {
	radius float64
}

type Square struct {
	side float64
}

func (c Circle) Area() float64 {
	return 3.14 * c.radius * c.radius
}

func (s Square) Area() float64 {
	return s.side * s.side
}
func main() {
	var s Shape = Circle{10}
	fmt.Println("Circle Area: ", s.Area())

	var sq Shape = Square{4}
	fmt.Println("Squre Area: ", sq.Area())
}
