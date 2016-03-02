#pragma hdrstop

#include "SLL.h"
#include <string>
#include <math.h>

template <typename Info>
Sequence<Info>::Sequence(const Sequence<Info>& sequence)
{
    head = NULL;
    for( element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
        push_back( iterator->info );
}

template <typename Info>
Sequence<Info>::~Sequence()
{
	remove_all();
}

template <typename Info>
bool Sequence<Info>::isEmpty() const
{
	if(!head) 
		return 1;
	else
		return 0;
}

template <typename Info>
void Sequence<Info>::push_front(const Info& newInfo)
{
		element* newPtr = new element;
		newPtr->info = newInfo;	
		newPtr->next = NULL;
	
		if(isEmpty()) 
		{
			newPtr->next = NULL;
			head = newPtr;		
		}
		else 
		{		
			newPtr->next = head;
			head = newPtr;
		}
}

template <typename Info>
void Sequence< Info>::push_back(const Info& newInfo)
{
		element* newPtr = new element; 
		newPtr->info = newInfo;
		newPtr->next = NULL;

		if(isEmpty()) 
		{
			head = newPtr;		
		}
		else
		{
			element* temp = head;
			while(temp->next)
				temp = temp->next;
			temp->next = newPtr;			
		}	
}

template <typename Info>
bool Sequence< Info>::pop_front()
{
	if(isEmpty())
	{
		cout<<"The sequence is empty.\n";
		return false;
	}
	else
	{
		element* tempPtr = head;
		head = head->next;
		delete tempPtr;
		return true;	
	}
}

template <typename Info>
bool Sequence< Info>::pop_back()
{
	if(isEmpty())
	{
		cout<<"The sequence is empty.\n";
		return false;
	}
	else
	{
		if( head->next )
        {
            element* currentPtr = head;
            while( currentPtr->next->next )
				currentPtr = currentPtr->next;
            delete currentPtr->next;
            currentPtr->next = NULL;
        }
        else
        {
            delete head;
            head = NULL;
        }
		return true;
	}
}

template <typename Info>
void Sequence<Info>::insert(const Info& _where, const Info& newInfo)
{
	if(isEmpty()){
		push_front(newKey, newInfo);
		return;
	}
		element* newPtr = new element; 
		newPtr->info = newInfo;
		newPtr->next = NULL;
		
		element* temp = head;
		
		while (temp->next && temp->info != _where)
			temp = temp->next;
		newPtr->next = temp->next;
		temp->next = newPtr;
}

template <typename Info>
void Sequence<Info>::print() const
{
	if(isEmpty())
		cout<<"The sequence is empty.\n";
	else
	{
		element* currentPtr = head;
		cout<<"The sequence contains such elements:\n";
		while(currentPtr)
		{			
			cout<<currentPtr->info<<endl;
			currentPtr = currentPtr->next;
		}
	}
}

template <typename Info>
void Sequence <Info>::print(const Info& existInfo) const
{
	if(isEmpty())
		cout<<"The sequence is empty.\n";
	else
	{
		element* currentPtr = head;
		while(currentPtr)
		{	
			if(currentPtr->info == existInfo)
			{
				cout<<currentPtr->info<<endl;
				break;
			}
			else
				currentPtr = currentPtr->next;
		}
		if (!currentPtr)
			cout<<"No element with such key.\n";
	}
}

template <typename Info>
bool Sequence<Info>::find(const Info& existInfo) const
{
	element* elementPtr = head;
	bool found = false;

	while((!found) && (elementPtr))
	{
		if(elementPtr->info == existInfo) 
			found = true;
		else
			elementPtr = elementPtr->next; 
	}
	return found;
}

template <typename Info>
void Sequence<Info>::remove_all()
{
	while(head)
		pop_front();
}

template <typename Info>
bool Sequence<Info>::remove(const Info& what)
{	
	if(isEmpty())
		cout<<"The sequence is empty.\n";
	else
	{
		element* currentPtr = head;
		element* tempPtr = NULL;

		if(head->info == what)
		{
			tempPtr = head;
			head = head->next;
			delete tempPtr;
			return true;
		}
		while(currentPtr->next)
		{
			if(currentPtr->next->info == what)
			{
				tempPtr = currentPtr->next;
				currentPtr->next = currentPtr->next->next;
				delete tempPtr;
				return true;
			}
			else currentPtr = currentPtr->next;				
		}			
	}
	return false;
}

template <typename Info>
int Sequence<Info>::numberOfElements() const
{
	if(isEmpty())
		return 0;
	else
	{
		int numbers = 0;
		element* currentPtr = head;
		while(currentPtr)
		{
			++numbers;
			currentPtr = currentPtr->next;
		}
		return numbers;
	}
}

template <typename Info>
Info Sequence<Info>::elementAt(int index)
{
	if(isEmpty())
		cout<<"The sequence is empty.\n";
	else
	{
		int idx = 0;
		element* currentPtr = head;	
		while (currentPtr != NULL)
		{
			if (idx == index)		
				return currentPtr->info;
			else
			{
				currentPtr = currentPtr->next;
				++idx;
			}
		}
	}
	return Info();
}

template <typename Info>
Sequence<Info>& Sequence<Info>::operator=(const Sequence<Info>& sequence)
{
	remove_all();
    for(element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
        push_back(iterator->info );
    return *this;
}

template <typename Info>
Sequence<Info>& Sequence<Info>::operator+=(const Sequence<Info>& sequence)
{
    for(element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
        push_back(iterator->info );
    return *this;
}

template <typename Info>
Sequence<Info>& Sequence<Info>::operator+(const Sequence<Info>& sequence)
{
    for(element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
        push_back(iterator->info );
    return *this;
}

template <typename Info>
bool Sequence<Info>::operator!=(const Sequence<Info>& sequence) const
{
	bool isEqual = true;
	if (this->numberOfElements() != sequence.numberOfElements())
		isEqual = true;
	else
	for(element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
		for(element* iterator_this = this->head; iterator != NULL; iterator_this = iterator_this->next )
			if(iterator->info == iterator_this->info)
			{
				isEqual = false;
				break;
			}
	return isEqual;
}

template <typename Info>
bool Sequence<Info>::operator==(const Sequence<Info>& sequence) const
{
	bool isEqual = true;
	if (this->numberOfElements() != sequence.numberOfElements())
		isEqual = false;
	else
	for(element* iterator = sequence.head; iterator != NULL; iterator = iterator->next )
		for(element* iterator_this = this->head; iterator != NULL; iterator_this = iterator_this->next )
			if(iterator->info != iterator_this->info)
			{
				isEqual = false;
				break;
			}
	return isEqual;
}

template <typename Info>
ostream& operator<<(ostream& os, const Sequence<Info>& elementPtr)
{
	return os<<elementPtr;
}