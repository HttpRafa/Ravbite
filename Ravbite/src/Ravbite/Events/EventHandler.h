#pragma once

#include <vector>
#include <functional>

#include "Ravbite/Core.h"
#include "Event.h"

namespace Ravbite {

	class RAVBITE_API EventHandler
	{

	public:
		void fire(Event& event);

		void subscribe(const std::function<bool(Event&)>& function);

		template<typename T>
		void typeSub(std::function<bool(T&)> func)
		{
			std::function<bool(Event&)> function = [=](Event& a_event)
			{
				if (a_event.getType() == T::getStaticType())
				{
					return func(*(T*)&a_event);
				}
				return false;
			};
			m_callbacks.push_back(function);
		}

	private:
		std::vector<std::function<bool(Event&)>> m_callbacks;

	};

}

