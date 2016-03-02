#include <fstream>
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <conio.h>
#include <vector>
#include <memory>
#include "Animal.h"
#include "Artiodactyla.h"
#include "Aves.h"
#include "Carnivora.h"
#include "Crocodiles.h"
#include "Mammalia.h"
#include "Ciconiiformes.h"
#include "Psittaciformes.h"
#include "Reptilia.h"
#include "Rhinocerotidae.h"
#include "Snakes.h"

//typedef std::shared_ptr<Animal> AnimalPtr;
//typedef std::vector<AnimalPtr> AnimalCollection;
//
//AnimalCollection zoo;
//
//void addAnimal(AnimalPtr animal)
//{
//	zoo.push_back(animal);
//}

char menu(string action)
{
	char kind, form;				
				cout<<"What kind of animals do you want to "<<action<<":\n"
					<<" - R - Reptilias\n"
					<<" - M - Mammalias\n"
					<<" - A - Aves\n"
					<<" - N - New animal\n"
					<<" - 0 - back\n";
				cin>>kind;
				switch(kind)
				{					
				case 'r':
					{
					cout<<"What kind of reptilias do you want to "<<action<<":\n"
						<<" - C - Crocodiles\n"
						<<" - S - Snakes\n";
					cin>>form;
					break;
					}
				case 'm':
					{
					cout<<"What kind of mammalias do you want to "<<action<<":\n"
						<<" - A - Artiodactyla\n"
						<<" - V - Carnivora\n";
					cin>>form;
					break;
					}
				case 'a':
					{
					cout<<"What kind of aves do you want to "<<action<<":\n"
						<<" - I - Ciconiiformes\n"
						<<" - P - Psittaciformes\n";
					cin>>form;
					break;
					}
				case 'n':
					{
						form = 'n';
						break;
					}
				case '0':
					//exit(0);					
					form = '0';
					break;
				default:
					break;
				}	
				return form;
}

