#ifndef AVES_H
#define AVES_H
#include "Animal.h"

//птицы
class Aves:public Animal
{
private:	
	float _wing_size;
	float _wingspan;// размах крыла

	void eat(vector<Animal*>&animalList);	
public:
	Aves();
	Aves(string name);	
	Aves(string name, string sex, int age, string color, float weight, float size, float speed, float wing_size, float wingspan,
		bool isIll = false, disease dis = no);
	~Aves(){};

	virtual void showList();
};

#endif