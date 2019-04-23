#include <iostream>
#include <string>

using namespace std;

template <class type>
class part
{
public:
	part();
	~part();
	void set_element(type new_element);
	void set_next(part<type> *new_next);
	void set_previous(part<type> *new_previous);
	type get_element();
	part<type> *get_next();
	part<type> *get_previous();
private:
	type element;
	part<type> *next;
	part<type> *previous;
};


template <class type>
class list
{
public:
	list();
	~list();
	void add(type element);
	void del(type element);
	void print();
	bool check(type element);
	type at(int i);
	int get_size();
	void del_all();
private:
	part<type> *begin, *end;
	int size;
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class type>
part<type>::part()
{
	this->next = NULL;
	this->previous = NULL;
}

template <class type>
part<type>::~part()
{

}

template <class type>
void part<type>::set_element(type new_element)
{
	this->element = new_element;
}

template <class type>
void part<type>::set_next(part *new_next)
{
	this->next = new_next;
}

template <class type>
void part<type>::set_previous(part *new_previous)
{
	this->previous = new_previous;
}

template <class type>
type part<type>::get_element()
{
	return this->element;
}

template <class type>
part<type> *part<type>::get_next()
{
	return this->next;
}

template <class type>
part<type> *part<type>::get_previous()
{
	return this->previous;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class type>
list<type>::list() 
{
	this->begin = NULL;
	this->end = NULL;
	this->size = 0;
}

template <class type>
list<type>::~list()
{

}

template <class type>
void list<type>::print()
{
	part<type> *now = this->begin;
	while (now)
	{
		cout << now->get_element() << " ";
		now = now->get_next();
	}
	cout << endl;
}

template <class type>
void list<type>::add(type element)
{
	this->size++;
	part<type> *new_element;
	new_element = new part<type>;
	new_element->set_element(element);
	new_element->set_next(NULL);
	new_element->set_previous(NULL);
	if (!this->begin)
	{
		this->begin = new_element;
		this->end = this->begin;
	}
	else
	{
		this->end->set_next(new_element);
		new_element->set_previous(this->end);
		this->end = new_element;
	}
}

template <class type>
void list<type>::del(type element)
{
	part<type> *now = this->begin;
	part<type> *previous = NULL;
	if (this->begin->get_element() == element)
	{
		this->begin = this->begin->get_next();
		this->begin->set_previous = NULL;
		delete now;
		this->size--;
	}
	else
	{
		while (now)
		{
			if (now->get_element() == element && now == this->end)
			{
				this->end = now->get_previous();
				delete now;
				this->size--;
				return;
			}
			if (now->get_element() == element)
			{
				previous = now->get_previous();
				previous->set_next(now->get_next());
				delete now;
				this->size--;
				return;
			}
			else
			{
				now = now->get_next();
			}
		}
	}
}

template <class type>
bool list<type>::check(type element)
{
	part<type> *now = this->begin;
	bool result = false;
	while (now)
	{
		if (now->get_element() == element)
		{
			result = true;
			return result;
		}
		now = now->get_next();

	}
	return result;
}

template <class type>
type list<type>::at(int i)
{
	part<type> *now = this->begin;
	for (int j = 0; j < i; j++)
	{
		if (!now)
		{
			return this->begin->get_element();
		}
		now = now->get_next();
	}
	return now->get_element();
}

template <class type>
int list<type>::get_size()
{
	return this->size;
}

template <class type>
void list<type>::del_all()
{
	part<type> *now = this->begin;
	while (now)
	{
		this->begin = this->begin->get_next();
		delete now;
		now = this->begin;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

