/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Gokay Yilmaz		
 * Date			:	14.12.2018
 * Description	:	Modes Class Implementation
 * ******************************************************/

#include "Modes.h" // Necessary header file is included.
using namespace std;

Modes::Modes(Number &num) // Constructor for initializing and call "make_vectors" member function.
:n(num)
{
	make_vectors();
}


// A member function for creating vectors for different product types (Start)

void Modes::make_vectors()
{
	ifstream file("input.txt"); // File is opening for reading.
    if(file.is_open())
    {
    	int i=0;
    	string word;
    	n.rdw_numbers(); // "rdw_numbers" member function of "Number" class is created for working with product type numbers.
    
    	while(file>>word)
    	{
    		if(word!="Refrigerator" && word!="Dishwasher" && word!="WashingMachine")
        	{
        		if(i<n.getr()*13)
        		{
        			refspecs.push_back(word); // Vector for refrigerator details is created.
        			++i;
				}
				else if(i>=n.getr()*13 && i<(n.getr()+n.getd())*13)
				{
					dishspecs.push_back(word); // Vector for dishwasher details is created.
					++i;
				}
				else
				{
					washspecs.push_back(word); // Vector for washing machine details is created.
					++i;
				}		
			}
		}	
	}
}

// A member function for creating vectors for different product types (End)


// A member function for listing the products (Start)

void Modes::lister()
{
	cout << "\n**********************";                                  //
	cout << "\nWelcome to Lister Mode\n";                                // Welcome screen of Lister Mode is printed.
	cout << "**********************\n";                                  //
	
	cout << "\nREFRIGERATORS\n";                                         //
	cout << "ID\tH\tL\tW\tECC\tMT\tV\tNOD\tDP\tEP\tER\tECCAP\tNORI\n";   // Abbreviations of details of refrigerator type are printed.
	cout << "-----------------------------------------------------";     //
	cout << "-----------------------------------------------\n";         //
	
	for(int k=0; k<n.getr()*13; k++)
	{
		if(k%13==0 && k!=0)
		{
			cout << endl;
			cout << refspecs[k] << "\t";                                 // Details of refrigerators are printed.
		}
		else
			cout << refspecs[k] << "\t";
	}
	
	cout << "\n\nDISHWASHERS\n";                                         //
	cout << "ID\tH\tL\tW\tECC\tWC\tNOP\tCAP\tNOR\tEP\tER\tEWSC\tNODI\n"; // Abbreviations of details of dishwasher type are printed.
	cout << "-----------------------------------------------------";     //
	cout << "-----------------------------------------------\n";         //
	
	for(int k=0; k<n.getd()*13; k++)
	{
		if(k%13==0 && k!=0)
			cout << "\n" << dishspecs[k] << "\t";	                     // Details of dishwashers are printed.
		else
			cout << dishspecs[k] << "\t";
	}
	
	cout << "\n\nWASHING MACHINES\n";                                    //
	cout << "ID\tH\tL\tW\tECC\tWC\tNOP\tCAP\tSS\tEP\tER\tEHC\tNOWI\n";   // Abbreviations of details of washing machine type are printed.
	cout << "-----------------------------------------------------";     //
	cout << "-----------------------------------------------\n";         //
	
	for(int k=0; k<n.getw()*13; k++)
	{
		if(k%13==0 && k!=0)
			cout << "\n" << washspecs[k] << "\t";                        // Details of washing machines are printed.
		else
			cout << washspecs[k] << "\t";
	}
	cout << "\n\n\n:) Lister Mode is closing...(Successfully listed)\n";
}

// A member function for listing the products (End)


// A member function for adding new product (Start)

