package main

import (
	"fmt"
	"log"
)

type node[T any] struct {
	next *node[T]
	val  T
}

type stack[T any] struct {
	head *node[T]
	size int
	cap  int
}

func (st *stack[T]) push(v T) {
	if st.cap == st.size {
		log.Fatal("stack over flow, abort!!")
		return
	}

	new_node := node[T]{val: v}
	new_node.next = st.head
	st.head = &new_node
	st.size += 1
}

func (st *stack[T]) pop() {
	if st.size == 0 {
		log.Fatal("stack is empty")
		return
	}
	st.head = st.head.next
	st.size -= 1
}

func (st *stack[T]) top() (T, bool) {
	if st.size == 0 {
		log.Fatal("stack is empty")
		var zero T
		return zero, false
	}

	return st.head.val, true
}

func (st *stack[T]) print() {
	if st.size == 0 {
		fmt.Println("stack is empty")
		return
	}

	for ele := st.head; ele != nil; ele = ele.next {
		fmt.Println(ele.val)
	}
}

func main() {
	st := stack[int]{cap: 8}
	st.push(10)
	st.push(8)
	st.push(7)
	st.push(1)
	st.push(5)

	st.pop()

	topVal, ok := st.top()
	if ok {
		fmt.Println("Top element:", topVal)
	} else {
		fmt.Println("Stack is empty")
	}

	st.print()

}
