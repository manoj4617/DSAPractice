package main

import "fmt"

type Person struct {
	name string
	age  int
}

func newPerson(name string) *Person {
	p := Person{name: name}
	p.age = 45
	return &p
}

func main() {
	fmt.Println(Person{"Bob", 20})
	fmt.Println(Person{name: "Manoj", age: 25})
	fmt.Println(Person{name: "Sumedha"})
	fmt.Println(&Person{name: "Anne", age: 40})
	fmt.Println(newPerson("Anuj"))

	dog := struct {
		name   string
		isGood bool
	}{
		"Rex",
		true,
	}

	fmt.Println(dog)
}
