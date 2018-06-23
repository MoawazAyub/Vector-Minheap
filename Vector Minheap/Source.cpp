# include < iostream >
# include "Vector.h"
//# include <vector>
# include <string>
# include <fstream>
# include <math.h>

using namespace std;

template <class T>
class MinHeap
{
	vector<T> mh;

public:

	

	MinHeap(int n = 0)
	{
		mh.reallocate(n+1);
		mh.push_back(T());
	
	}

	int getsize()
	{
		return (mh.getsize() - 1);
	
	}

	int parent(int i)
	{
		return (i/2);
	
	}

	int lchild(int i)
	{
		return (2*i);
	
	}

	int rchild(int i)
	{
		return ((2*i) + 1);
	
	}

	T getmin()
	{
		return mh[1];
	
	}

	T *getminP()
	{
		return &(mh[1]);
	
	}

	void bubbleup(int i)
	{
		if(i > 1)
		{
			if(mh[parent(i)] > mh[i])
			{
				swap(mh[parent(i)],mh[i]);
				bubbleup(parent(i));
			
			}
		
		}
	
	}


	void insert(const T & key)
	{
		if (mh.getsize() == 0)
		{
			mh.push_back(T());
		
		}
		mh.push_back(key);
		bubbleup(getsize());

	
	}

