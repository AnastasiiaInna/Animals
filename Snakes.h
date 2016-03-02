#ifndef SNAKESS_H
#define SNAKESS_H
#include "Reptilia.h"

//млекопитающие
class Snakes:public Reptilia
{
private:
	bool _isPoison;

	void speak();
	void generate(vector<Animal*>&animalList);
	void eat(vector<Animal*>&animalList);	

public:
	Snakes();
	Snakes(string name);	
	Snakes(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim, bool isPoson,
		bool isIll = false, disease dis = no);
	~Snakes(){};

	void showList();

};

#endif