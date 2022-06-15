#pragma once

#include <sstream>

#include "Event.h"

namespace Ravbite {

	class RAVBITE_API MouseMovedEvent : public Event {

	private:
		float m_mouseX, m_mouseY;

	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		inline float getX() const {
			return m_mouseX;
		}

		inline float getY() const {
			return m_mouseY;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_mouseX << ", " << m_mouseY;
			return stringStream.str();
		}

		EVENT_TYPE(MouseMoved)
		EVENT_CATEGORY(Mouse | Input)

	};

	class RAVBITE_API MouseScrolledEvent : public Event {

	private:
		float m_offsetX, m_offsetY;

	public:
		MouseScrolledEvent(float x, float y) : m_offsetX(x), m_offsetY(y) {}

		inline float getOffsetX() const {
			return m_offsetX;
		}

		inline float getOffsetY() const {
			return m_offsetY;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_offsetX << ", " << m_offsetY;
			return stringStream.str();
		}

		EVENT_TYPE(MouseMoved)
		EVENT_CATEGORY(Mouse | Input)

	};

	class RAVBITE_API MouseButtonEvent : public Event {

	protected:
		int m_button;

		MouseButtonEvent(int button) : m_button(button) {}

	public:
		inline int getButton() const { 
			return m_button;
		}

		EVENT_CATEGORY(Mouse | Input)

	};

	class RAVBITE_API MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_button;
			return stringStream.str();
		}

		EVENT_TYPE(MouseButtonPressed)

	};

	class RAVBITE_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_button;
			return stringStream.str();
		}

		EVENT_TYPE(MouseButtonReleased)

	};

}