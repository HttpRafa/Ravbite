#pragma once

#include "Ravbite.h"

extern Ravbite::Application* Ravbite::createApplication();

int main()
{
	// Init loggingService
	Ravbite::Log::init();

	// Creating application
	Ravbite::Application* application = Ravbite::createApplication();

	// Running application
	application->run();

	// Stopping application
	delete application;

}
