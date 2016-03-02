#ifndef MAMMALIA_H
#define MAMMALIA_H
#include "Animal.h"

//млекопитающие
class Mammalia:public Animal
{
protected:	
	float _horns_length;
	
	virtual void eat(vector<Animal*>&animalList);	

public:
	Mammalia();
	Mammalia(string name);	
	Mammalia(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length = 0,
		bool isIll = false, disease dis = no);
	~Mammalia(){};

	virtual void showList();
};

#endif