void Modes::adder()
{
	
	// Creating variables for getting user inputs and storing details of different product types (Start)
	
	string ref_details[13] = {"Identification Code", "Height", "Length", "Width", "Energy Consumption Class", "Minimum Temperature",
		 "Volume", "Number of Doors", "Defrost Property (T/F)", "Engine Power", "Engine Rotation", "Engine Cooling Capacity", 
		 "Number of Refrigerator in the Inventory" };
	string dish_details[13] = {"Identification Code", "Height", "Length", "Width", "Energy Consumption Class", "Water Consumption",
		 "Number of Programs", "Capacity", "Number of Racks", "Engine Power", "Engine Rotation", "Engine Water Spray Capacity", 
		 "Number of Dishwashers in the Inventory" };
	string wash_details[13] = {"Identification Code", "Height", "Length", "Width", "Energy Consumption Class", "Water Consumption",
		 "Number of Programs", "Capacity", "Squeeze Speed", "Engine Power", "Engine Rotation", " Engine Heating Capacity", 
		 "Number of Washing Machines in the Inventory" };
	string new_product_type;
	string details;
	
	// Creating variables for getting user inputs and storing details of different product types (End)
	
	cout << "\n*********************";                                   //
	cout << "\nWelcome to Adder Mode";                                   // Welcome screen of Adder Mode is printed.
	cout << "\n*********************\n\n";                               //
	
	cout << "Which product type do you want to add? " <<                 //
			"(Refrigerator, Dishwasher or WashingMachine)\n-> ";         // Getting user input for product type which is wanted to add.
	cin >> new_product_type;                                             //
	cout << endl;
	
	if(new_product_type == "Refrigerator")
	{
		for(int i=0; i<13; i++)
		{
			cout << "Please enter the refrigerator's " << ref_details[i] << " -> "; //
			cin >> details;                                                         // Getting and storing new refrigerator's details.
			refspecs.push_back(details);                                            //
		}
		n.setr(n.getr()+1);
		cout << "\n\n:) Adder Mode is closing...(Successfully added)\n";            // Successful good bye screen of Adder Mode printed.
		
	}
	else if(new_product_type == "Dishwasher")
	{
		for(int i=0; i<13; i++)
		{
			cout << "Please enter the dishwasher's " << dish_details[i] << " -> ";  //
			cin >> details;                                                         // Getting and storing new dishwasher's details.
			dishspecs.push_back(details);                                           //
		}
		n.setd(n.getd()+1);
		cout << "\n\n:) Adder Mode is closing...(Successfully added)\n";            // Successful good bye screen of Adder Mode printed.
	}
	else if(new_product_type == "WashingMachine")
	{
		for(int i=0; i<13; i++)
		{
			cout << "Please enter the washing machine's " << wash_details[i] << " -> "; //
			cin >> details;                                                             // Getting and storing new washing machine's details.
			washspecs.push_back(details);                                               //
		}
		n.setw(n.getw()+1);
		cout << "\n\n:) Adder Mode is closing...(Successfully added)\n";            // Successful good bye screen of Adder Mode printed.
	}
	else
		cout << ":( Adder Mode is closing...(You entered wrong product type)\n";    // Unsuccessful good bye screen of Adder Mode printed.
}

// A member function for adding new product (End)


// A member function for changing a product's available number in inventory (Start)

