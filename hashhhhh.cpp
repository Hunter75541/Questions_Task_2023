#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class GetData
{
	protected:
		string arr;
	public:
		virtual void getter(string obj) = 0;
		virtual void setter() = 0;
		GetData() {}
		GetData(string arr)
		{
			this -> arr = arr;
		}
};


class Get_Data_by_File : public GetData
{
	public:
	void getter(string obj) override
	{
		arr = "":
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
				arr += tmp;
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
		bool checkHash(char * obj, int hash) override
		{
			int hash_correct = getHash(obj);
			if (hash_correct == hash)
				return 1;
			else 
				return 0;
			// return getHash(obj) == hash  
		}
};


int main(int argc, char *argv[])
{
	
}
