package main

import "fmt"

func main() {
	m := make(map[string]int) //map[key]value

	m["k1"] = 7
	m["k2"] = 8

	fmt.Println(m)
	v1 := m["k1"]
	fmt.Println("v1:", v1)

	v2 := m["k2"]
	fmt.Println("v2:", v2)

	delete(m, "k1")
	fmt.Println(m)

	clear(m)
	fmt.Println(m)

	_, prs := m["k2"] // to check if there is a value present for the key
	fmt.Println("prs:", prs)
}
