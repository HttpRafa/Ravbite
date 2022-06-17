#include <Ravbite.h>

class SandBox : public Ravbite::Application
{

public:
	SandBox() {

	}

private:


};

Ravbite::Application* Ravbite::createApplication()
{
	return new SandBox();
}