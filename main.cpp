#include <iostream>
using namespace std;


struct Object
{
	virtual ~Object()
	{

	}
};

class MySimpleVector
{
	Object* obj = nullptr;
	size_t sz;
	size_t cap;

public:
	//Constructors
	MySimpleVector()
	{
		sz = 0;
		cap = 0;
		obj = nullptr;
	}

	MySimpleVector(size_t n)
	{
		sz = n;
		cap = n * 2;
		obj = new Object [n];
	}


	MySimpleVector(size_t n, const Object& value)
	{
		sz = n;
		cap = n * 2;
		*obj = value;
	}

	//Destructor
	~MySimpleVector()
	{
		delete[] obj;
	}


	MySimpleVector(const MySimpleVector& mv)
	{
		sz = mv.sz;
		cap = mv.cap;
		obj = new Object [sz];
	}


	// Operators
	Object& operator = (const MySimpleVector & mv)
	{
		delete[] obj;
		sz = mv.sz;
		obj = new Object [sz];
		//Ñassigment mv to obj
	}

	Object& operator [] (size_t i)
	{
		return obj[i];
	}

	Object& at (size_t i)
	{
		if (i >= sz)
		{
			throw std::out_of_range("Out of range");
		}
		return obj[i];
	}

	//Methods
	size_t size() const
	{
		return sz;
	}

	void reserve(size_t sz)
	{
		if (sz <= cap)
			return;
		// Allocate memory
		// copy elements
		// remove old pointer
	}


	size_t capacity() const
	{
		return cap;
	}


	void push_back(const Object& value)
	{
		if (sz == cap)
		{
			reserve(2 * cap);
		}
		new (obj + sz) Object(value);
		++sz;
	}

	void pop_back()
	{
		(obj + sz - 1)-> ~Object();
		--sz;
	}
};



int main()
{
	return 0;
}
