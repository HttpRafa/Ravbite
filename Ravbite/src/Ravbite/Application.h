#pragma once

#include "Ravbite/Core.h"

namespace Ravbite {

	class RAVBITE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();

	private:


	};

	Application* createApplication();

}
