package main

import "fmt"

type List[T any] struct {
	head, tail *element[T]
}

type element[T any] struct {
	next *element[T]
	val  T
}

func (list *List[T]) Push(v T) {
	if list.tail == nil {
		list.head = &element[T]{val: v}
		list.tail = list.head
	} else {
		list.tail.next = &element[T]{val: v}
		list.tail = list.tail.next
	}
}

func (list *List[T]) AllElements() []T {
	var elems []T

	for e := list.head; e != nil; e = e.next {
		elems = append(elems, e.val)
	}
	return elems
}

func main() {
	lst := List[int]{}
	lst.Push(3)
	lst.Push(13)
	lst.Push(0)
	lst.Push(30)
	lst.Push(45)

	fmt.Println("List: ", lst.AllElements())

	lst1 := List[string]{}
	lst1.Push("manoj")
	lst1.Push("sumedha")
	lst1.Push("akash")
	lst1.Push("anuj")
	fmt.Println("List: ", lst1.AllElements())

}
