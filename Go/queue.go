package main

import "fmt"

type Queue struct {
	queue []int
}

func (q Queue) len() int {
	return len(q.queue)
}

func (q Queue) capacity() int {
	return cap(q.queue)
}

func (q *Queue) push(val int) {
	q.queue = append(q.queue, val)
}

func (q *Queue) pop() int {
	if len(q.queue) == 0 {
		return -1
	}
	val := q.queue[0]
	q.queue = q.queue[1:]
	return val
}

func (q Queue) empty() bool {
	return len(q.queue) == 0
}

func main() {
	var q Queue = Queue{}

	q.push(10)
	q.push(2)
	q.push(4)
	q.push(5)
	q.push(1)

	fmt.Println(q.queue)
	val := q.pop()
	fmt.Println("popped val:", val)
	fmt.Println(q.queue)
	fmt.Println("Is queue empty: ", q.empty())

}
