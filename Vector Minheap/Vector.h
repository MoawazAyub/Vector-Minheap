# include < iostream >


using namespace std;


template < class T >
class vector
{
private:

	T * arr;
	int capacity;
	int size;

public:
	//------------------------------------------
	

	vector(int n, const T & elem)
	{
		
		capacity = n;
		arr = new T[capacity];
		size = n;

		for(int i = 0; i<n ; i++)
		{
			arr[i] = elem;
		
		}
	
	}

	void resize(int n, const T & elem)
	{
		if (arr != NULL)
		{
			//delete arr;
		
		}
		capacity = n;
		arr = new T[capacity];
		size = n;

		for(int i = 0; i<n ; i++)
		{
			arr[i] = elem;
		
		}
	
	}

	void set(int n, const T & elem)
	{
		arr[n] = elem;
	
	}
	//-------------------------------------------

	vector()
	{
		size = capacity = 0;
		arr = NULL;
	
	}

	vector(int s)
	{
		capacity = s;
		arr = new T[capacity];
		size = 0;
	
	}

	void reallocate(int n)
	{
		if (arr != NULL)
		{
			delete arr;
		
		}

		size = 0;
		capacity = n;

		arr = new T[capacity];
	
	
	}

	vector(const vector<T> & v)
	{
		size = v.size;
		capacity = v.capacity;

		arr = new T[capacity];

		for (int i = 0 ; i < size ; i++)
		{
			arr[i] = v.arr[i];
		
		}
	
	
	}

	const vector<T> & operator=(const vector<T> & v)
	{
		size = v.size;
		capacity = v.capacity;

		arr = new T[capacity];

		for (int i = 0 ; i < size ; i++)
		{
			arr[i] = v.arr[i];
		
		}

		return *this;
	
	
	}

	void print()
	{
		cout << "the size is " << size << endl;
		cout << "the capacity is " << capacity << endl;
		cout << "the array is " << endl;

		for (int i = 0 ; i < size ; i++)
		{
			cout << arr[i] <<" ";
		
		}

	cout << endl;
	
	}

	void push_back(const T & obj)
	{
		if(arr == NULL)
		{
			arr = new T[256];
			capacity = 256;
		
		}

		if (size < capacity)
		{
			arr[size] = obj;
			size++;
		
		}

		else if (size == capacity)
		{
			T* temp = new T[capacity * 2];
			for (int i = 0 ; i < capacity ; i++)
			{
				temp[i] = arr[i];
			
			}

			temp[capacity] = obj;

			capacity = capacity * 2;
			
			size++;

			delete arr;

			arr = temp;
		
		}
	
	}

	bool pop_back()
	{
		if (size == 0)
		{
			return false;
		
		}

		if (size > capacity/2)
		{
			size--;
		return true;
		}

		else
		{
			T * temp = new T[capacity/2];

			for (int i = 0 ; i < capacity/2 ; i++)
			{
				temp[i] = arr[i];
			
			}

			//delete arr;

			arr = temp;

			capacity = capacity/2;
			size--;
		return true;
		}
	
	}

	T & operator[](int i)
	{
		return arr[i];
	
	}

	int getsize()
	{
		return size;
	
	}

	~vector()
	{
		//if (arr != NULL)
//		delete [] arr;
	
	}

	
	
};