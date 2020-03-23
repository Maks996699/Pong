#ifndef Stick_h
#define Stick_h

#include "GameObject.h"

class Stick : public GameObject
{

public:
	Stick(const char* texturesheet, int x, int y, int speed);
	~Stick();

	void moveUP();
	void moveDown();


private:
	int speed;

};

#endif