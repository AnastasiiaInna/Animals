#include "Artiodactyla.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Artiodactyla::Artiodactyla():Mammalia(){};

Artiodactyla::Artiodactyla(string name):Mammalia(name){};	

Artiodactyla::Artiodactyla(string name, string sex, int age, string color, float weight, float size, float speed_walk, float horns_length, 
						   int numberOfhorns, bool isIll, disease dis) : 
	Mammalia(name, sex, age, color, weight, size, speed_walk, horns_length){
		_numberOfhorns =  numberOfhorns;
		_who = "artiodactyla";
};

void Artiodactyla::showList()
{
	Mammalia::showList();
	cout<<" - Number of horns: "<<_numberOfhorns<<endl;
}

void Artiodactyla::speak()
{
	strToFile = _name + ": brrrrr brr brrrb rr brr \n";
	cout<<strToFile;
}

void Artiodactyla::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Artiodactyla(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, rand() % 10+10, true, _disease)); 
	else animalList.push_back(new Artiodactyla(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,  rand() % 10+10, rand() % 10+10)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}