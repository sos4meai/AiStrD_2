#pragma once
class List
{
public:
	List();
	~List();

	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void insert(int data, size_t position);
	int at(size_t position);
	void remove(size_t position);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t position, int new_data);
	bool isEmpty();
	size_t find_first(List* for_search);

	void input_list();
	bool size_equal(size_t expected);
	bool head_equal(int expected);
	bool tail_equal(int expected);
private:
	class Element
	{
	public:
		int data;
		Element* next;
		Element(int data=0, Element* next=nullptr)
		{
			this->data = data;
			this->next = next;
		}

	};
	Element* head;
	Element* tail;
	size_t size;

};

