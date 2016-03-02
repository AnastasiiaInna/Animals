#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>

using namespace std;

class Animal
{
private:
	bool found(string name);

protected:
	enum disease
	{
		newVirus,
		rabies,//бешенство
		influenza,
		cancer,
		foot_and_mouth,//ящур
		no
	};
		
	virtual void eat(vector<Animal*>&animalList);// Animal* animal = new Animal());		
	virtual void speak();
	virtual void generate(vector<Animal*>&animalList);
	void die(vector<Animal*>&animalList);
	void sleep();
	void ill();

public:
	string _name;
	string _sex;
	int _age;
	string _color;
	float _weight;
	float _size;
	float _speed_walk;
	string _who;
	bool _isIll;
	disease _disease;

	string strToFile;

	Animal();
	Animal(string name);
	Animal(string name, string sex, int age, string color, float weight, float size, float speed_walk, bool isIll = false, disease dis = no);
	~Animal();

	string getName();
	string getKind();
	virtual void showList();	

	virtual void live(vector<Animal*>&animalList, string& str);
	
	/*static vector<Animal*>*animals;
	static void *live_thread(void* animalList);
	static void _live(vector<Animal*>&);*/

	friend ostream& operator<<(ostream& os, const Animal& animal);
	friend bool operator==(const Animal& animal_l, const Animal& animal_r);
};

#endif