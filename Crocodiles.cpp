#include "Crocodiles.h"
#include <conio.h>

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Crocodiles::Crocodiles():Reptilia(){};

Crocodiles::Crocodiles(string name) : Reptilia(name){};	

Crocodiles::Crocodiles(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim, float tail,
					   bool isIll, disease dis):
	Reptilia(name, sex, age, color, weight, size, speed_walk, speed_swim) {
		_tail_size = tail;
		_who = "crocodile";
};

void Crocodiles::showList()
{
	Reptilia::showList();
	cout<<" - Tail size: "<<_tail_size<<" m"<<endl;
}

void Crocodiles::speak()
{
	strToFile = _name + ": brrrrr brr brrrb rr brr \n";
	cout<<strToFile;
}

void Crocodiles::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Crocodiles(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, rand() % 20 + 5, true, _disease)); 
	else animalList.push_back(new Crocodiles(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,  rand() % 10+10, rand() % 20 + 5)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}

void Crocodiles::eat(vector<Animal*>&animalList)
{	
	srand(time(NULL));
	Animal* animal = animalList.at(rand() % animalList.size());
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
//void Crocodiles::live(vector<Animal*>&animalList, string& str)
//{
//	Animal::live(animalList, str);
//}

