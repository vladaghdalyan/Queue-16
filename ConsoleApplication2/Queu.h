#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
#ifndef QUEU_H
#define QUEU_H
template<class Type>
class Queue;
template <class Type>
class QueueItem
{
public:
	QueueItem() :item(0), next(0){}
	QueueItem(const Type & t):item(t){ next = 0; }
	QueueItem(const QueueItem* pq) :item(pq->item), next(pq->next){}
	friend class Queue<Type>;
	/////////////////////////////////////////////////////////////

	template<class Type>friend ostream&	operator<<(ostream & os, const QueueItem<Type> & qi);
	template<class Type>friend ostream& operator<<(ostream &os, const Queue<Type> &q);

	/////////////////////////////////////////////////////////////

private:
	Type item;
	QueueItem *next;
};

/////////////////////////////////////////////////////////////
template<class Type>  ostream&	operator<<(ostream & os, const QueueItem<Type> & qi)
{

os << qi.item;
return os;
}
/////////////////////////////////////////////////////////////
template<class Type>
class Queue
{
public:
	Queue() :front(0), back(0){ count++; };
	void remove();
	void push(const Type &);
	bool empty()const { return front == 0; }
	bool is_full();
	static void f(){ cout << count << endl; }
	/////////////////////////////////////////////////////////////
	template<class Type>friend ostream& operator<<(ostream &os, const Queue<Type> &q);
	/////////////////////////////////////////////////////////////
	Queue& operator=(Queue&r);
	void ff();

	~Queue();
private:
	static int count;
	QueueItem<Type> *front;
	QueueItem<Type> *back;
};
template<class T>int  Queue<T>::count = 0;
template<class T> void Queue<T>::ff()
{
//	std::cout << (front)->item << "   " << front << std::endl;
	QueueItem<T> *p=front;
//	for (; p!=0;p=p->next)
	while (front)
	{
		std::cout << (front)->item << "   " << front << std::endl;
		front = front->next;
	}
}
template<class Type> Queue<Type>&  Queue<Type>::operator=(Queue<Type>& right)
{
	if (this != &right)
	{ 
		//front= new QueueItem<Type>(right.front);
		/*for (int i = 0; i < 3;i++)
		{
			
			front = front->next;
		}*/
		//QueueItem<Type>*tmp = right.front;
	

		//QueueItem<Type>*q;
		//front = new QueueItem<Type>(right.front);
		QueueItem<Type>*q;
		for (q = right.front; q; q = q->next)
		{ //count++;
		this->front = new QueueItem<Type>(q);
		}
	//	back = new QueueItem<Type>(right.back);
	}
	else
	{
		cout << "self-certification\n";
		exit(-1);
	}
	return *this;
}




/////////////////////////////////////////////////////////////
template <class Type>  ostream& operator<<(ostream &os, const Queue<Type> &q)
{
	//os << "< ";
	QueueItem<Type> *p;
	for (p = q.front; p; p = p->next)
		os << *p << " ";
	//os << " >";
	return os;
}
/////////////////////////////////////////////////////////////
 template<class Type>void Queue<Type>::push(const Type& val)
{
	QueueItem<Type> *pt =	new QueueItem<Type>(val);
	if (empty())
	{
		front = back = pt;
	}
	else
	{
		back->next = pt;
		back = pt;
	}
}
template<class T> Queue<T>::~Queue()
{

	//cout << " destructor\n";
	while (!empty())
	{
		count--;
			remove();
			//cout << " destructor\n";
	}
}

template<class T>void Queue<T>::remove()
{
	if (empty())
	{
		std::cerr << "remove() вызвана для пустой очереди\n";
		exit(-1);
	}
	QueueItem<T> *pt = front;
	front = front->next;
	//T retval = pt->item;
	delete pt;
	std::cout << " destructor\n";
	//return retval;
}

#endif