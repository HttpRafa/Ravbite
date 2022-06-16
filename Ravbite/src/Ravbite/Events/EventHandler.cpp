#include "rbpch.h"
#include "EventHandler.h"

namespace Ravbite {

	void EventHandler::fire(Event& event)
	{
		for (auto& callback : m_callbacks)
		{
			event.m_handled = callback(event);
		}
	}

	void EventHandler::subscribe(const std::function<bool(Event&)>& function) {
		m_callbacks.push_back(function);
	}

}