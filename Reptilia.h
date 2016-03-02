#ifndef REPTILIA_H
#define REPTILIA_H
#include "Animal.h"

//пресмыкающиеся
class Reptilia:public Animal
{
protected:
	float _speed_swim;
public:
	Reptilia();
	Reptilia(string name);	
	Reptilia(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim, 
		bool isIll = false, disease dis = no);
	~Reptilia(){};

	virtual void showList();
	//virtual void live(vector<Animal*>&){};	
	virtual void live(){};	
};

#endif