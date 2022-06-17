#pragma once

#include "Core.h"
#include "Events/EventHandler.h"

namespace Ravbite {

	struct RAVBITE_API WindowProperties {

	public:
		const std::string m_title;
		const unsigned int m_initialWidth;
		const unsigned int m_initialHeight;
		const unsigned int m_swapInterval;

		WindowProperties(const std::string& title = "Ravbite Engine", unsigned int width = 1200, unsigned int height = 700, unsigned int swapInterval = 1) : m_title(title), m_initialWidth(width), m_initialHeight(height), m_swapInterval(swapInterval) {}

	};

	class RAVBITE_API Window
	{

	public:
		static Window* create(const WindowProperties& properties = WindowProperties());

	public:
		virtual ~Window() {}

		virtual void update() = 0;

		virtual EventHandler& getEventHandler() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual void getSize(int* width, int* height) const = 0;

		virtual unsigned int getSwapInterval() const = 0;
		virtual void setSwapInterval(unsigned int interval) = 0;

		virtual const std::string& getTitle() const = 0;
		virtual void setTitle(std::string&& title) = 0;

	protected:

	};

}