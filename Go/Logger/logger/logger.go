package logger

type Logger interface {
	LogInfo(msg string)
	LogError(msg string)
}
