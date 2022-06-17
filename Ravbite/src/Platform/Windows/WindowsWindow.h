#pragma once

#include <GLFW/glfw3.h>

#include "Ravbite/Core.h"
#include "Ravbite/Window.h"

namespace Ravbite {

	class RAVBITE_API WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

	private:
		void create(const WindowProperties& properties);
		void destroy();

		virtual void update() override;

		virtual EventHandler& getEventHandler() override;

		virtual unsigned int getWidth() const override;
		virtual unsigned int getHeight() const override;
		virtual void getSize(int* width, int* height) const override;

		virtual unsigned int getSwapInterval() const override;
		virtual void setSwapInterval(unsigned int interval) override;

		virtual const std::string& getTitle() const override;
		virtual void setTitle(std::string&& title) override;

	private:
		GLFWwindow* m_window;
		std::string m_title;
		unsigned int m_swapInterval = 0;

		EventHandler m_eventHandler;

	};

}