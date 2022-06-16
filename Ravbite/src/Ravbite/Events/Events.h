#pragma once

#include <sstream>

#include "Event.h"

namespace Ravbite {

	// Window events
	class RAVBITE_API WindowClose : public Event
	{

	public:
		WindowClose()
		{

		}

		EVENT_TYPE(WindowClose)
		EVENT_CATEGORY(CategoryApplication)

	};

	class RAVBITE_API WindowResize : public Event
	{

	public:
		WindowResize(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		inline unsigned int getWidth() {
			return m_width; 
		}

		inline unsigned int getHeight() {
			return m_height; 
		}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_width << ", " << m_height << "]";
			return stream.str();
		}

		EVENT_TYPE(WindowResize)
		EVENT_CATEGORY(CategoryApplication)

	private:
		unsigned int m_width, m_height;

	};

	// Key events
	class RAVBITE_API KeyEvent : public Event
	{

	public:
		inline int getKeyCode() const {
			return m_keyCode;
		}

		EVENT_CATEGORY(CategoryKeyboard | CategoryInput)
	protected:
		KeyEvent(int keyCode) : m_keyCode(keyCode) {}

		int m_keyCode;

	};

	class RAVBITE_API KeyPressedEvent : public KeyEvent
	{

	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		inline int getRepeatCount() const
		{
			return m_repeatCount;
		}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_keyCode << ", " << m_repeatCount << "]";
			return stream.str();
		}

		EVENT_TYPE(KeyPressed)

	protected:
		int m_repeatCount;

	};

	class RAVBITE_API KeyReleasedEvent : public KeyEvent
	{

	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_keyCode << "]";
			return stream.str();
		}

		EVENT_TYPE(KeyReleased)

	};

	// Mouse events
	class RAVBITE_API MouseMovedEvent : public Event
	{

	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		inline float getX() const
		{
			return m_mouseX;
		}

		inline float getY() const
		{
			return m_mouseY;
		}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_mouseX << ", " << m_mouseY << "]";
			return stream.str();
		}

		EVENT_TYPE(MouseMoved)
		EVENT_CATEGORY(CategoryMouse | CategoryInput)

	private:
		float m_mouseX, m_mouseY;

	};

	class RAVBITE_API MouseScrolledEvent : public Event
	{

	public:
		MouseScrolledEvent(float x, float y) : m_offsetX(x), m_offsetY(y) {}

		inline float getOffsetX() const
		{
			return m_offsetX;
		}

		inline float getOffsetY() const
		{
			return m_offsetY;
		}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_offsetX << ", " << m_offsetY << "]";
			return stream.str();
		}

		EVENT_TYPE(MouseScrolled)
		EVENT_CATEGORY(CategoryMouse | CategoryInput)

	private:
		float m_offsetX, m_offsetY;

	};

	class RAVBITE_API MouseButtonEvent : public Event
	{

	public:
		inline int getButton() const
		{
			return m_button;
		}

		EVENT_CATEGORY(CategoryMouse | CategoryInput)

	protected:
		MouseButtonEvent(int button) : m_button(button) {}

		int m_button;

	};
	
	class RAVBITE_API MouseButtonPressedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_button << "]";
			return stream.str();
		}

		EVENT_TYPE(MouseButtonPressed)

	};

	class RAVBITE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{

	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream stream;
			stream << getName() << "[" << m_button << "]";
			return stream.str();
		}

		EVENT_TYPE(MouseButtonReleased)

	};
	
}