#ifndef ITERATOR_H
#define ITERATOR_H

template<typename Info>
class Ring<Info>::Iterator
{
	Element* Ptr;
public:
	friend class Ring;

	Iterator() : Ptr(NULL){};
	Iterator(Element* ptr) : Ptr(ptr){};
	Iterator(const Iterator& iterator) : Ptr(NULL) { *this = iterator; }
	~Iterator() {this->Ptr = NULL;};

	const Iterator& operator=(const Iterator& iterator) 
	{
		Ptr = iterator.Ptr;
		return *this;
	}

	Iterator operator++()
	{
		Iterator curr(Ptr);
		Ptr = Ptr->next;
		return curr;
	}

	Iterator operator++(int)
	{
		Ptr = Ptr->next;
		return *this;
	}

	Iterator operator--()
	{
		Iterator curr(Ptr);
		Ptr = Ptr->prev;
		return curr;
	}

	Iterator operator--(int)
	{
		Ptr = Ptr->prev;
		return *this;
	}

	bool operator==(const Iterator& iterator) const
	{
		return (Ptr == iterator.Ptr);
	}

	bool operator!=(const Iterator& iterator) const
	{
		return (Ptr != iterator.Ptr);
	}

	Info& operator*(){return (Ptr->info);}; 
};
#endif