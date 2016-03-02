#ifndef CROCODILES_H
#define CROCODILES_H
#include "Reptilia.h"

class Crocodiles:public Reptilia
{
private:
	float _tail_size;

	void speak();
	void generate(vector<Animal*>&animalList);
	void eat(vector<Animal*>&animalList);	

public:
	Crocodiles();
	Crocodiles(string name);	
	Crocodiles(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim, float tail,
		bool isIll = false, disease dis = no);
	~Crocodiles(){};

	void showList();
//	void live(vector<Animal*>&animalList, string& str);

};

#endif