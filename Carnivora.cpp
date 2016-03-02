#include "Carnivora.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Carnivora::Carnivora():Mammalia(){};

Carnivora::Carnivora(string name):Mammalia(name){};	

Carnivora::Carnivora(string name, string sex, int age, string color, float weight, float size, float speed_walk, float mane_length, 
					 float canines_size, bool isIll, disease dis) : 
	Mammalia(name, sex, age, color, weight, size, speed_walk){
		_mane_length =  mane_length;
		_canines_size = canines_size;
		_who = "carnivora";
};

void Carnivora::showList()
{
	Animal::showList();
	cout<<" - Mane length: "<<_mane_length<<" cm"
		<<"\n - Canines size: "<<_canines_size<<" cm"<<endl;
}

void Carnivora::speak()
{
	strToFile = _name + ": aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \n";
	cout<<strToFile;
}

void Carnivora::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red", "green", "yellow"};
	if (_isIll)
		animalList.push_back(new Carnivora(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10, rand() % 10+10, rand() % 20 + 5, true, _disease)); 
	else animalList.push_back(new Carnivora(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 7], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,  rand() % 10+10, rand() % 20 + 5)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}

void Carnivora::eat(vector<Animal*>&animalList)
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

void Carnivora::hunt()
{
	strToFile = _name + "is hunting \n";
	cout<<strToFile;
}

void Carnivora::live(vector<Animal*>&animalList, string& str)
{
	srand(time(NULL));
	int action = rand() % 6 + 1;
	switch (action)
	{
	case 1://speak
	{
		this->speak();
		_sleep(500);
		break;
	}
	case 2://sleep
	{
		this->sleep();
		_sleep(500);
		break;
	}
	case 3://eat
	{
		eat(animalList);
		_sleep(500);
		break;
	}
	case 4://die
		{
			this->die(animalList);
			_sleep(500);
			break;
		}
	case 5://generation
		{
			this->generate(animalList);
			_sleep(500);
			break;
		}
	case 6://ill
		{
			this->ill();
			_sleep(500);
			break;
		}
	case 7:
		{
			this->hunt();
			_sleep(500);
			break;
		}
	default:
		break;
	}
	str = strToFile;
}