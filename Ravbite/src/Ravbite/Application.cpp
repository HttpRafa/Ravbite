#include "rbpch.h"
#include "Ravbite/Application.h"
#include "Ravbite/Log.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Ravbite {

	#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->getEventHandler().typeSubscribe<WindowClose>(BIND_EVENT(onClose));
		m_window->getEventHandler().subscribe(BIND_EVENT(handleEvent));
	}

	Application::~Application()
	{

	}

	bool Application::handleEvent(Event& event) {
		RB_CORE_TRACE(event);
		return false;
	}

	bool Application::onClose(WindowClose& closeEvent) {
		m_run = false;
		return false;
	}

	void Application::run()
	{
		while (m_run) {
			m_window->update();
		}
	}

}
