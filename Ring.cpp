#pragma hdrstop

#include "Ring.h"
#include "Iterator.h"

template<typename Key, typename Info>
Ring<Key, Info>::Ring():head(NULL){};

template<typename Key, typename Info>
Ring<Key, Info>::Ring(const Ring<Key, Info>& ring):head(NULL)
{
	*this = ring;
}

template<typename Key, typename Info>
Ring<Key, Info>::~Ring()
{
	clear();
}

template<typename Key, typename Info>
void Ring<Key, Info>::push_front(const Key& newKey, const Info& newInfo)
{
	Element* newPtr = new Element();
	newPtr->key = newKey;
	newPtr->info = newInfo;

	if(isEmpty())
		head = newPtr->prev = newPtr->next = newPtr;
	else
	{
		newPtr->next = head;
		newPtr->prev = head->prev;
		head->prev->next = newPtr;
		head->prev = newPtr;
		head = newPtr;
	}
	return;
}

template<typename Key, typename Info>
void Ring<Key, Info>::push_back(const Key& newKey, const Info& newInfo)
{
	Element* newPtr = new Element();
	newPtr->key = newKey;
	newPtr->info = newInfo;

	if(isEmpty())
		head = newPtr->prev = newPtr->next = newPtr;
	else
	{
		Element* currPtr = head;
		while (currPtr->next != head)
			currPtr = currPtr->next;
		newPtr->next = head;
		newPtr->prev = currPtr;
		currPtr->next = newPtr;
		head->prev->next = newPtr;
		head->prev = newPtr;
	}
	return;
}

template<typename Key, typename Info>
void Ring<Key, Info>::insert(Iterator& iterator,const Key& newKey, const Info& newInfo)
{
	if(iterator == NULL){
		cout<<"\nThe iterator is NULL\n" ;
		return;
	}
		
	Element* currPtr = iterator.Ptr;
	Element* newPtr = new Element;
	newPtr->key = newKey;
	newPtr->info = newInfo;

	newPtr->next = currPtr;
	newPtr->prev = currPtr->prev;
	currPtr->prev->next = newPtr;	
	currPtr->prev = newPtr;
	currPtr = newPtr;

	if(currPtr->next == head)
		head = currPtr;
	iterator--;
}

template<typename Key, typename Info>
bool Ring<Key, Info>::pop_back()
{
	if (isEmpty())	{
		cout<<"The Ring is empty\n";
		return false;
	}
	if(head->next == head)
	{
		delete head;
		head = NULL;
	}
	else
	{			
		Element* tempPtr = head->prev->prev;
		tempPtr->next = head;			
		delete head->prev;
		head->prev = tempPtr;				
		end() = head->prev;
	}
	return true;
}

template<typename Key, typename Info>
bool Ring<Key, Info>::pop_front()
{
	if (isEmpty())
	{
		cout<<"The Ring is empty\n";
		return false;
	}	
	else
	{	
		Element* tempPtr = head;
		if (tempPtr->next == head)
		{
			delete head;
			head = NULL;
		}
		else
		{
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
			delete tempPtr;			
		}
		return true;
	}
}

template<typename Key, typename Info>
void Ring<Key, Info>::clear()
{
	if (isEmpty())
		cout<<"The Ring is empty\n";
	else
	{		
		head->prev->next = NULL;
		Element* currPtr;

		while(head)
		{
			currPtr = head;
			head = head->next;
			delete currPtr;
		}
	}
}

template<typename Key, typename Info>
bool Ring<Key, Info>::remove(Iterator& iterator)
{
	if (iterator == NULL)
		return false;
	
	Element* currPtr = iterator.Ptr;
	if(currPtr == head && currPtr->next == head)
	{
		delete head;
		head = NULL;
		iterator = NULL;
	}
	else if(currPtr == head && currPtr->next != head)
		head = head->next;
	
	iterator--;
	currPtr->prev->next = currPtr->next;
	currPtr->next->prev = currPtr->prev;
	delete currPtr;
	return true;
}


template<typename Key, typename Info>
bool Ring<Key, Info>::isEmpty() const
{
	if(!head) 
		return 1;
	else
		return 0;
}

template<typename Key, typename Info>
void Ring<Key, Info>::print() const
{
	if (isEmpty())
		cout<<"The Ring is empty\n";
	else
	{
		Element* currPtr = head;
		do
		{
			cout<<"Key = "<<currPtr->key
				<<" Info = "<<currPtr->info<<endl;
			currPtr = currPtr->next;
		}
		while(currPtr!= head);
	}
}

