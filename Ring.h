#ifndef RING_H
#define RING_H

#include <iostream>
#include <math.h>
using namespace std;

template<typename Key, typename Info>
class Ring
{	
private:
	struct Element
	{
		Element* prev;
		Element* next;
		Key key;
		Info info;
	};
	Element* head;

public:
	class Iterator;

	Ring<Key, Info>();
	Ring(const Ring<Key, Info>& ring);
	~Ring();

	void push_back(const Key& newKey, const Info& newInfo);
	void push_front(const Key& newKey, const Info& newInfo);
	void insert(Iterator& iterator,const Key& newKey, const Info& newInfo);
	
	bool pop_back();
	bool pop_front();
	bool remove(Iterator& iterator);
	void clear();
	bool isEmpty() const;

	void print() const;
	void print(const Key& existKey) const;
	
	Iterator find(const Key& existKey) const;	
	Iterator begin() const;
	Iterator end() const;

	int size() const;

	Info get(const Key& existKey) const;
	
	void sort();			
	
	void produce(const Ring<Key, Info>& ring_1, Key key_1, int length_1, 
				 const Ring<Key, Info>& ring_2, Key key_2, int length_2, 
				 int repeat, bool clockwise);

	const Ring<Key, Info>& operator= (const Ring<Key, Info>& ring);
	bool operator!=(const Ring<Key, Info>& ring) const;
	bool operator==(const Ring<Key, Info>& ring) const;
};
#endif