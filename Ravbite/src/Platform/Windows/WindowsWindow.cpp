#include "rbpch.h"

#include "Platform/Windows/WindowsWindow.h"
#include "Ravbite/Events/Events.h"

namespace Ravbite {

	static bool s_glfwInit = false;

	Window* Window::create(const WindowProperties& properties) {
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties) {
		create(properties);
	}

	WindowsWindow::~WindowsWindow() {
		destroy();
	}

	void WindowsWindow::create(const WindowProperties& properties) {
		m_title = properties.m_title;
		
		RB_CORE_INFO("Creating window {0} with the size({1}, {2})", m_title, properties.m_initialWidth, properties.m_initialHeight);

		if (!s_glfwInit) {
			int result = glfwInit();
			RB_CORE_ASSERT(result, "GLFW intialize failed!");
			glfwSetErrorCallback([](int error_code, const char* description) {
				RB_CORE_CRITICAL("GLFW error[{0}]: {1}", error_code, description);
			});

			s_glfwInit = true; 
		}

		m_window = glfwCreateWindow(properties.m_initialWidth, properties.m_initialHeight, properties.m_title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, reinterpret_cast<void*>(this));

		setSwapInterval(properties.m_swapInterval);

		// Set callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* a_window, int width, int height) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));
			WindowResize event(width, height);
			window->getEventHandler().fire(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* a_window) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));
			WindowClose event;
			window->getEventHandler().fire(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* a_window, int key, int scancode, int action, int mods) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));
			
			switch (action) {
			case GLFW_PRESS: {
				KeyPressedEvent event(key, 0);
				window->getEventHandler().fire(event);
				break;
			}

			case GLFW_REPEAT: {
				KeyPressedEvent event(key, 1);
				window->getEventHandler().fire(event);
				break;
			}

			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);
				window->getEventHandler().fire(event);
				break;
			}
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* a_window, int button, int action, int mods) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));

			switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressedEvent event(button);
				window->getEventHandler().fire(event);
				break;
			}

			case GLFW_RELEASE: {
				MouseButtonReleasedEvent event(button);
				window->getEventHandler().fire(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* a_window, double x, double y) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));
			MouseScrolledEvent event(x, y);
			window->getEventHandler().fire(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* a_window, double x, double y) {
			Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(a_window));
			MouseMovedEvent event(x, y);
			window->getEventHandler().fire(event);
		});
	}

	void WindowsWindow::destroy() {
		glfwDestroyWindow(m_window);
	}

	// Overrides
	void WindowsWindow::update() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	EventHandler& WindowsWindow::getEventHandler() {
		return m_eventHandler;
	}

	unsigned int WindowsWindow::getWidth() const {
		int width = 0;
		getSize(nullptr, &width);
		return width;
	}

	unsigned int WindowsWindow::getHeight() const {
		int height = 0;
		getSize(nullptr, &height);
		return height;
	}

	void WindowsWindow::getSize(int* width, int* height) const {
		glfwGetWindowSize(m_window, width, height);
	}

	unsigned int WindowsWindow::getSwapInterval() const {
		return m_swapInterval;
	}

	void WindowsWindow::setSwapInterval(unsigned int interval) {
		m_swapInterval = interval;
		glfwSwapInterval(m_swapInterval);
	}

	const std::string& WindowsWindow::getTitle() const {
		return m_title;
	}

	void WindowsWindow::setTitle(std::string&& title) {
		m_title = std::move(title);
		glfwSetWindowTitle(m_window, m_title.c_str());
	}

}