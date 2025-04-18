package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type Matrix [][]float64

type MatrixQueue struct {
	startRow int
	endRow   int
	a        Matrix
	b        Matrix
}

func generateMatrix(rows, cols int) Matrix {
	matrix := make(Matrix, rows)
	for i := range matrix {
		matrix[i] = make([]float64, cols)
		for j := range matrix[i] {
			matrix[i][j] = rand.Float64() * 2.0
		}
	}
	return matrix
}

func multiplyMatrix(a, b Matrix, res Matrix, startRow, endRow int, mtx *sync.Mutex) {
	m := len(a[0])
	n := len(b[0])

	for i := startRow; i < endRow; i++ {
		for j := 0; j < n; j++ {
			sum := 0.0
			for k := 0; k < m; k++ {
				sum += a[i][k] * b[k][j]
			}
			mtx.Lock()
			res[i][j] = sum
			mtx.Unlock()
		}
	}
}

func worker(id int, jobs <-chan MatrixQueue, res Matrix, mtx *sync.Mutex, wg *sync.WaitGroup) {
	defer wg.Done()

	for job := range jobs {
		fmt.Printf("\nWorker %d Multiplying matrices\n", id)
		start := time.Now()
		multiplyMatrix(job.a, job.b, res, job.startRow, job.endRow, mtx)
		duration := time.Since(start).Seconds()
		fmt.Printf("\nWorker %d finished multiplication in: %.4f seconds", id, duration)
	}
}

func main() {
	const SIZE = 500
	THREADS := 8

	fmt.Printf("Generating matrices of %dx%d...", SIZE, SIZE)
	a := generateMatrix(SIZE, SIZE)
	b := generateMatrix(SIZE, SIZE)

	res := make(Matrix, SIZE)
	for i := range res {
		res[i] = make([]float64, SIZE)
	}

	jobs := make(chan MatrixQueue, THREADS)

	var resMtx sync.Mutex
	var wg sync.WaitGroup

	for i := 0; i < THREADS; i++ {
		wg.Add(1)
		go worker(i, jobs, res, &resMtx, &wg)
	}

	rowsPerThread := SIZE / THREADS
	extraRows := SIZE % THREADS
	startRow := 0

	start := time.Now()

	for i := 0; i < THREADS; i++ {
		endRow := startRow + rowsPerThread
		if i < extraRows {
			endRow++
		}

		jobs <- MatrixQueue{
			startRow: startRow,
			endRow:   endRow,
			a:        a,
			b:        b,
		}
		startRow = endRow
	}

	close(jobs)
	wg.Wait()

	duration := time.Since(start).Seconds()
	fmt.Printf("\nFinished matrix Multiplication in %.4f seconds\n", duration)

	fmt.Println("Verifying one element")
	checkRow, checkCol := 0, 0
	expected := 0.0
	for k := 0; k < SIZE; k++ {
		expected += a[checkRow][k] * b[k][checkCol]
	}
	fmt.Printf("Exepcted: %.4f, Got: %.4f (Difference: %.8f)\n",
		expected, res[checkRow][checkCol], expected-res[checkRow][checkCol])

}
