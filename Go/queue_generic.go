package main

import "fmt"

type node[T any] struct {
	next  *node[T]
	value T
}

type queue[T any] struct {
	head     *node[T]
	tail     *node[T]
	size     int
	capacity int
}

func (q *queue[T]) push(val T) bool {
	if q.size == q.capacity {
		fmt.Println("Queue is full\n")
		return false
	}
	new_node := &node[T]{value: val}
	if q.tail == nil {
		q.head = new_node
		q.tail = new_node
	} else {
		q.tail.next = new_node
		q.tail = new_node
	}
	q.size++
	return true
}

func (q *queue[T]) pop() {
	if q.size == 0 {
		fmt.Println("Queue is empty")
		return
	}

	q.head = q.head.next
	q.size--
	if q.head == nil {
		q.tail = nil
	}
}

func (q *queue[T]) peek() (T, bool) {
	if q.size == 0 {
		fmt.Println("Queue is empty")
		var zero T
		return zero, false
	}
	return q.head.value, true
}

func (q *queue[T]) print() {
	if q.size == 0 {
		fmt.Println("Queue is empty")
	}
	for ele := q.head; ele != nil; ele = ele.next {
		fmt.Println(ele.value)
	}
}

func main() {
	q := queue[int]{capacity: 10}
	q.push(10)
	q.push(3)
	q.push(4)

	if val, ok := q.peek(); ok {
		fmt.Println("Peeked:", val)
	}

	q.push(7)
	q.print()

	q.pop()

	q.push(1)
	q.push(13)

	q.pop()
	q.push(12)

	q.print()

}
