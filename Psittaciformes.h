#ifndef PSITTACIFORMES_H
#define PSITTACIFORMES_H
#include "Aves.h"

//попугообразные
class Psittaciformes:public Aves
{
private:	
	void speak();
	void generate(vector<Animal*>&animalList);

public:
	Psittaciformes();
	Psittaciformes(string name);	
	Psittaciformes(string name, string sex, int age, string color, int weight, float size, float speed, float wing_size, float wingspan, 
		bool isIll = false, disease dis = no);
	~Psittaciformes(){};

	void showList();
};

#endif