	void printheap()
	{
		if(getsize() >= 1)
		{
			for(int i = 1 ; i <= getsize() ; i++)
			{
				cout<<mh[i]<<" ";
			
			}
		
		}
	
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++
	void printheapptr()
	{
		if(getsize() >= 1)
		{
			for(int i = 1 ; i <= getsize() ; i++)
			{
				cout<<*mh[i]<<" ";
			
			}
		
		}
	
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++
		void minheapyfyptr(int i)
	{
		int si = i;
		
		if(rchild(i) <= getsize())
		{
		if(lchild(i) <= getsize() && *mh[lchild(i)] < *mh[si] && *mh[lchild(i)] <= *mh[rchild(i)])
		{
			si = lchild(i);
		
		}
		}

		if(rchild(i) > getsize())
		{
		if(lchild(i) <= getsize() && *mh[lchild(i)] < *mh[si] )
		{
			si = lchild(i);
		
		}
		}

		else if(rchild(i) <= getsize() && *mh[rchild(i)] < *mh[si] && *mh[rchild(i)] < *mh[lchild(i)])
		{
			si = rchild(i);
		
		}

		if(si != i)
		{
			swap(mh[si],mh[i]);

			minheapyfy(si);
		
		}
	
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++

	void minheapyfy(int i)
	{
		int si = i;
		
		if(rchild(i) <= getsize())
		{
		if(lchild(i) <= getsize() && mh[lchild(i)] < mh[si] && mh[lchild(i)] <= mh[rchild(i)])
		{
			si = lchild(i);
		
		}
		}

		if(rchild(i) > getsize())
		{
		if(lchild(i) <= getsize() && mh[lchild(i)] < mh[si] )
		{
			si = lchild(i);
		
		}
		}

		else if(rchild(i) <= getsize() && mh[rchild(i)] < mh[si] && mh[rchild(i)] < mh[lchild(i)])
		{
			si = rchild(i);
		
		}

		if(si != i)
		{
			swap(mh[si],mh[i]);

			minheapyfy(si);
		
		}
	
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	void deleteminptr()
	{
		if(getsize() != 0)
		{
			mh[1] = mh[getsize()];

			mh.pop_back();

			minheapyfyptr(1);

			
		}
	
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	void deletemin()
	{
		if(getsize() != 0)
		{
			mh[1] = mh[getsize()];

			mh.pop_back();

			minheapyfy(1);

			
		}
	
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++
	void buildheapptr(vector<T> & arr)
	{
		mh = arr;

		for(int i = (getsize()/2) ; i >= 1 ; i--)
		{
			minheapyfyptr(i);
		}
	
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++

	void buildheap(vector<T> & arr)
	{
		mh = arr;

		for(int i = (getsize()/2) ; i >= 1 ; i--)
		{
			minheapyfy(i);
		}
	
	}

	friend ostream & operator<<(ostream &  out, const MinHeap & h)
{

	if(h.getsize() >= 1)
		{
			for(int i = 1 ; i <= h.getsize() ; i++)
			{
				cout<<h[i]<<" ";
			
			}
		
		}

	return out;
}

};

//----------------------------------------------------------------------------------------------------------------
class Treenode
{
public:
	int count;
	string sym;

	Treenode * lchild, * rchild;

	

	Treenode()
	{
		count = 0;
		lchild = NULL;
		rchild = NULL;
	
	}

	Treenode(const Treenode & t1)
	{
		count = t1.count;
		sym = t1.sym;
		lchild = new Treenode;
		rchild = new Treenode;
	     lchild = t1.lchild;
		 rchild = t1.rchild;
	
	}

	const Treenode & operator=(const Treenode & t1)
	{
		count = t1.count;
		sym = t1.sym;
		lchild = new Treenode;
		rchild = new Treenode;
		lchild = t1.lchild;
		rchild = t1.rchild;

		return * this;
	
	}



	bool operator<=(const Treenode & obj)
	{
		return (count <= obj.count);

	}

	bool operator>=(const Treenode & obj)
	{
		return (count >= obj.count);

	}

	bool operator<(const Treenode & obj)
	{
		return (count < obj.count);

	}

	bool operator>(const Treenode & obj)
	{
		return (count > obj.count);

	}

	friend ostream & operator<<(ostream &  out, const Treenode  & t)
{

	cout << t.sym << " " << t.count <<endl; 

	return out;
}

};
//----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------string to decimal

int btodconvertion(string s)
{
	int count = 0;
	for(int i = s.size() - 1 , j = 0 ; i >= 0 ; j++ , i-- )
	{
		int temp = static_cast<int>(s[i]) - 48;
		count = count + (static_cast<int>(pow(2,j)) * temp);
	
	}

	return count;
}

//--------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------vec sum


void vectorsum(vector<int> v1 , string *s, Treenode * t1)
{
	string s1;
	char c1 = t1->sym[0];
	for(int i = 0 ; i < v1.getsize(); i++)
	{
		s1 = s1 + static_cast<char>(v1[i]+48);
	
	}
	s[static_cast<int>(c1)] = s1;

}

void vecsum(vector<int> v1 , string * s, Treenode * t1)
	{
		
			
		if(t1->lchild != nullptr  ) 
			{
				v1.push_back(0);
				vecsum(v1,s,t1->lchild);
				v1.pop_back();
			
			}

			if(t1->rchild != nullptr)
			{
				v1.push_back(1);
				vecsum(v1,s,t1->rchild);
			v1.pop_back();
			
			
			}

			else if(t1->rchild == nullptr && t1->lchild == nullptr)
			{
				
				vectorsum(v1,s,t1);
			
			}
		
		
		
	
	}

//-----------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------dec to bin

string dectob(int index)
{
	string s,s1,s2,s3;
	int temp = index;

	while(temp != 0)
	{
		s = s + static_cast<char>(temp%2 +48);
		temp = temp / 2;
	}

	s1.resize(s.size());

	for(int i = s.size() - 1 , j = 0 ; i >= 0 ; i--,j++)
	{
		s1[j] = s[i];
	
	}

	temp = 8-s.size();

	for(int i = 0 ; i < temp ; i++)
	{
		s2 = s2 + '0';
	
	}

	s3 = s2 + s1;

	return s3;

}

//---------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------compress
void compress()
{
		ifstream fin,finn;	// object to read data from file.
		vector<char> charvec(256);
		
	char ch;
	int frequency[256] = {0};
	int count = 0;
	int countN = 0;
	int countn = 0;
	string s;

	fin.open("q1.8b",ios::in);	// opening file input.txt.

	if(!fin)	//Check if file has been opened or not.
	{
		cout<<"Could not open the input file.\n";
		return;
	}

	cout<<"Reading data character by character:\n";
	
	while (!fin.eof())		//Read until end of file.

	{
		ch = fin.get();		//Read a character from file.
		
		if(ch == '1' || ch == '0')
		{
		s = s + ch;
		count++;
		countN++;
		if(count == 8)
		{
			int temp = btodconvertion(s);
			charvec.push_back(temp);
			frequency[temp] = frequency[temp] + 1;
		     s = "";
			 count = 0;
		}
	    }
		//cout<<ch;
	}

	//for(int i = 0 ; i < 256 ; i++)
	//{
		//cout<<i<<" = "<<frequency[i]<<endl;
	
//	}

	fin.close();		//Close file after reading data.


	vector<Treenode> v1;
	Treenode t2,tr,tl,result;
	Treenode * trr, *tll;

	v1.push_back(t2);
	Treenode t1;
	MinHeap<Treenode> minh;
	
	for(int i = 0 ; i < 255 ; i++)
	{
		if(frequency[i] != 0)
		{
			t1.sym = static_cast<char>(i);
			t1.count = frequency[i];

			v1.push_back(t1);
		
		}

		
	
	}

	
	  minh.buildheap(v1);
	 // cout<<minh.getsize();
	//minh.printheap();
	  while(minh.getsize() != 1)
	  {
		  tl = minh.getmin();
		  trr = new Treenode;
		  tll = new Treenode;
		  
		  minh.deletemin();
		  tr = minh.getmin();
		   minh.deletemin();
		  trr->count = tr.count;
		  trr->sym = tr.sym;
		  trr->lchild = tr.lchild;
		   trr->rchild = tr.rchild;

		  tll->count = tl.count;
		  tll->sym = tl.sym;
		   tll->lchild = tl.lchild;
		   tll->rchild = tl.rchild;

		  result.lchild = tll;
		  result.rchild = trr;
		  result.count = tr.count + tl.count;
		  minh.insert(result);
		
	  
	  }
	cout<<result.count;
	Treenode* resultptr ;
	resultptr = & result;
	
	
	vector<int> vec1(256);
	
	string str[255];

	vecsum(vec1,str,resultptr);

	
	cout<<endl;
	
	 
		ofstream fout;	//Object to write data in file.

	fout.open("output.cmp", ios::out);		//open file output.txt. (Previous data in the file will be truncated.)

	if( fout )		//Check if file has been opened or not.
	{
		//Writing in the file.
		for(int i = 0 ; i < charvec.getsize(); i++)
		{
			for(int j = 0 ; j < str[static_cast<int>(charvec[i])].size(); j++)
			{
				fout<<str[static_cast<int>(charvec[i])][j];
			
			}
			
		}

		fout.close();		//Close the file after writing all the data.
	}
	else
	{
		//If file could not be opened, print error message.
		cout<<"File could not be opened.\n";
	} 


	//--------------------------------------------------compression ratio
	finn.open("output.cmp",ios::in);	// opening file input.txt.

	if(!finn)	//Check if file has been opened or not.
	{
		cout<<"Could not open the input file.\n";
		return;
	}

	cout<<"Reading data character by character:\n";
	
	while (!finn.eof())		//Read until end of file.

	{
		ch = finn.get();		//Read a character from file.
		
		if(ch == '1' || ch == '0')
		{
		
		countn++;
		
		}
		
		//cout<<ch;
	}

	

	fin.close();		//Close file after reading data.

	//

	cout<<endl;

	cout<< "compression complete ";

	double temp = (1 - (static_cast<double>(countn)/static_cast<double>(countN)))*100 ;
	cout<<temp<<" % ";

}
//-------------------------------------------------------------------------------------------------------------
void main()
{

	
	compress();

	//cout<<dectob(45);

	/*vector<int> p;
	p.push_back(0);
	p.push_back(3);
	p.push_back(2);
	p.push_back(1);
	p.push_back(1);
	

	MinHeap<int> a,b;
	
	
	
	b.buildheap(p);

	
	
	b.printheap();*/
	
}