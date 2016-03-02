//#include "Iterator.h"
//
//template<typename Key, typename Info>
//Iterator class Ring<Key, Info>::Iterator():Ptr(NULL){};
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Iterator(Element* ptr):Ptr(ptr){};
//	
//template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator(const Iterator& iterator):Ptr(NULL){ *this = iterator; }
//	
//template<typename Key, typename Info>
//class Ring<Key, Info>::~Iterator() {this->Ptr = NULL;};
//
//template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator	const Iterator& operator=(const Iterator& iterator) 
//	{
//		Ptr = iterator.Ptr;
//		return *this;
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Iterator operator++()
//	{
//		Iterator curr(Ptr);
//		Ptr = Ptr->next;
//		return curr;
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Iterator operator++(int)
//	{
//		Ptr = Ptr->next;
//		return *this;
//	}
//
//	
//template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Iterator operator--()
//	{
//		Iterator curr(Ptr);
//		Ptr = Ptr->prev;
//		return curr;
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Iterator operator--(int)
//	{
//		Ptr = Ptr->prev;
//		return *this;
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator bool operator==(const Iterator& iterator) const
//	{
//		return (Ptr == iterator.Ptr);
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator bool operator!=(const Iterator& iterator) const
//	{
//		return (Ptr != iterator.Ptr);
//	}
//
//	template<typename Key, typename Info>
//class Ring<Key, Info>::Iterator Key& operator*() {return (Ptr->key);}
