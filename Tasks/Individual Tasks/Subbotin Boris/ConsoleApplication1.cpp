// ConsoleApplication1.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"

using namespace std;

class Stack
{
public:
	Stack(int capacity = DEFAULT_STACK_CAPACITY); // Конструктор стека
	~Stack(); // Деструктор стека
	friend ostream& operator<<(ostream& os, const Stack &stack); // Вывод информации о стеке на экран
	int getCapacity() const; // Возвращает текущую вмстимость стека
	int push(int element); // Добавляет элемент в стек и возвращает значение этого элемента
	void pop(); // Удаляет элемент стека

private:
	static const int DEFAULT_STACK_CAPACITY = 5; // Стандартный размер стека
	int *capacity; // Вместимость стека
	int *size; // Текущее количество элементов стека
	unsigned int *head; // Положение элемента головы стека
	unsigned int *V; // Стек
	int getSize() const; // Возвращает текущее количество элементов в стеке
	int getHead() const; // Возвращает индекс головного элемента
	int getIndex(int i = 0) const; // Возвращает i-ый индекс стека относительно его головного элемента
	void setSize(int n); // Задает значение количества элементов стека
	void setHead(int n); // Задает значение головного элемента стека
	void setCapacity(int n); // Задает значение вместимости стека
	bool isEmpty() const; // Проверяет стек на пустоту
	bool isFull() const; // Проверяет стек на заполненность
	void circularShiftRight(); // Циклический сдвиг стека вправо
	void circularShiftLeft(); // Циклический сдвиг стека влево
	void expand(); // Увеличивает вместимость стека в два раза
	void narrow(); // Уменьшает вместимость стека в два раза
};

Stack::Stack(int capacity)
{
	this->capacity = new int(capacity);
	this->head = new unsigned int((capacity - 1) / 2);
	this->size = new int(0);
	this->V = new unsigned int[capacity];
}

Stack::~Stack()
{
	delete this->capacity;
	delete this->head;
	delete this->size;
	delete[] this->V;
}

int Stack::getCapacity() const
{
	return *this->capacity;
}

int Stack::getSize() const
{
	return *this->size;
}

int Stack::getHead() const
{
	return *this->head;
}

bool Stack::isEmpty() const
{
	return this->getSize() == 0 ? true : false;
}

int Stack::getIndex(int i) const
{
	return (this->getHead() + i) % this->getCapacity();
}

void Stack::setSize(int n)
{
	*this->size = n;
}

void Stack::setHead(int n)
{
	*this->head = n;
}

void Stack::setCapacity(int n)
{
	*this->capacity = n;
}

bool Stack::isFull() const
{
	return this->getSize() == this->getCapacity() ? true : false;
}

void Stack::circularShiftRight()
{
	int tmp = this->V[this->getIndex(-1)];
	for (int i = this->getCapacity() - 2; i >= 0; i--)
		this->V[this->getIndex(i + 1)] = this->V[this->getIndex(i)];
	this->V[this->getIndex()] = tmp;
}

void Stack::circularShiftLeft()
{
	int tmp = this->V[this->getIndex(this->getCapacity())];
	for (int i = 0; i < this->getCapacity() - 1; i++)
		this->V[this->getIndex(i)] = this->V[this->getIndex(i + 1)];
	this->V[this->getIndex(this->getCapacity() - 1)] = tmp;
}

ostream& operator<<(ostream& os, const Stack &stack)
{
		cout << "Вместимость стека: " << stack.getCapacity() << endl;
		cout << "Количество элементов в стеке: " << stack.getSize() << endl;
	if (!stack.isEmpty())
	{
		cout << "Индекс начального элемента вектора: " << stack.getHead() << endl;
		for (int i = 0; i < stack.getSize(); i++)
			os << stack.V[stack.getIndex(i)] << " ";
		os << endl;
	}
	return os;
}

void Stack::expand()
{
	Stack tmp(this->getCapacity()*2);
	for (int i = 0; i < this->getSize(); i++)
		tmp.V[tmp.getIndex(i)] = this->V[this->getIndex(i)];
	tmp.setSize(this->getSize());
	delete[] this->V;
	this->setCapacity(tmp.getCapacity());
	this->setHead(tmp.getHead());
	this->V = new unsigned int[this->getCapacity()];
	for (int i = 0; i < tmp.getSize(); i++)
		this->V[this->getIndex(i)] = tmp.V[this->getIndex(i)];
}

void Stack::narrow()
{	
	Stack tmp(this->getCapacity() / 2);
	for (int i = 0; i < this->getSize(); i++)
		tmp.V[tmp.getIndex(i)] = this->V[this->getIndex(i)];
	tmp.setSize(this->getSize());
	delete[] this->V;
	this->setCapacity(tmp.getCapacity());
	this->setHead(tmp.getHead());
	this->V = new unsigned int[this->getCapacity()];
	for (int i = 0; i < tmp.getSize(); i++)
		this->V[this->getIndex(i)] = tmp.V[this->getIndex(i)];
}

int Stack::push(int element)
{
	if (this->isFull())
		this->expand();
	if (!this->isEmpty())
		this->circularShiftRight();
	this->V[this->getIndex()] = element;
	this->setSize(this->getSize() + 1);
	return element;
}

void Stack::pop()
{
	if (!this->isEmpty()) {
		this->circularShiftLeft();
		this->setSize(this->getSize() - 1);
		if ((this->getSize() != 0) && (this->getCapacity() / this->getSize() == 2))
			this->narrow();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Stack stack;
	for (int i = 0; i < 5; i++)
		stack.push(i + 1);
	stack.push(6);
	cout << stack << endl;
	stack.pop();
	cout << stack;
	system("pause");
	return 0;
}

