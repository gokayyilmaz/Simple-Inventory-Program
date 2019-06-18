/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Gokay Yilmaz		
 * Date			:	13.12.2018
 * Description	:	Modes Class Interface
 * ******************************************************/

#ifndef MODES_H
#define MODES_H
#include "Number.h" // Necesary header file is included.
using namespace std;

class Modes
{
	public:
		Modes(Number &);         // Composition is used for taking product type numbers from "Number" class.
		void make_vectors();     // Member function for creating vectors for different product types.
		void lister();           // Member function for listing the products.
		void adder();            // Member function for adding new product.
		void changer();          // Member function for changing a product's available number in inventory.
		void saver();            // Member function for saving changes to the "input.txt" file.
		void handbook();         // Member function for viewing abbreviations used in the software.
		
	private:
		vector<string>refspecs;  // A vector data member for storing refrigerators' details.
		vector<string>dishspecs; // A vector data member for storing dishwashers' details.
		vector<string>washspecs; // A vector data member for storing washing machines' details.
		Number n;                // A Number data member for using Number class' objects.
};

#endif