void Modes::changer()
{
	
	// Creating variables for getting user inputs (Start)
	
	vector<string>change_id;
	string change_product;
	string id;
	string new_nopi;
	
	// Creating variables for getting user inputs (End)
	
	cout << "\n***********************\n";                                                 //
	cout << "Welcome to Changer Mode\n";                                                   // Welcome screen of Changer Mode is printed.
	cout << "***********************\n\n";                                                 //
	
	cout << "Which product type do you want to change its available number in inventory?"  // Getting user input for
		<< " (Refrigerator, Dishwasher or WashingMachine)\n-> ";                           // product type which is wanted to change
	cin >> change_product;                                                                 // its available number in inventory
	
	if(change_product == "Refrigerator")
	{
		if(n.getr() == 0)
		{
			cout << "\nThere are not any refrigerator models in our inventory.\n";  // Checking if there is any refrigerator.
			cout << "\n:( Changer mode is closing. (No refrigerator)\n";            // Unsuccessful good bye screen of Changer Mode is printed.
		}
		
		else
		{
			if(n.getr() == 1)
				cout << "\nThere is " << n.getr() << " refrigerator model in our inventory: \n";             // Numbers of refrigetors
			else                                                                                             // available in inventory
				cout << "\nThere are " << n.getr() << " different refrigerator models in our inventory: \n"; // is printed.
				  
		for(int i=0; i<n.getr()*13;i++)
		{
			if(i%13 == 0)
			{
				cout << refspecs[i] << endl;       // Refrigerators' IDs are listed.
				change_id.push_back(refspecs[i]);
			}		
		}
		
			if(n.getr() == 1)
			{
				cout << "\nEnter the refrigerator's ID code if you want to change its available number in inverntory?\n-> ";
				cin >> id; // Getting ID code of refrigerator which is wanted to change its available number in inventory.
			}
			else
			{
				cout <<	"\nWhich refrigerator do you want to change its available number in inventory?\n-> ";
				cin >> id; // Getting ID code of refrigerator which is wanted to change its available number in inventory.
			}
		
		for(int k=0; k<n.getr(); k++)
		{
			if(change_id[k] == id)
			{
				cout << "\nPlease enter the new available number in inventory of " << change_id[k] << ":\n-> ";
				cin >> new_nopi;                    // Getting and storing new
				refspecs[k+(12*(k+1))] = new_nopi;  // available number in inventory.
			}
		}
		cout << "\n:) Changer Mode is closing...(Successfully changed)\n"; // Successfull good bye screen of Changer Mode is printed.
		}
	}
	else if(change_product == "Dishwasher")
	{
		if(n.getd() == 0)
		{
			cout << "\nThere are not any dishwasher models in our inventory.\n"; // Checking if there is any dishwasher.
			cout << "\n:( Changer mode is closing. (No dishwasher)\n";           // Unsuccessful good bye screen of Changer Mode is printed.
		}
		else
		{
			if(n.getd() == 1)
				cout << "\nThere is " << n.getd() << " dishwasher model in our inventory: \n";             // Numbers of dishwashers
			else                                                                                           // available in inventory
				cout << "\nThere are " << n.getr() << " different dishwasher models in our inventory: \n"; // is printed.
				  
		for(int i=0; i<n.getd()*13;i++)
		{
			if(i%13 == 0)
			{
				cout << dishspecs[i] << endl;      // Dishwashers' IDs are listed.
				change_id.push_back(dishspecs[i]);
			}			
		}
		
			if(n.getd() == 1)
			{
				cout << "\nEnter the dishwasher's ID code if you want to change its available number in inverntory?\n-> ";
				cin >> id; // Getting ID code of dishwasher which is wanted to change its available number in inventory.
			}
			else
			{
				cout <<	"\nWhich dishwasher do you want to change its available number in inventory?\n-> ";
				cin >> id; // Getting ID code of dishwasher which is wanted to change its available number in inventory.
			}
		
		for(int k=0; k<n.getd(); k++)
		{
			if(change_id[k] == id)
			{
				cout << "\nPlease enter the new available number in inventory of " << change_id[k] << ":\n-> ";
				cin >> new_nopi;                    // Getting and storing new
				dishspecs[k+(12*(k+1))] = new_nopi; // available number in inventory. 
			}
		}
		cout << "\n:) Changer Mode is closing...(Successfully changed)\n"; // Successfull good bye screen of Changer Mode is printed.
		}
	}
	else if(change_product == "WashingMachine")
	{
		if(n.getw() == 0)
		{
			cout << "\nThere are not any washing machine models in our inventory.\n"; // Checking if there is any washing machine.
			cout << "\n:( Changer mode is closing. (No washing machine)\n";           // Unsuccessful good bye screen of Changer Mode is printed.
		}
		else
		{
			if(n.getw() == 1)
				cout << "\nThere is " << n.getw() << " washing machine model in our inventory: \n";             // Numbers of washing machines
			else                                                                                                // available in inventory
				cout << "\nThere are " << n.getr() << " different washing machine models in our inventory: \n"; // is printed.
				
		for(int i=0; i<n.getw()*13;i++)
		{
			if(i%13 == 0)
			{
				cout << washspecs[i] << endl;      // Washing machines' IDs are listed.
				change_id.push_back(washspecs[i]); 
			}		
		}
		
			if(n.getw() == 1)
			{
				cout << "\nEnter the washing machine's ID code if you want to change its available number in inverntory?\n-> ";
				cin >> id; // Getting ID code of washing machine which is wanted to change its available number in inventory.
			}
			else
			{
				cout <<	"\nWhich refrigerator do you want to change its available number in inventory?\n-> ";
				cin >> id; // Getting ID code of washing machine which is wanted to change its available number in inventory.
			}
		
		for(int k=0; k<n.getw(); k++)
		{
			if(change_id[k] == id)
			{
				cout << "\nPlease enter the new available number in inventory of " << change_id[k] << ":\n-> ";
				cin >> new_nopi;                     // Getting and storing new
				washspecs[k+(12*(k+1))] = new_nopi;  // available number in inventory.
			}
		}
		cout << "\n:) Changer Mode is closing...(Successfully changed)" << endl; // Successfull good bye screen of Changer Mode is printed.
		}
	}
	else                                                                                   // Unsuccessful good bye screen
		cout << "\n:( Changer Mode is closing...(You entered wrong product type)" << endl; // of Changer Mode is printed.
}

