#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Ravbite::Application* Ravbite::createApplication();

int main(int argc, char** argv) {

	Ravbite::Application* application = Ravbite::createApplication();
	application->run();

	delete application;

}

#endif