#include <time.h>
#include <math.h>
#include <conio.h>

#include "Animal.h"

const string choose_disease[] ={"newVirus", "rabies", "influenza", "cancer", "foot_and_mouth"};

Animal::Animal():_name(), _sex(), _age(0), _color(), _weight(0){};

Animal::Animal(string name):_name(name){};

Animal::Animal(string name, string sex, int age, string color, float weight, float size, float speed_walk, bool isIll, disease dis):
	_name(name), _sex(sex), _age(age), _color(color), _weight(weight), _size(size), _speed_walk(speed_walk), _who("animal"), _isIll(isIll),
	_disease(dis){};

Animal::~Animal(){}

string Animal::getName()
{
	return this->_name;
}

string Animal::getKind()
{
	return this->_who;
}

void Animal::showList()
{
	cout<<_name
	<<"\n - Sex: "<<_sex
	<<"\n - Age: "<<_age<<" months"
	<<"\n - Color: "<<_color
	<<"\n - Weight: "<<_weight<<" kg"
	<<"\n - Size: "<<_size<<" m"
	<<"\n - Speed: "<<_speed_walk<<" km/h"<<endl;
}
//
//bool Animal::found(string name)
//{
//	for(list<Animal>::iterator it = animals.begin(); it != animals.end(); it++)
//			if(it->_name == name)
//				return true;
//	return false;
//}
//
//void Animal::statistics()
//{
//	if(animals.empty())
//		cout<<"No animal exists.\n";
//	else
//	{
//		list<Animal> temp_animal = animals;
//		int counter = 1;
//		int total = 0;
//		list<Animal>::iterator it = temp_animal.begin();
//		while(!temp_animal.empty())	
//		{
//			for(list<Animal>::iterator i = ++temp_animal.begin(); i != temp_animal.end(); )
//				if(it->_name == i->_name)
//				{
//					counter++;
//					temp_animal.erase(i++);
//				}
//				else i++;
//			cout<<"Amount of "<<it->_name<<"s: "<<counter<<endl;
//			total += counter;
//			counter = 1;
//			temp_animal.erase(it);
//			it = temp_animal.begin();
//		}
//		cout<<"________________________________\n"
//			<<"Total: "<<total<<endl;
//	}
//}
//

void Animal::eat(vector<Animal*>&animalList)
{	
	/*if (animal->_isIll && !this->_isIll)
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
		}*/
	strToFile = _name + " is eating \n";	
	cout<<strToFile;
}

void Animal::sleep()
{
	strToFile = _name + " is sleeping\n";
	cout<<strToFile;
}

void Animal::die(vector<Animal*>&animalList)
{	
	if(_isIll)
		strToFile = _name + " has died from " + choose_disease[disease(_disease)] +"\n";
	else strToFile = _name + ": I dont understand why I died\n" ;
	cout<<strToFile;
	
	vector<Animal*>::const_iterator it = animalList.begin();		
	while( it != animalList.end() ){
		if((*it) == this)	{	
			it = animalList.erase(it); 	
			break;
		}
		else it++;
	}
}

void Animal::speak()
{
	strToFile = _name + ": lalala la la lalala la la lalallalala aaaaaaaaaaaaaaaaaaaaaaaaaaa \n";
	cout<<strToFile;
}

void Animal::generate(vector<Animal*>&animalList)
{
	srand(time(NULL));
	string sex[] = {"M", "F"};
	string color[] = {"white", "black", "grey", "pink", "red"};
	if (_isIll)
		animalList.push_back(new Animal(_name + to_string(rand()%1 + 1), sex[rand() % 2], 0.0,color[rand() % 5], rand() % 100+100, rand() % 100+100,
			rand() % 10+10,true, _disease)); 
	else animalList.push_back(new Animal(_name + to_string(rand()%100 + 1), sex[rand() % 2], 0.0,color[rand() % 5], rand() % 100+100, rand() % 100+100,
			rand() % 10+10)); 

	strToFile = animalList.back()->_name + " was born \n";
	cout<<strToFile;
}

void Animal::ill()
{
	bool recover[] = {true, false};
	if (!_isIll)
	{
		_isIll = true;
		_disease = disease(rand() % 5);
		strToFile = _name + " become ill with " + choose_disease[disease(_disease)]+"\n";
	}
	else if (recover[rand()%2])
	{
		_isIll = false;
		_disease = no;
		strToFile = _name + " has recovered and now it `s absolutely healty\n";
	}
	else strToFile = _name + " continues to be ill with " + choose_disease[disease(_disease)]+"\n";
	
	cout<<strToFile;
}

void Animal::live(vector<Animal*>&animalList, string& str)
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
	default:
		break;
	}
	str = strToFile;
}
		
//void Animal::_live(vector<Animal*>&v)
//{
//	pthread_t threads[5];  
//	animals = &v;
//	for (int i = 0; i < animals->size() - 1; i++)
//				{
//					pthread_create(&threads[i], NULL, live_thread,(void*)animals->at(i));
//				}
//				pthread_exit(NULL);
//				
//}
//void *Animal::live_thread( void *animal)
//{	
//	Animal *_animal = (Animal*)animal;
//	if (_animal){
//		//_animal->live();
//		pthread_exit(NULL);}
//	else
//	pthread_exit(NULL);
//	return 0;
//}

ostream& operator<<(ostream& os, const Animal& animal)
{
	return os<<animal;
}

bool operator==(const Animal& animal_l, const Animal& animal_r)
{
	if(animal_l._name== animal_r._name)
		return true;
	else return false;
}
