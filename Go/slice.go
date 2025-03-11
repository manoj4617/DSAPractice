package main

import "fmt"

func main() {

	var ss []int
	fmt.Println(ss, ss == nil)

	s := []int{1, 2, 3}
	fmt.Println(s)

	s2 := make([]int, 5)
	fmt.Println(s2)

	s3 := make([]int, 3, 5)
	fmt.Println(len(s3), cap(s3))

	twoD := make([][]int, 7)

	for i := 0; i < 7; i++ {
		innerlen := i + 1
		twoD[i] = make([]int, innerlen)
		for j := 0; j < innerlen; j++ {
			twoD[i][j] = i + j
		}
	}

	fmt.Println(twoD)

}
