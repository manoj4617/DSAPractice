package main

import "fmt"

type IntHeap []int

func (v IntHeap) Len() int {
	return len(v)
}

// Reference receiver
func (v *IntHeap) Push(x int) bool {
	*v = append(*v, x)
	if v != nil {
		return true
	} else {
		return false
	}
}

func main() {
	heap := IntHeap{1, 2, 3, 4}

	fmt.Println("Len: ", heap.Len())
	if heap.Push(23) {
		fmt.Println("Len: ", heap.Len())
	}

}