template<typename Key, typename Info>
void Ring<Key, Info>::print(const Key& existKey) const
{
	if (isEmpty())
		cout<<"The Ring is empty\n";
	else
	{
		Element* currPtr = head;
		while(currPtr)
		{
			if(currPtr->key == existKey) 
			{
				cout<<"Key = "<<currPtr->key
					<<" Info = "<<currPtr->info<<endl;
				break;
			}
			else 
				currPtr = currPtr->next;
		}
		if (!currPtr)
			cout<<"No element with such key.\n";
	}
}

template<typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::find(const Key& existKey) const
{
	Iterator it = begin();
	if(!isEmpty())
	{
		do
		{
			if(*it == existKey)
				return it;
			it++;
		}
		while (it != begin());
		cout<<"No elemtent with such key\n";
		return NULL;
	}
	else 
	{
		cout<<"The Ring is empty\n";
		return NULL;
	}
}

template<typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::begin() const
{
	if(!head)
		return NULL;
	Iterator iter(head); 
	return iter;
}

template<typename Key, typename Info>
typename Ring<Key, Info>::Iterator Ring<Key, Info>::end() const
{
	if(!head)
		return NULL;
	Iterator iter(head->prev); 
	return iter;
}

template<typename Key, typename Info>
int Ring<Key, Info>::size() const
{
	if(isEmpty())
		return 0;

	int amount = 0;
	Element* currPtr = head;
	do
	{
		amount++;
		currPtr = currPtr->next;
	}
	while(currPtr != head);
	return amount;
}

template <typename Key, typename Info>
Info Ring<Key, Info>::get(const Key& existKey) const
{
	if(isEmpty())
		cout<<"The ring is empty.\n";
	else
	{
		Element* currentPtr = head;	
		while (currentPtr)
		{
			if (currentPtr->key == existKey)		
				return currentPtr->info;
			else
				currentPtr = currentPtr->next;
		}
		if(!currentPtr)
			cout<<"No element with such key.\n";
	}
	return NULL;
}

template<typename Key, typename Info>
const Ring<Key, Info>& Ring<Key, Info>::operator=(const Ring<Key, Info>& ring)
{
	  /*if (this == ring)       
         return *this;*/
         
      clear();       
      
	  if (ring.isEmpty())           
         return *this;
         
	  Element* ptr = ring.head;    
      
      do 
	  {                       
		 push_back(ptr->key, ptr->info);
         ptr = ptr->next;
      } 
	  while (ptr != ring.head); 
      
      return *this;
}

template<typename Key, typename Info>
bool Ring<Key, Info>::operator==(const Ring<Key, Info>& ring) const
{
     if (this->isEmpty() && ring.isEmpty())
        return true;
     
     if (this->size() != ring.size()) 
        return false;
     
     Element* ptr1 = this->head;
     Element* ptr2 = ring.head;
     
     do 
	 {
		 if (ptr1->key != ptr2->key || ptr1->info != ptr2->info)  
           return false;               
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
     } 
	 while ((ptr1 == NULL) || (ptr2 == NULL));
     
     return true;
}

template<typename Key, typename Info>
bool Ring<Key, Info>::operator!=(const Ring<Key, Info>& ring) const
{
	return !(*this != ring);
}

template<typename Key, typename Info>
void Ring<Key, Info>::produce(const Ring<Key, Info>& ring_1, Key key_1, int length_1, 
							  const Ring<Key, Info>& ring_2, Key key_2, int length_2,
							  int repeat, bool clockwise)
{
	if(ring_1.isEmpty() && ring_2.isEmpty()){
		cout<<"Ring is empty";
		return;
	}

	Ring<Key, Info> result;

	int temp_repeat = 0;
	int len1 = abs(length_1), len2 = abs(length_2);
	Iterator it_1 = ring_1.find(key_1);
	Iterator it_2 = ring_2.find(key_2);

	while(temp_repeat < repeat){
		for(;len1 > 0; len1--){
			if (it_1 == NULL) break;
			clockwise ? result.push_back(*it_1, ring_1.get(*it_1)) 
				: result.push_front(*it_1, ring_1.get(*it_1));
			length_1 > 0 ? ++it_1 : --it_1;
		}
		for(;len2 > 0; len2--){
			if (it_2 == NULL) break;
			clockwise ? result.push_back(*it_2, ring_2.get(*it_2)) : result.push_front(*it_2, ring_2.get(*it_2));
			length_2 > 0 ? ++it_2 : --it_2;
		}

		temp_repeat++;
		len1 = abs(length_1);
		len2 = abs(length_2);
	}
	*this = result;
}