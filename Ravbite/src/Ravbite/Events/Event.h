#pragma once

#include <string>
#include <iostream>
#include <functional>

#include "Ravbite/Core.h"

namespace Ravbite {

	class RAVBITE_API Event {

	public:
		enum EventType {
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			KeyPressed, KeyReleased,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		enum EventCategory {
			Application = BIT(0),
			Input =       BIT(1),
			Keyboard =    BIT(2),
			Mouse =       BIT(3),
			MouseButton = BIT(4)
		};

	protected:
		bool m_handled = false;

	public:
		virtual EventType getType() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual const char* getName() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}

	};

	class EventDispatcher {

	private:
		Event& m_event;

	public:
		template<typename T>
		using EventFunction = std::function<bool(T&)>;

		EventDispatcher(Event& event) : m_event(event) {}

		template<typename T>
		bool dispatch(EventFunction<T> function) {
			if (m_event.getType() == T::getStaticType()) {
				m_event.m_handled = function(*((T*)&m_event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& ostream, const Event& event) {
		return ostream << event.toString();
	}

}

#define EVENT_TYPE(type) static EventType getStaticType() { return Event::EventType::##type; }\
							virtual EventType getType() const override { return getStaticType(); }\
							virtual const char* getName() const override { return #type; }
#define EVENT_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

