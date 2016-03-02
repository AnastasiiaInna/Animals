#ifndef ARTIODACTYLA_H
#define ARTIODACTYLA_H
#include "Mammalia.h"

//парнокопытные
class Artiodactyla:public Mammalia
{
private:
	int _numberOfhorns;

	void speak();
	void generate(vector<Animal*>&animalList);
	//void eat(vector<Animal*>&animalList);	

public:
	Artiodactyla();
	Artiodactyla(string name);	
	Artiodactyla(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length, int numberOfhorns,
		bool isIll = false, disease dis = no);
	~Artiodactyla(){};

	void showList();
};

#endif