#include "List.h"
#include<iomanip>
#include<iostream>
using namespace std;
List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}


List::~List()
{
	List::clear();
}

void List::push_back(int data)
{
	Element* newElem = new Element(data);
	if (head == nullptr)
		head = newElem;
	else
		tail->next = newElem;
	tail = newElem;
	size++;
}

void List::push_front(int data)
{
	Element *newElem=new Element(data);
	if (head == nullptr)
		tail = newElem;
	else
		newElem->next = head;
	head = newElem;
	size++;
}

void List::pop_back()
{
	if (head != nullptr)
		if (head != tail)
		{
			Element *new_tail = head;
			while (new_tail->next != tail)
				new_tail = new_tail->next;
			delete tail;
			new_tail->next = nullptr;
			tail = new_tail;
			size--;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
		}
	else throw 0;
}

void List::pop_front()
{
	if (head != nullptr)
		if (head != tail)
		{
			Element *new_head = head->next;
			delete head;
			head = new_head;
			size--;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
		}
	else throw 0;
}

void List::insert(int data, size_t position)
{
	Element *newElem = new Element(data);
	if (position == size)
		List::push_back(data);
	if (position < size )
	{
		if (position == 0)
			List::push_front(data);
		if (position > 0)
		{
			Element* previous_position = head;
			while (position > 1)
			{
				previous_position = previous_position->next;
				position--;
			}
			newElem->next = previous_position->next;
			previous_position->next = newElem;
			size++;
		}
	}
	else throw 1;

}

int List::at(size_t position)
{
	if (position < size) 
	{
		Element* current_elem = head;
		while (position != 0)
		{
			current_elem = current_elem->next;
			position--;
		}
		return current_elem->data;
	}
	else throw 1;
}

void List::remove(size_t position)
{
	if (position < size)
	{
		if (position == 0)
			List::pop_front();
		if (position == size - 1)
			List::pop_back();

		if ((position > 0) && (position < size-1))
		{
			Element* previous_elem = head;
			while (position != 1)
			{
				previous_elem = previous_elem->next;
				position--;
			}
			Element* current_elem = previous_elem->next;
			previous_elem->next = current_elem->next;
			delete current_elem;
			current_elem = nullptr;
			size--;
		}
	}
	else throw 1;
}

size_t List::get_size()
{
	return size;
}

void List::print_to_console()
{
	Element* current_elem = head;
	cout << "List:  ";
	while (current_elem != nullptr)
	{
		cout << current_elem->data << "  ";
		current_elem = current_elem->next;
	}
	cout << endl;
	if (head == nullptr)
		cout << "List is empty";
}

void List::clear()
{
	while (head != nullptr)
		List::pop_front();
}

void List::set(size_t position, int new_data)
{
	if (position < size)
	{
		if (position == 0)
			head->data = new_data;
		if (position == size-1)
			tail->data = new_data;
		if ((position > 0) && (position < size-1))
		{
			Element* current_elem = head;
			while (position != 0)
			{
				current_elem = current_elem->next;
				position--;
			}
			current_elem->data = new_data;
		}
	}
	else throw 1;
}

bool List::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

size_t List::find_first(List* for_search)
{
	size_t count = 0;
	Element* p = head, *q = for_search->head;
	while ((p != nullptr) && (q != nullptr) && (size-count>=for_search->size)) {
		if (p->data == q->data)
			q = q->next;
		else
		{
			
			if (q != for_search->head)
			{
				q = for_search->head;
				count++;
				p = head; size_t i = count - 1;
				while (i != 0)
				{
					p = p->next;
					i--;
				}
			}
			else
			{
				q = for_search->head;
				count++;
			}


		}
		p = p->next;
	}
	if (q == nullptr)
		return count;
	return size;
}

void List::input_list()
{
	cout << "Number of elements: ";
	size_t number_of_elem;
	cin >> number_of_elem;
	while (number_of_elem > 0)
	{
		cout << "Input data: ";
		int data;
		cin >> data;
		List::push_back(data);
		number_of_elem--;
	}
	while (1)
	{
		cout << "\n1 push_back   2 push_front   3 pop_back   4 pop_front\n5 insert   6 remove   7 set   8 end\n\n";
		int choice; cin >> choice;
		if (choice == 8) break;
		int data; size_t position;
		switch (choice)
		{
		case 1: cout << "Data: "; cin >> data; List::push_back(data); List::print_to_console(); break;
		case 2: cout << "Data: "; cin >> data; List::push_front(data); List::print_to_console(); break;
		case 3: List::pop_back(); List::print_to_console(); break;
		case 4: List::pop_front(); List::print_to_console(); break;
		case 5: cout << "Data and position: "; cin >> data >> position; List::insert(data, position); List::print_to_console(); break;
		case 6: cout << "Position: "; cin >> position; List::remove(position); List::print_to_console(); break;
		case 7: cout << "Data and position: "; cin >> data >> position; List::set(position, data); List::print_to_console(); break;
		}
	}

}

bool List::size_equal(size_t expected)
{
	if (size == expected)
		return true;
	return false;
}

bool List::head_equal(int expected)
{
	if (head->data == expected)
		return true;
	return false;
}

bool List::tail_equal(int expected)
{
	if (tail->data == expected)
		return true;
	return false;
}
