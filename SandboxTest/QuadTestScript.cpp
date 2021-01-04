#include "Mob_Engine/IScript.h"

#include <iostream>

class QuadTestScript : public IScript {

public:
	QuadTestScript(std::string& name) : IScript(name)  {

	}

	~QuadTestScript() override{

	}


	void Start() override {

	}

	void FrameUpdate() override {

	}

	void OnCollision(std::string& name1, std::string& name2) override {
		std::cout << "Collision Detected!" << std::endl;
	}

};