int main()
{
	char variant = -1;
	char form = NULL;
	vector<Animal*> animalList;
	while(variant)
	{
		cout<<"\n  Menu:\n"
			<<"  - 1 - Add animal\n"
			<<"  - 2 - Remove animal\n"
			<<"  - 3 - Show list\n"
			<<"  - 4 - Zapis\n"
			<<"  - 5 - Statistics\n"
			<<"  - 6 - Open from file\n"
			<<"  - 7 - Live\n"
			<<"  - 0 - Exit\n";
		cin>>variant;

		switch (variant)
		{ 
		case '0':exit(0) ; break;
		case '1':
			{
				form = menu("add");
				if(form == '0') break;
				string name, color, sex;
				int age = 0;
				float weight = 0.0, size = 0.0;	
				float speed_walk = 0.0;
				bool isPoisoned = false;
				
				while(name.length() < 2)
				{
					cout<<"Enter name:\n";
					cin>>name;
				}
				while(sex != "M" && sex !="F" && sex !="m" && sex !="f")
				{
					cout<<"\nEnter sex (M or F):\n";
					cin>>sex;
				}
				cout<<"\nEnter age (months):\n";
				cin>>age;
				cout<<"\nEnter color:\n";
				cin>>color;
				cout<<"\nEnter weight (kg):\n";
				cin>>weight;
				cout<<"\nEnter size (m):\n";
				cin>>size;
				cout<<"\nEnter speed_walk (km/h):\n";
				cin>>speed_walk;

				switch (form)
				{
				case'c':
					{
						float tail_size = 0.0, speed_swim = 0.0;
						cout<<"\nEnter tail size (m):\n";
						cin>>tail_size;
						cout<<"\nEnter speed in the water (km/h):\n";
						cin>>speed_swim;						
 					    animalList.push_back(new Crocodiles(name, sex, age, color, weight, size, speed_walk, tail_size, speed_swim));
						break;
					}
				case 's':
					{
						float tail_size = 0.0;
						cout<<"\nEnter tail size (m):\n";
						cin>>tail_size;
						cout<<"\nEnter if the snake is poisoned (T/F):\n";
						cin>>isPoisoned;
						animalList.push_back(new Snakes(name, sex, age, color, weight, size, speed_walk, tail_size, isPoisoned));
						break;
					}
				default:
					break;
				}
				break;
			}
		case '2':
			{	
				if (animalList.empty()){
					cout<<"\nNo animall exists\n";
					break;
				}
				vector<Animal*>::const_iterator it = animalList.begin();
				string name;
				bool found = false;
				cout<<"Enter name to remove animal:\n";
				cin>>name;
				while( it != animalList.end() ){
					if((*it)->getName() == name){									
						it = animalList.erase(it); 	
						found = true;
					}
					else it++;
				}
				if (!found) cout<<"There is no such animal\n";
				break;
			}
		case '3':
			{
				if (animalList.empty()){
					cout<<"\nNo animal exists\n";
					break;
				}
				int j = 1;
				for(vector<Animal*>::const_iterator it = animalList.begin(); it != animalList.end(); it++){
					cout<<endl<<j<<". ";
					(*it)->showList();
					++j;
				}
				break;
			}
		case '4':
			{
				ofstream file;
				string strToFile;
				vector<Animal*>::iterator it = animalList.begin();
				file.open("D:/animals.txt");
				srand(time(NULL));
					if(!animalList.empty())
					{
						while(it != animalList.end())
						{
							strToFile = (*it)->_who + "\n"+
							(*it)->_name + "\t" + (*it)->_sex+ "\t" + to_string((*it)->_age)+ "\t" + (*it)->_color + "\t" + to_string((*it)->_weight)+
							"\t" + to_string((*it)->_size) + to_string((*it)->_speed_walk)+"\t\n\t";
							++it;
							file<<strToFile;
						}						
					}
				break;
			}
		case '5':
			{
				if(animalList.empty())
					cout<<"No animal exists.\n";
				else
				{
					vector<Animal*> temp_animal = animalList;
					int counter = 1;
					int total = 0;
					vector<Animal*>::iterator it = temp_animal.begin(), i = it + 1;
					while(!temp_animal.empty())	
					{
						while( i != temp_animal.end() ){
							if((*it)->_who == (*i)->_who){
								counter++;
								i = temp_animal.erase(i); 	
							}
							else i++;
						}
				
						cout<<"Amount of "<<(*it)->_who<<"s: "<<counter<<endl;
						total += counter;
						it = temp_animal.erase(it);
						if (! temp_animal.empty()){
							counter = 1;							
							it = temp_animal.begin(); i = it + 1;
						} else break;
					}
					cout<<"________________________________\n"
					<<"Total: "<<total<<endl;
				}
				break;
			}
		case '6':
			{
				const int n = 15;
				string line[n], kind;												
				ifstream file;//("D:/animal.txt");
				file.exceptions ( ifstream::failbit | ifstream::badbit );
				try
				//if(file.is_open())
				{		
					file.open("D:/animals.txt");
					while(!file.eof())
					{
						getline(file, kind, '\n');
						for(int i=0; ; ++i)
						{
							getline(file, line[i], '\t');
							if(line[i] == "\n")
								break;
						}
						if (kind == "animal"){
							animalList.push_back(new Animal(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str())));
							/*addAnimal(AnimalPtr(new Animal(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()))));*/
							
						}
						
						else if (kind == "artiodactyla")
							animalList.push_back(new Artiodactyla(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str())));
						else if (kind == "ave")
							animalList.push_back(new Aves(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str())));
						else if (kind == "carnivora")
							animalList.push_back(new Carnivora(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str())));
						else if (kind == "ciconiiforme")
							animalList.push_back(new Ciconiiformes(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str()),
															atof(line[9].c_str()), atof(line[10].c_str())));
						else if (kind == "crocodile"){
							animalList.push_back(new Crocodiles(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str())));
							/*addAnimal(AnimalPtr(new Crocodiles(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str()))));
							*/
						}
						else if (kind == "mammalia")
							animalList.push_back(new Mammalia(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str())));
						else if (kind == "psittaciforme")
							animalList.push_back(new Psittaciformes(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), atof(line[8].c_str())));
						else if (kind == "reptilia")
							animalList.push_back(new Reptilia(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str())));
						else if (kind == "rhinocerotidae")
							animalList.push_back(new Rhinocerotidae(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str())));
						else if (kind == "snake")
							animalList.push_back(new Snakes(line[0], line[1], atoi(line[2].c_str()),line[3], atof(line[4].c_str()),
															atof(line[5].c_str()),atof(line[6].c_str()), atof(line[7].c_str()), (bool)(line[8].c_str())));
					}
					cout<<"Animals were added\n";
				}
				//else cout<<"Wrong directory\n";
				catch (ifstream::failure e)
				{
					cout<<"Exception opening file\n";
				};
				file.close();
				break;
			}
		case '7':
			{
				//pthread_t threads[5];  
				//Animal::_live(animalList);
				//for (int i = 0; i < 5; i++)
				//{
				//	pthread_create(&threads[i], NULL, Animal::live_thread,(void*)&animalList);//(void*)animalList.at(i));
				//	_sleep(500);
				//}
				//
				ofstream file;
				string strToFile;
				file.open("D:/simulation.txt");
				srand(time(NULL));
				while(!kbhit())				
				{
					if(!animalList.empty())
					//try
					{
						int i = rand() % animalList.size() + 0;		
						animalList.at(i)->live(animalList, strToFile);	
					
						if (file.fail())
						{
							cout<<"\nOpening is failed\n";
							exit(1);
						}					
						file<<strToFile;
					}
					else{
						cout<<"\nOoops...all animals died or have been eaten\n";
						strToFile = "All animals died or have been eaten\n";
						file<<strToFile;
						break;
					}
					//catch(exception& e){e.what();}
				}
				file.close();
				break;
			}
		default:
			cout<<"Wrong sign\n";
			break;
		}
	}	
	return 0;
}