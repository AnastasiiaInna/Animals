#ifndef SLL_H
#define SLL_H
#include <iostream>

using namespace std;

template <typename Info>
class Sequence{
private:
	struct element
	{
		element* next;
		Info info;
	};	
    element* head; 

public:
	Sequence<Info>():head(NULL){};
	Sequence(const Sequence<Info>& sequence);
    ~Sequence();
 	
    void push_front(const Info& newInfo);
	void push_back( const Info& info);	
	void insert( const Info& _where, const Info& newInfo);
	bool pop_front();
	bool pop_back();
	void print() const;
	void print(const Info& existInfo) const;
	bool find(const Info& existInfo) const;	
	bool isEmpty() const;
	bool remove(const Info& what);
	void remove_all();
	int numberOfElements() const;	
	Info elementAt(int index);	

	Sequence<Info>& operator=(const Sequence<Info>& sequence);
	Sequence<Info>& operator+(const Sequence<Info>& sequence);
	Sequence<Info>& operator+=(const Sequence<Info>& sequence);
	bool operator!=(const Sequence<Info>& sequence) const;
	bool operator==(const Sequence<Info>& sequence) const;
	friend ostream& operator<<(ostream& os, const Sequence<Info>& elementPtr);	
};

#endif