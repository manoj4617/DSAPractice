package main

import "fmt"

func sum(nums ...int) {
	fmt.Println(nums)
	total := 0
	for idx, num := range nums {
		fmt.Println("idx: ", idx)
		total += num
	}
	fmt.Println(total)
}

func main() {
	sum(1, 2)
	sum(1, 2, 3)

	nums := []int{1, 2, 3, 5, 10}
	sum(nums...)
}
