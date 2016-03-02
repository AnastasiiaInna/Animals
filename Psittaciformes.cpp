#include "Psittaciformes.h"

Psittaciformes::Psittaciformes():Aves(){};

Psittaciformes::Psittaciformes(string name):Aves(name){};	

Psittaciformes::Psittaciformes(string name, string sex, int age, string color, int weight, float size, float speed, float wing_size, 
							   float wingspan, bool isIll, disease dis) : 
	Aves(name, sex, age, color, weight, size, speed, wing_size, wingspan){_who = "psittaciformes";};

void Psittaciformes::showList()
{
	Aves::showList();
}

void Psittaciformes::speak()
{
	strToFile = _name + "is singing \n";
	cout<<strToFile;
}

void Psittaciformes::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Psittaciformes(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 5+1, rand() % 5 + 1, true, _disease)); 
	else animalList.push_back(new Psittaciformes(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,  rand() % 5+1, rand() % 5 + 1)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}

