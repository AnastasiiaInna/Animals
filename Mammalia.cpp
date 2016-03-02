#include "Mammalia.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Mammalia::Mammalia():Animal(){};

Mammalia::Mammalia(string name):Animal(name){};	

Mammalia::Mammalia(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length,
				   bool isIll, disease dis) : 
	Animal(name, sex, age, color, weight, size, speed_walk){
		_horns_length =  horns_length;
		_who = "mammalia";
};

void Mammalia::showList()
{
	Animal::showList();
	cout<<" - Horn length: "<<_horns_length<<" cm"<<endl;
}

void Mammalia::eat(vector<Animal*>&animalList)
{	
	Animal::eat(animalList);
}