// A member function for changing a product's available number in inventory (End)


// A member function for saving changes to the "input.txt" file (Start)

void Modes::saver()
{
	cout << "\n*********************";    //
	cout << "\nWelcome to Saver Mode\n";  // Welcome screen of Saver Mode is printed.
	cout << "*********************\n";    //
	
	ofstream myfile;                      // File is opening for writing.
  	myfile.open("input.txt");
  	
  	// New input file which is created by user is saving to input.txt (Start)
  	
  	myfile << "Refrigerator" << endl;
  	for(int k=0; k<n.getr()*13; k++)
	{
		if(k%13==0 && k!=0)
		{
			myfile << endl;
			myfile << refspecs[k] << " ";
		}
		else
			myfile << refspecs[k] << " ";
	}
	
	myfile << "\nDishwasher" << endl;
  	for(int k=0; k<n.getd()*13; k++)
	{
		if(k%13==0 && k!=0)
		{
			myfile << endl;
			myfile << dishspecs[k] << " ";	
		}
		else
			myfile << dishspecs[k] << " ";
	}
	
	myfile << "\nWashingMachine" << endl;
  	for(int k=0; k<n.getw()*13; k++)
	{
		if(k%13==0 && k!=0)
		{
			myfile << endl;
			myfile << washspecs[k] << " ";
		}
		else
			myfile << washspecs[k] << " ";
	}
	
	// New input file which is created by user is saving to input.txt (End)
	
	cout << "\n:) Saver Mode is closing...(Successfully saved)\n"; // Successful good bye screen of Saver Mode is printed.
  	myfile.close(); // File is closed.
}

// A member function for saving changes to the "input.txt" file (End)


// A member function for viewing abbreviations used in the software (Start)

void Modes::handbook()
{
	cout << "\n************************";   //
	cout << "\nWelcome to Handbook Mode\n"; // Welcome screen of Handbook Mode is printed.
	cout << "************************\n\n"; //
	
	// Abbreviations for details used in this software are printed (Start)
	
	cout << "Abbreviations used in this software: \n\n";
	
	cout << "ID   : Identification Code\nH    : Height\nL    : Length\nW    : Width\nECC  : Energy Consumption Class\n" << 
		"MT   : Minimum Temperature\nV    : Volume\nNOD  : Number of Doors\nDP   : Defrost Property\nEP   : Engine Power\n" 
		<< "ER   : Engine Rotation\nECCAP: Engine Cooling Capacity\nNORI : Number of Refrigerator in the Inventory\n" << 
		"WC   : Water Consumption\nNOP  : Number of Programs\nCAP  : Capacity\nNOR  : Number of Racks\n" << 
		"EWSC : Engine Water Spray Capacity\nNODI : Number of Dishwashers in the Inventory\nSS   : Squeeze Speed\n" 
		<< "EHC  : Engine Heating Capacity\nNOWI : Number of Washing Machines in the Inventory\n\n";
		
	// Abbreviations for details used in this software are printed (End)
	
	cout << ":) Handbook Mode is closing...(Successfully viewed)\n"; // Successful good bye screen of Handbook Mode is printed.
}

// A member function for viewing abbreviations used in the software (End)


