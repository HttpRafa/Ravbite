#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Ravbite {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowCloseEvent event;
		RB_WARN(event);

		while (true) {}
	}

}