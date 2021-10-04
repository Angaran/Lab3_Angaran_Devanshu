//STUDENT 1 Name: Devanshu Dave
//STUDENT 1 Student ID: 100785733
//Student 2 Name: Angaran Yogeswaran
//Student 2 Student ID: 100754161
//include iostream for outputting
#include <iostream>
//Include ExtendWorkTicket.H class
#include "ExtendedWorkTicket.h"
int main()
{
	
	/* FIX THIS BY IMPLEMENTING A WORKING ExtendedWOrkTicket Class*/
	ExtendedWorkTicket testTicket1;
	ExtendedWorkTicket testTicket2(1, "MACDONALD-001", 10, 3, 2012, "Pasword Reset", true);
	std::cout << std::endl << "As Initialized: " << std::endl;
	//Calling ShowWorkTicket on testTicket1 so we are checking if getOpenValue is set to 1 or 0 that way we print out The Ticket is open or closed
	testTicket1.ShowWorkTicket();
	//Calling ShowWorkTicket on testTicket2 so we are checking if getOpenValue is set to 1 or 0 that way we print out The Ticket is open or closed
	testTicket2.ShowWorkTicket();
	// calling the setwork ticket of derived class with testicket1 if any error value goes in it will say the error message and no changes will be made
	if (!testTicket1.SetWorkTicket(1, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl;
	// calling the setwork ticket of derived class with testicket2 if any error value goes in it will say the error message and no changes will be made

	if (!testTicket2.SetWorkTicket(1, "BLAGO-042", 3, 2, 3011, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;

	//Output if testTicket2 is OPEN or CLOSED
	std::cout << std::endl << "\n\nTicket 2: " << testTicket2 << std::endl;
	//Close TestTicket2 so set isOpen Attribute to False
	testTicket2.CloseTicket();
	//Output Ticket 2 closed
	std::cout << std::endl << "After Ticket 2 closed: " << testTicket2 << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}


