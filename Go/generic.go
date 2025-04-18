package main

import "fmt"

func printSlice[T any](s []T) {
	for _, v := range s {
		fmt.Println(v)
	}
}

type Pair[T any, U any] struct {
	First  T
	Second U
}

type Adder[T int | float64] interface {
	~int | ~float64
}

func main() {
	printSlice([]int{1, 2, 3, 4})
	printSlice([]string{"m", "a", "n", "o", "j"})

	p := Pair[int, string]{1, "Manoj"}
	fmt.Println(p)
	q := Pair[string, string]{First: "Some", Second: "pair"}
	fmt.Println(q)
}
