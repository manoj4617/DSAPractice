package logger

import (
	"fmt"
)

type ConsoleLogger struct{}

func (consle ConsoleLogger) LogInfo(msg string) {
	fmt.Println("[INFO]", msg)
}

func (console ConsoleLogger) LogError(msg string) {
	fmt.Println("[ERROR]", msg)
}
