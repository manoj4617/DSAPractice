package main

import (
	"log"
	"mylogger/logger"
)

func main() {
	var l logger.Logger

	l = logger.ConsoleLogger{}
	l.LogInfo("Running in console")
	l.LogError("Console Error")

	fileLogger, err := logger.NewfileLogger("test.log")

	if err != nil {
		log.Fatal(err)
	}

	l = fileLogger
	l.LogInfo("Now logging to a file")
	l.LogError("Something failed in the file")
}
