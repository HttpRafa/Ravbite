#pragma once

#include "Ravbite/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ravbite {

	class RAVBITE_API Log {

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;

	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
			return s_coreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
			return s_clientLogger;
		}

	};

}

#define RB_CORE_TRACE(...) ::Ravbite::Log::getCoreLogger()->trace(__VA_ARGS__)
#define RB_CORE_INFO(...) ::Ravbite::Log::getCoreLogger()->info(__VA_ARGS__)
#define RB_CORE_WARN(...) ::Ravbite::Log::getCoreLogger()->warn(__VA_ARGS__)
#define RB_CORE_ERROR(...) ::Ravbite::Log::getCoreLogger()->error(__VA_ARGS__)
#define RB_CORE_CRITICAL(...) ::Ravbite::Log::getCoreLogger()->critical(__VA_ARGS__)

#define RB_TRACE(...) ::Ravbite::Log::getClientLogger()->trace(__VA_ARGS__)
#define RB_INFO(...) ::Ravbite::Log::getClientLogger()->info(__VA_ARGS__)
#define RB_WARN(...) ::Ravbite::Log::getClientLogger()->warn(__VA_ARGS__)
#define RB_ERROR(...) ::Ravbite::Log::getClientLogger()->error(__VA_ARGS__)
#define RB_CRITICAL(...) ::Ravbite::Log::getClientLogger()->critical(__VA_ARGS__)
