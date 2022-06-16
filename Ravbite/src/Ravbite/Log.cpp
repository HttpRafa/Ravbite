#include "Ravbite/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Ravbite/Events/Events.h"

namespace Ravbite {

	std::shared_ptr<spdlog::logger> Log::s_coreLogger;
	std::shared_ptr<spdlog::logger> Log::s_clientLogger;

	void Log::init() {

		spdlog::set_pattern("%^[%T/%l] %n: %v%$");

		s_coreLogger = spdlog::stdout_color_mt("Core");
		s_coreLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stdout_color_mt("Application");
		s_clientLogger->set_level(spdlog::level::trace);

		s_coreLogger->info("Loggingservice initialized");
	}

}
