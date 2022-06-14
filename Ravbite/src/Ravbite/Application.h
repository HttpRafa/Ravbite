#pragma once

#include "Core.h"

namespace Ravbite {

	class RB_API Application {

	public:
		Application();
		virtual ~Application();

		void run();

	};

	Application* createApplication();

}

