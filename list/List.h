#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node* pNext = NULL)
	{
		this->data = data;
		this->pNext = pNext;
	}
};


template<class T>
class List
{
private:

	int Size;
	Node<T>* head;

	Node<T>* find_prev(int index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		return previous;
	}
public:

	List()
	{
		Size = 0;
		head = NULL;
	}
	List(List<T>& ob)
	{
		Size = 0;
		head = NULL;
		for (int i = 0; i < ob.Size; i++)
			push_back(ob[i]);
	}

	~List()
	{
		while (Size)
			pop_front();
	}

	void push_back(T data)
	{
		if (head == NULL)
			head = new Node<T>(data);
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != NULL)
				current = current->pNext;
			current->pNext = new Node<T>(data);
		};

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("empty");

		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("wrong index");

		if (index == 0)
			push_front(data);
		else if (index == Size)
			push_back(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;

			Size++;
		}
	}


	void pop_back()
	{
		if (Size == 0)
			throw logic_error("Empty");

		

		Node<T>* previous = find_prev(Size - 1);

		Node<T>* temp = previous->pNext;
		previous->pNext = NULL;

		delete temp;
		Size--;
	}

	ostream& operator << (ostream& ostr, List<T>& list)
	{
	
		for (int i = 0; i < list.GetSize(); i++)
			ostr << list[i] << " ";

		ostr << "\n";
		return ostr;
	}

	int GetSize() const { return Size; }
	
};