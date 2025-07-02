#pragma once
namespace dx3d
{

	class Logger final
	{
	public:
		enum class LogLevel {
			Error = 0,
			Warning,
			Info
		};
		explicit Logger(LogLevel logLevel= LogLevel::Error);
		void log(LogLevel level, const char* message) const;
		LogLevel m_logLevel = LogLevel::Error;
	};
}