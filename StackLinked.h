#if !defined (STACKLINKED_H)
#define STACKLINKED_H

#include "NextNode.h"

template < class T >
class StackLinked
{
	private:
		NextNode<T>* top;
		int sze;  // number of items in the stack

	public:
		StackLinked();
		~StackLinked();
		bool isEmpty();
		int size();
		void popAll();
		T* pop();
		void push(T* item);
		T* peek();
};

template < class T >
StackLinked<T>::StackLinked()
{
	top = NULL;
	sze = 0;
}

template < class T >
StackLinked<T>::~StackLinked()
{
	popAll();
}

template < class T >
bool StackLinked<T>::isEmpty()
{
	return sze == 0;
}

template < class T >
int StackLinked<T>::size()
{
	return sze;
}

template < class T >
void StackLinked<T>::popAll()
{
	//loop over the stack, deleting the nodes
	//the actual items are not deleted
	if (sze == 0) return;

	NextNode<T>* curr = top;
	NextNode<T>* prev = NULL;
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->getNext();
		prev->setNext(NULL);
		delete prev;
	}
}

template < class T >
T* StackLinked<T>::peek()
{
	T* item = NULL;
	//DO THIS
	if (!isEmpty()) //see if list has anything 
	{  
		item = top->getItem();
	}
	return item;
}

template < class T >
void StackLinked<T>::push(T* item)
{
	//DO THIS
	NextNode<T>* node = new NextNode<T>(item); //create a new pointer with item in it
	
	node->setNext(top); //get node to point to the top
	top = node; // make top pointing to the node
	
	sze++;
	///delete node;
	/*for unknown reasons, when deleting the node, the program crashed on runtime
		but with this commented out, it works as usual.*/
}

template < class T >
T* StackLinked<T>::pop()
{
	if (sze == 0) return NULL;

	//DO THIS
	NextNode<T>* node = top; //create pointer pointing to top
	
	T* item = top->getItem(); //get the current item from node pointing at top
	top = node->getNext(); //move the node pointer to the next item, set it to top
	
	
	sze--;
	
	delete node;
	return item; //return the item that's "popped" out
}

#endif