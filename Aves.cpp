#include "Aves.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Aves::Aves():Animal(){};

Aves::Aves(string name):Animal(name){};	

Aves::Aves(string name, string sex, int age, string color, float weight, float size, float speed, float wing_size, float wingspan, 
		   bool isIll, disease dis) : 
	Animal(name, sex, age, color, weight, size, speed){
		_wing_size =  wing_size;
		_wingspan = wingspan;
		_who = "aves";
};

void Aves::showList()
{
	Animal::showList();
	cout<<" - Wing size: "<<_wing_size<<" cm"
		<<"\n - Wingspan: "<<_wingspan<<" cm"<<endl;
}

void Aves::eat(vector<Animal*>&animalList)
{	
	srand(time(NULL));
	Animal* animal = new Animal();
	while(animal->_who != "snake" && _weight < animal->_weight /2)
		animal = animalList.at(rand() % animalList.size());
	if (animal->_isIll && !this->_isIll)
	{
		_isIll = true;
		_disease = animal->_disease;
		strToFile = _name + " has eaten " + animal->_name + " and become ill with " + choose_disease[disease(_disease)] + "\n" +
				_name + "`s weight is " + to_string(_weight) + "kg\n";
	}
	else strToFile = _name + " has eaten " + animal->_name + "\n" +	_name + "`s weight is " + to_string(_weight) + "kg\n";
	
	vector<Animal*>::const_iterator it = animalList.begin();		
	while( it != animalList.end() ){
		if((*it) == animal)	{	
			_weight += ((*it)->_weight /2);
			it = animalList.erase(it); 	
			break;
		}
		else it++;
	}	
	cout<<strToFile;
}