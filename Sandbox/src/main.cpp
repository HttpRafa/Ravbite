#include <Ravbite.h>

class SandBox : public Ravbite::Application
{

public:


private:


};

Ravbite::Application* Ravbite::createApplication()
{
	return new SandBox();
}