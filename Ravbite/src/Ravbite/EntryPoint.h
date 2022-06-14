#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Ravbite::Application* Ravbite::createApplication();

int main(int argc, char** argv) {

	Ravbite::Log::init();
	RB_CORE_WARN("Initialized logging service!");

	Ravbite::Application* application = Ravbite::createApplication();
	application->run();

	delete application;

}

#endif