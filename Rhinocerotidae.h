#ifndef RHINOSEROTIDAE_H
#define RHINOSEROTIDAE_H
#include "Mammalia.h"

//непарнокопытные
class Rhinocerotidae:public Mammalia
{
private:
	void speak();
	void generate(vector<Animal*>&animalList);
	//void eat(vector<Animal*>&animalList);	

public:
	Rhinocerotidae();
	Rhinocerotidae(string name);	
	Rhinocerotidae(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length, 
		bool isIll = false, disease dis = no);
	~Rhinocerotidae(){};

	void showList();
};

#endif