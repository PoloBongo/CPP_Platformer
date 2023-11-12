#pragma once
#include "Component.h"
#include "Scene.h"
#include "SceneManager.h"

class Atout : public Component
{
public:
	Atout();
	
	void CreateAtout();
	void RandAtout();
	


private:

	std::vector<int> atouts = {5, 10, 15};
	int random_atout;
};

