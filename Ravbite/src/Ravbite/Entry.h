#pragma once

#include "Ravbite.h"

extern Ravbite::Application* Ravbite::createApplication();

int main()
{
	// Init loggingService
	Ravbite::Log::init();

	RB_CORE_INFO("Ravbite engine");
	RB_CORE_INFO("v0.0.0");

	// Creating application
	Ravbite::Application* application = Ravbite::createApplication();

	// Running application
	application->run();

	// Stopping application
	delete application;

}
