package main

import (
	"fmt"
	"sync"
	"time"
)

type BoundedBlockingQueue struct {
	ch chan int
}

func NewQueue(capacity int) *BoundedBlockingQueue {
	return &BoundedBlockingQueue{
		ch: make(chan int, capacity),
	}
}

func (q *BoundedBlockingQueue) push(element int) {
	q.ch <- element
}

func (q *BoundedBlockingQueue) pop() int {
	return <-q.ch
}

func (q *BoundedBlockingQueue) size() int {
	return len(q.ch)
}

func (q *BoundedBlockingQueue) Capacity() int {
	return cap(q.ch)
}

func main() {
	q := NewQueue(8)
	var wg sync.WaitGroup

	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 1; i <= 10; i++ {
			fmt.Println("Produding:", i)
			q.push(i)
			time.Sleep(500 * time.Millisecond)
		}
		close(q.ch)
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for val := range q.ch {
			fmt.Println("Consumed:", val)
			time.Sleep(1500 * time.Millisecond)
		}
	}()
	wg.Wait()
}
