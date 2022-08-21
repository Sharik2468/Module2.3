#include <iostream>
#include <vector>

template<class T>
class Iterator
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef std::forward_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

	Iterator(T* curr) :current(curr)
	{
	}
	Iterator& operator =(const Iterator& other)
	{
		if (this != &other)
		{
			current = other.current;
		}
		return *this;
	}
	Iterator& operator ++()
	{
		++current;
		return *this;
	}
	Iterator operator ++(int i)
	{
		Iterator tmp(current);
		++current;
		return tmp;
	}
	T& operator *()
	{
		return *current;
	}
	T* operator ->()
	{
		return current;
	}
	bool operator ==(const Iterator& other)
	{
		return current == other.current;
	}
	bool operator !=(const Iterator& other)
	{
		return !(*this == other);
	}
	int GetValue() { return 1; }
private:
	T* current;
};

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	Iterator<std::vector<int>> iter(&v); // получаем итератор

	++iter;             // перемещаемся вперед на один элемент
	std::cout << iter.GetValue() << std::endl;


	return 0;
}