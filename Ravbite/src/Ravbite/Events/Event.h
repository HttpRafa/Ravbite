#pragma once

#include "Ravbite/Core.h"
#include "Ravbite/Log.h"

namespace Ravbite {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		CategoryApplication = BIT(0),
		CategoryInput = BIT(1),
		CategoryKeyboard = BIT(2),
		CategoryMouse = BIT(3),
		CategoryMouseButton = BIT(4)
	};

	class RAVBITE_API Event
	{
		friend class EventHandler;

	public:
		inline bool is(EventType type)
		{
			return getType() == type;
		}

		inline bool isIn(EventCategory category)
		{
			return getCategories() & category;
		}

		virtual EventType getType() const = 0;
		virtual int getCategories() const = 0;

		// Debugging
		virtual const char* getName() const = 0;
		virtual std::string toString() const {
			return getName(); 
		}

	protected:
		bool m_handled = false;

	};

	// Adds support for the logger to print a event
	inline std::ostream& operator<<(std::ostream& stream, const Event& handledEvent)
	{
		return stream << handledEvent.toString();
	}

	#define EVENT_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
							 virtual EventType getType() const override { return getStaticType(); }\
							 virtual const char* getName() const override { return #type; }

	#define EVENT_CATEGORY(category) virtual int getCategories() const override { return category; }

}