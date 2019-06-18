/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Gokay Yilmaz		
 * Date			:	13.12.2018
 * Description	:	Number Class Interface
 * ******************************************************/


#ifndef NUMBER_H
#define NUMBER_H
#include <iostream> //
#include <fstream>  // Necessary libraries are included.
#include <vector>   //

class Number                // A class for calculating and storing different product type numbers.
{
	public:
		Number();
		void rdw_numbers(); // Member function for counting product numbers of different product types.
		
		int getr();         //
		int getd();         // "get" member functions for getting product type numbers from another class.
		int getw();         //
		
		void setr(int);     //
		void setd(int);     // "set" member functions for setting product type numbers from another class.
		void setw(int);     //
	private:
		int r;              //
		int d;              // data members for storing numbers of different product types.
		int w;              //
};

#endif
