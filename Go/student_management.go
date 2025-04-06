package main

import (
	"fmt"
)

type Student struct {
	id     int
	name   string
	grades map[string]int
}

var student []Student

func AddStudent(name string, grades map[string]int) int {

	newId := 1
	if len(student) >= 1 {
		newId = student[len(student)-1].id + 1
	}
	student = append(student, Student{id: newId, name: name, grades: grades})
	return newId
}

func GetStudent(id int) (Student, bool) {
	for _, stu := range student {
		if stu.id == id {
			return stu, true
		}
	}
	return Student{}, false
}

func (s *Student) UpdateMarks(id int, subject string, marks int) bool {
	for i := range student {
		if student[i].id == id {
			if _, exists := student[i].grades[subject]; exists {
				student[i].grades[subject] = marks
				return true
			}
			return false
		}
	}
	return false
}

func CalculateAvarage(grades map[string]int) float64 {
	total := 0
	for _, mark := range grades {
		total += mark
	}
	return float64(total) / float64(len(grades))
}

func CalculateTotalMarks(grades map[string]int) int {
	total := 0
	for _, mark := range grades {
		total += mark
	}
	return total
}

func TopStudent() (Student, int) {
	maxMarks := 0
	topStudnet := Student{}

	for _, stu := range student {
		currentMarks := CalculateTotalMarks(stu.grades)
		if maxMarks < currentMarks {
			maxMarks = currentMarks
			topStudnet = stu
		}
	}
	return topStudnet, maxMarks
}

func AverageMarks(id int) (float64, bool) {
	for _, stu := range student {
		if stu.id == id {
			return CalculateAvarage(stu.grades), true
		}
	}
	return -1, false
}

func PrintAllStudents() {
	for _, stu := range student {
		fmt.Println(stu)
	}
}

func main() {
	s := Student{}
	AddStudent("Manoj", map[string]int{"Math": 90, "Science": 85})
	AddStudent("Sumedha", map[string]int{"Math": 57, "Science": 80})

	// fmt.Println("Student with ID : 1", GetStudent(1))
	if stu, found := GetStudent(2); found {
		fmt.Println("Student with ID 2:", stu)
	} else {
		fmt.Println("No Student with ID 2")
	}

	s.UpdateMarks(1, "Math", 15)
	s.UpdateMarks(2, "Science", 100)
	PrintAllStudents()
	if avg, found := AverageMarks(1); found {
		fmt.Printf("Average marks for ID 1: %.2f\n", avg)
	} else {
		fmt.Println("No Student with ID 1")
	}

	stu, totalMarks := TopStudent()
	fmt.Printf("%s with highest Marks: %d", stu.name, totalMarks)
}
