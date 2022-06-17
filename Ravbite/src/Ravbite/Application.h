#pragma once

#include "Ravbite/Core.h"
#include "Ravbite/Window.h"

#include "Ravbite/Events/EventHandler.h"
#include "Ravbite/Events/Events.h"

namespace Ravbite {

	class RAVBITE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void run();

		bool handleEvent(Event& event);

	private:
		bool onClose(WindowClose& closeEvent);

		std::unique_ptr<Window> m_window;

		bool m_run = true;

	};

	Application* createApplication();

}
