#include <iostream>
#include <string>
using namespace std;

template <class T>
T add(T param1, T param2)
{
	return param1 + param2;
}

template <typename T>
class Vector
{
private:
	T* values = nullptr;
	unsigned int size = 0;

public:
	Vector()
	{
	}

	Vector(T* values, unsigned int size)
	{
		if (values != nullptr)
		{
			this->values = new T[size];
			this->size = size;
			for (unsigned int i = 0; i < size; i++)
			{
				this->values[i] = values[i];
			}
		}
	}

	Vector(const Vector<T>& v)
	{
		if (v.values != nullptr)
		{
			this->values = new T[v.size];
			this->size = v.size;
			for (unsigned int i = 0; i < v.size; i++)
			{
				this->values[i] = v.values[i];
			}
		}
	}

	~Vector()
	{
		if (values != nullptr)
		{
			delete[] values;
		}
	}

	Vector<T>& operator=(const Vector<T>& v)
	{
		if (this != &v)
		{
			if (values != nullptr)
			{
				delete[] values;
			}
			if (v.values != nullptr)
			{
				this->values = new T[v.size];
				this->size = v.size;
				for (unsigned int i = 0; i < v.size; i++)
				{
					this->values[i] = v.values[i];
				}
			}
			else
			{
				this->values = nullptr;
				this->size = 0;
			}
		}
		return *this;
	}

	unsigned int getSize()
	{
		return size;
	}

	T operator[](unsigned int index);
};

template <typename T>
T Vector<T>::operator[](unsigned int index)
{
	if (index < size)
	{
		return values[index];
	}
	else
	{
		return T();
	}
}

int main()
{
	cout << add<int>(1, 2) << endl;
	cout << add(2.5, 3.5) << endl;

	int array[]{ 1, 2, 3, 4, 5 };
	Vector<float> v1;
	Vector<int> v2(array, 5);
	Vector<int> v3 = v2;
	Vector<int> v4;
	v4 = v2;
	cout << endl;
	cout << v4[4] << endl;
	cout << v4[7] << endl;
}