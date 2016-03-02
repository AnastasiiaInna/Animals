#include "Ciconiiformes.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Ciconiiformes::Ciconiiformes():Aves(){};

Ciconiiformes::Ciconiiformes(string name):Aves(name){};	

Ciconiiformes::Ciconiiformes(string name, string sex, int age, string color, int weight, float size, float speed, float wing_size, float wingspan,
							 float beak_size, float legs_length, bool isIll, disease dis) : 
	Aves(name, sex, age, color, weight, size, speed, wing_size, wingspan){
		_beak_size = beak_size;
		_legs_length = legs_length;
		_who = "ciconiiformes";
	};

void Ciconiiformes::showList()
{
	Aves::showList();
	cout<<" - Beak size: " <<_beak_size<<" cm"
		<<" - Leg length: "<<_legs_length<<" cm"<<endl;
}

void Ciconiiformes::speak()
{
	strToFile = _name + "is not singing but do smth\n";
	cout<<strToFile;
}

void Ciconiiformes::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Ciconiiformes(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0, color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 5+1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, true, _disease)); 
	else animalList.push_back(new Ciconiiformes(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0, color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 5+1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}