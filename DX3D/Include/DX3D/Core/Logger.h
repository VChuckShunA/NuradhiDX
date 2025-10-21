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
		~Logger();
	protected:
		//Rule of 5
		//share this behaviour across all the classes in our egnien
		Logger(const Logger&) = delete;  // no copy‑constructor
		Logger(Logger&&) = delete; // no move‑constructor
		Logger& operator = (const Logger&) = delete; // no copy‑assignment
		Logger& operator =(Logger&&) = delete; // no move‑assignment

	private:
		LogLevel m_logLevel = LogLevel::Error;
	};

#define DX3DLogInfo(message)\
	getLogger().log((Logger::LogLevel::Info), message);

#define DX3DLogWarning(message)\
	getLogger().log((Logger::LogLevel::Warning), message);

#define DX3DLogError(message)\
	getLogger().log((Logger::LogLevel::Error), message);

#define DX3DLogErrorAndThrow(message)\
	{\
	DX3DLogError(message);\
	throw std::runtime_error(message);\
	}
}

//#define DX3DGraphicsLogThrowOnFail(hr,message)\
//	{\
//	auto res = (hr);\
//	if (FAILED(res))\
//		DX3DLogError(message);\
//	}