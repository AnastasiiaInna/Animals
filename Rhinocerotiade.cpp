#include "Rhinocerotidae.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Rhinocerotidae::Rhinocerotidae():Mammalia(){};

Rhinocerotidae::Rhinocerotidae(string name):Mammalia(name){};	

Rhinocerotidae::Rhinocerotidae(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length, 
							   bool isIll, disease dis) : 
	Mammalia(name, sex, age, color, weight, size, speed_walk){_who = "rhinoceritidae";};

void Rhinocerotidae::showList()
{
	Mammalia::showList();
}

void Rhinocerotidae::speak()
{
	strToFile = _name + ": brrrrr brr brrrb rr brr \n";
	cout<<strToFile;
}

void Rhinocerotidae::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Rhinocerotidae(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, true, _disease)); 
	else animalList.push_back(new Rhinocerotidae(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,  rand() % 10+10)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}
