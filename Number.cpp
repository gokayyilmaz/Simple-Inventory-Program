/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Gokay Yilmaz		
 * Date			:	13.12.2018
 * Description	:	Number Class Implementation
 * ******************************************************/


#include "Number.h"
using namespace std;

Number::Number()
{
	r=0;
	d=0;
	w=0;
}

// Standart get and set member functions (Start)

int Number::getr()
{
	return r;
}

int Number::getd()
{
	return d;
}

int Number::getw()
{
	return w;
}

void Number::setr(int new_r)
{
	r = new_r;
}

void Number::setd(int new_d)
{
	d = new_d;
}

void Number::setw(int new_w)
{
	w = new_w;
}

// Standart get and set member functions (End)


// A member function for counting product numbers of different product types (Start)

void Number::rdw_numbers()
{
	string line;
	ifstream file("input.txt");
	if(file.is_open())
    {
    	getline(file, line);                 // Counting lines is used for calculating different product type numbers.
    	if(line=="Refrigerator")
    	{
    		getline(file, line);
    		while(line!="Dishwasher")
    		{
    			r+=1;                        // Refrigerator type products number is calculated.
    			getline(file, line);
			}
			getline(file, line);
			while(line!="WashingMachine")
			{
				d+=1;                        // Dishwasher type products number is calculated.
				getline(file, line);
			}
			getline(file, line);
			string temp;
			while(line != temp)
			{
				temp = line;
				w+=1;                        // Washing machine type products number is calculated. 
				getline(file,line);
			}
		}	
    }
}

// A member function for counting product numbers of different product types (End)
