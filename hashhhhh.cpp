#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class GetData
{
	protected:
		vector<int> arr;
	public:
		virtual void getter(string obj) = 0;
		virtual void setter() = 0;
		GetData() {}
		GetData(vector<int> arr)
		{
			this -> arr = arr;
		}
};


class Get_Data_by_File : public GetData
{
	public:
	void getter(string obj) override
	{
		int tmp;
		string path = obj;
		fstream pf;
		pf.open(path, fstream::in);
		if (!pf.is_open())
		{
			cout << "Error of the opening File!" << endl;
		}
		else
		{
			while(!pf.eof())
			{
				pf >> tmp; 
				arr.push_back(tmp);
			}
		}
		pf.close();
	}
};


class Get_Data_by_Http : public GetData
{
	void getter(string obj) override
	{
		cout << "Take data from IP" << endl;
	}
	
};


class Hash : public GetData
{
	public:
		virtual int getHash(char *obj) = 0; 
		virtual bool checkHash(char * obj, int p) = 0; 
};

class MD5 : public Hash
{
	public:
		int getHash(char * obj) override
		{
			return 1;
		}
};

class Valid_func : public Hash
{
	bool checkHash(char * obj, int hash) override
	{
		int hash_correct = getHash(obj);
		if (hash_correct == hash)
			return 1;
		else 
			return 0;
		// return GetHash(obj) == hash  
	}
};


int main(int argc, char *argv[])
{
	
}
