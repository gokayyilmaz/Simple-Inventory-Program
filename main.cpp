/* ******************************************************* 
 * Filename		:	main.cpp
 * Author		:	Gokay Yilmaz		
 * Date			:	14.12.2018
 * Description	:	Driver Program for GSIP Software
 * ******************************************************/


#include "Modes.h" // Necessary header file is included.
using namespace std; 

int main() 
{ 
	// Necessary objects and variables created (Start)
	
	Number num; // "num" object of Number class is created.
	Modes mode(num); // "mode" object of Modes class is created.
    int selected_mode; // "selected_mode" variable is created for selecting differen modes according to user input.
    string again; // "again" variable is created for going back to "Mode Select Menu" and keep going working with same or different mode.

	// Necessary objects and variables created (End)
	
    cout << "****************************************************\n";                        //
    cout << "****************************************************\n\n";                      //
    cout << " Welcome to GISP (Gokay's Simple Inventory Program)\n\n\n";                     //
    cout << "Created by Gokay YILMAZ in Eskisehir, December 2018\n\n";                       //
    cout << "Advanced Programming 2018-2019 Fall Semester Project\n";                        // Welcome screen is printed.
    cout << "\n      Project #4: A Simple Inventory Program\n";                              // Program is opened.
    cout << "\n     Supervisor: Asst. Prof. Dr. Burak KALECI\n\n";                           //
    cout << "****************************************************\n";                        //
    cout << "****************************************************\n\n\n";                    //
	
    do {
    	cout << "Please select a program mode by typing its number:\n\n";                    //
    	cout << "1 - LISTER (List all products in the inventory with their details)\n";      //
    	cout << "2 - ADDER (Add a new product)\n";                                           // Program modes are listed.
    	cout << "3 - CHANGER (Change the number of available products in the inventory)\n";  // 
    	cout << "4 - SAVER (Save the product data to file named as input.txt)\n";            //
    	cout << "5 - HANDBOOK (See the abbreviations used in this software)\n\n->";          //
		 
    	cin >> selected_mode;   // Mode is selected by user.
    	
   		switch(selected_mode) {                                                              //                                       
      		case 1 :                                                                         //
        		mode.lister();                                                               //
        		cout << endl;                                                                //
         		break;                                                                       //
      		case 2 :                                                                         //
    			mode.adder();                                                                //
    			cout << endl;                                                                // 
    			break;                                                                       //
      		case 3 :                                                                         // Related functions are called 
        		mode.changer();                                                              // according to program mode selected
        		cout << endl;                                                                // by user.
        		break;                                                                       //
      		case 4 :                                                                         //
        		mode.saver();                                                                //
        		cout << endl;                                                                //
        		break;                                                                       //
        	case 5:                                                                          //
        		mode.handbook();                                                             //
        		cout << endl;                                                                //
        		break;                                                                       //
      		default :                                                                         
         		cout << "You selected non-exist mode number\n";                              // Checking wrong inputs. 
    }
    cout << "\nDo you want to select another mode? (Yes or No)\n-> ";                        // Asking user if they want another  
    cin >> again;                                                                            // mode operation.
    
    while(again != "Yes" && again != "No")                                                   // 
    {									                                                     //
    	cout << "\n:( You entered wrong answer\n";                                           // Checking wrong inputs.
    	cout << endl << "Do you want to select another mode? (Yes or No)\n-> ";              //
    	cin >> again;                                                                        //
	}                                                                                        //
	
    cout << endl;
	} while(again == "Yes");  // Going back to "Mode Select Menu if the input is "Yes"
	
	cout << "\n*************************************************************\n";             // Good Bye screen is printed
	cout << "Gokay's Simple Inventory Program is closing. Have a good day!\n";               // if the input is "Yes
  	cout << "*************************************************************\n";               // Program is closed.
  	
    return 0; 
} 
