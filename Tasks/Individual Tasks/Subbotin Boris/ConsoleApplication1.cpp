// ConsoleApplication1.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"

using namespace std;

struct Vector
{
	static const int DEFAULT_STACK_CAPACITY = 5;
	int capacity; // Вместимость
	int size; // Текущее количество элементов
	unsigned int head; // Положение элемента головы
	unsigned int *V; // Массив
};

Vector newVector(int capacity = 5) // На вход подается вместимость вектора. Возвращает вектор с инициализированными полями
{
	Vector vector;
	vector.capacity = capacity;
	vector.head = (capacity - 1) / 2;
	vector.size = 0;
	vector.V = new unsigned int[capacity];
	return vector;
}

bool vectorEmpty(const Vector &vector) // Проверяет вектор на пустоту
{
	return vector.size == 0 ? true : false;
}

bool vectorFull(const Vector &vector) // Проверяет вектор на заполненность
{
	return vector.size == vector.capacity ? true : false;
}

int vectorGetIndex(const Vector &vector, int delta = 0, int iterator = 0) // Преобразовывает индекс массива в индекс вектора относительно его начала, возвращает начальный элемент если параметры = 0
{
	return (iterator + vector.head + delta) % vector.capacity;
}

void vectorCircularShiftRight(Vector &vector) // Циклический сдвиг вектора вправо
{
	int tmp = vector.V[vectorGetIndex(vector, -1)];
	for (int i = vector.capacity - 2; i >= 0; i--)
		vector.V[vectorGetIndex(vector, 1, i)] = vector.V[vectorGetIndex(vector, 0, i)];
	vector.V[vectorGetIndex(vector)] = tmp;
}

void vectorCircularShiftLeft(Vector &vector) // Циклический сдвиг вектора влево
{
	int tmp = vector.V[vectorGetIndex(vector, vector.capacity)];
	for (int i = 0; i < vector.capacity - 1; i++)
		vector.V[vectorGetIndex(vector, 0, i)] = vector.V[vectorGetIndex(vector, 1, i)];
	vector.V[vectorGetIndex(vector, vector.capacity - 1)] = tmp;
}

ostream& operator<<(ostream& os, const Vector& vector) // Вывод вектора
{
		cout << "Вместимость стека: " << vector.capacity << endl;
		cout << "Количество элементов в стеке: " << vector.size << endl;
		cout << "Индекс начального элемента вектора: " << vector.head << endl;
	if (!vectorEmpty(vector))
	{
		for (int i = 0; i < vector.size; i++)
			os << vector.V[(i + vector.head) % vector.capacity] << " ";
		os << endl;
	}
	return os;
}

void vectorExpand(Vector &vector) // Увеличение вместимости вектора
{
	Vector tmp = newVector(vector.capacity * 2);
	for (int i = 0; i < vector.size; i++)
		tmp.V[vectorGetIndex(tmp, 0, i)] = vector.V[vectorGetIndex(vector, 0, i)];
	delete[] vector.V;
	vector.capacity = tmp.capacity;
	vector.head = tmp.head;
	vector.V = tmp.V;
}

void vectorNarrow(Vector &vector) // Уменьшение вместимости вектора
{	
	int capacity;
	vector.capacity > vector.DEFAULT_STACK_CAPACITY ? capacity = vector.capacity / 2 : capacity = vector.capacity;
	Vector tmp = newVector(capacity);
	for (int i = 0; i < vector.size; i++)
		tmp.V[vectorGetIndex(tmp, 0, i)] = vector.V[vectorGetIndex(vector, 0, i)];
	delete[] vector.V;
	vector.capacity = tmp.capacity;
	vector.head = tmp.head;
	vector.V = tmp.V;
}

int vectorPush(Vector &vector, int element) // Добавление элемента
{
	if (vectorFull(vector))
		vectorExpand(vector);
	if (!vectorEmpty(vector))
		vectorCircularShiftRight(vector);
	vector.V[vectorGetIndex(vector)] = element;
	vector.size++;
	return element;
}

void vectorPop(Vector &vector) // Удаление элемента
{
	if (!vectorEmpty(vector))
		vectorCircularShiftLeft(vector);
	vector.size--;
	if ((vector.size != 0) && (vector.capacity / vector.size == 2))
		vectorNarrow(vector);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Vector vector = newVector();
	for (int i = 0; i < 10; i++)
		vectorPush(vector, i + 1);
	cout << vector;
	system("pause");
	return 0;
}

