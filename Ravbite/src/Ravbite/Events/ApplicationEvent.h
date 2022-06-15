#pragma once

#include <sstream>

#include "Event.h"

namespace Ravbite {

	// Close
	class RAVBITE_API WindowCloseEvent : public Event {

	public:
		EVENT_TYPE(WindowClose)
		EVENT_CATEGORY(Application)

	};

	// Resize
	class RAVBITE_API WindowResizeEvent : public Event {

	private:
		unsigned int m_width, m_height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		inline unsigned int getWidth() const { return m_width; }
		inline unsigned int getHeight() const { return m_height; }

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_width << ", " << m_height;
			return stringStream.str();
		}

		EVENT_TYPE(WindowResize)
		EVENT_CATEGORY(Application)

	};

}
