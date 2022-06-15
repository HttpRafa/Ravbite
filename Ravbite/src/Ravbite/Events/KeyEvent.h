#pragma once

#include <sstream>

#include "Event.h"

namespace Ravbite {

	class RAVBITE_API KeyEvent : public Event {

	protected:
		KeyEvent(int keyCode) : m_keyCode(keyCode) {}

		int m_keyCode;

	public:
		inline int getKeyCode() const {
			return m_keyCode;
		}

		EVENT_CATEGORY(Keyboard | Input)

	};

	class RAVBITE_API KeyPressedEvent : public KeyEvent {

	private:
		int m_repeatCount;

	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		inline int getRepeatCount() const {
			return m_repeatCount;
		}

		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_keyCode << " [" << m_repeatCount << "]";
			return stringStream.str();
		}

		EVENT_TYPE(KeyPressed)

	};

	class RAVBITE_API KeyReleasedEvent : public KeyEvent {

	public:
		std::string toString() const override {
			std::stringstream stringStream;
			stringStream << getName() << " - " << m_keyCode;
			return stringStream.str();
		}

		EVENT_TYPE(KeyReleased)

	};

}