package logger

import (
	"fmt"
	"os"
)

type FileLogger struct {
	file *os.File
}

func NewfileLogger(filePath string) (*FileLogger, error) {
	f, err := os.Create(filePath)
	if err != nil {
		return nil, err
	}
	return &FileLogger{file: f}, nil
}

func (fileLogger FileLogger) LogInfo(msg string) {
	fmt.Fprintln(fileLogger.file, "[INFO]", msg)
}

func (fileLogger FileLogger) LogError(msg string) {
	fmt.Fprintln(fileLogger.file, "[ERROR]", msg)
}
