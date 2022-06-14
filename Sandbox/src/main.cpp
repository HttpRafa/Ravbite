#include <Ravbite.h>

class Sandbox : public Ravbite::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Ravbite::Application* Ravbite::createApplication() {
	return new Sandbox();
}