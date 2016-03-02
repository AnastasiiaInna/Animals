#include "Reptilia.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Reptilia::Reptilia():Animal(){};

Reptilia::Reptilia(string name):Animal(name){};	

Reptilia::Reptilia(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim,
				   bool isIll, disease dis) : 
	Animal(name, sex, age, color, weight, size, speed_walk){
		_speed_swim = speed_swim;
		_who = "reptilia";
};

void Reptilia::showList()
{
	Animal::showList();
	cout<<" - Speed in the water: "<<_speed_swim<<" km/h"<<endl;
}
