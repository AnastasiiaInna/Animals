#ifndef CARNIVORA_H
#define CARNIVORA_H
#include "Mammalia.h"

//������
class Carnivora:public Mammalia
{
private:
	float _mane_length;//����� �����
	float _canines_size;//������ ������

	void speak();
	void generate(vector<Animal*>&animalList);
	void eat(vector<Animal*>&animalList);	
	void hunt();

public:
	Carnivora();
	Carnivora(string name);	
	Carnivora(string name, string sex, int age, string color, float weight, float size, float speed_walk, float mane_lenght, float canines_size,
		bool isIll = false, disease dis = no);
	~Carnivora(){};

	void showList();
	void live(vector<Animal*>&animalList, string& str);
};

#endif