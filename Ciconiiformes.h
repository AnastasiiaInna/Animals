#ifndef CICONIIFORMES_H
#define CICONIIFORMES_H
#include "Aves.h"

//аистообразные
class Ciconiiformes:public Aves
{
private:	
	float _beak_size;//размер клюва
	float _legs_length;

	void speak();
	void generate(vector<Animal*>&animalList);
public:
	Ciconiiformes();
	Ciconiiformes(string name);	
	Ciconiiformes(string name, string sex, int age, string color, int weight, float size, float speed, float wing_size, float wingspan,
		float beak_size, float legs_length, bool isIll = false, disease dis = no);
	~Ciconiiformes(){};

	virtual void showList();
};

#endif