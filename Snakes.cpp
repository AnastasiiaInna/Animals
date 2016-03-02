#include "Snakes.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Snakes::Snakes():Reptilia(){};

Snakes::Snakes(string name) : Reptilia(name){};	

Snakes::Snakes(string name, string sex, int age, string color, float weight, float size, float speed_walk, float speed_swim, 
			   bool isPoison, bool isIll, disease dis):
	Reptilia(name, sex, age, color, weight, size, speed_walk, speed_swim) {
		_isPoison = isPoison;
		_who = "snake";
};

void Snakes::showList()
{
	Reptilia::showList();
	cout<<" - isPoison: " << _isPoison<<endl;
}

void Snakes::speak()
{
	strToFile = _name + ": pszpszspszzs \n";
	cout<<strToFile;
}

void Snakes::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	bool poison = false;
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isPoison) poison = true;
	if (_isIll) 
		animalList.push_back(new Snakes(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0 ,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, poison, true, _disease)); 
	else animalList.push_back(new Snakes(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0 ,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, poison)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}

void Snakes::eat(vector<Animal*>&animalList)
{	
	if(_isPoison || _weight >= 300.0){
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
	}	
	else strToFile = _name + "is not poisoned and is eating smth\n";
	cout<<strToFile;
}



