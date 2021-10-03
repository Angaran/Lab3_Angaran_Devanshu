#include <iostream>

#include "ExtendedWorkTicket.h"
int main()
{
	//// heading
	//std::cout << "*************************************************************************" << std::endl;
	//std::cout << "\n\t\t WORK TICKET INFORMATION." << std::endl;
	//std::cout << "\n***********************************************************************" << std::endl; //std::cout << "\n\n------------------------------------------------------" <<std::endl;
	//std::cout << "\tENTER THE WORK TICKET INFORMATION. 1" << std::endl;
	//std::cout << "----------------------------------------------------------" << std::endl; //// new objet
	//WorkTicket workTicketInformation;
	//// set work ticket called for taking input for the first and existing object
	//workTicketInformation.SetWorkTicket(WorkTicketNumber, client_id, workTicketDate, workTicketMonth, WorkTicketYear, issueDescription); //// Printing the object (ostream << overload operator)
	//std::cout << workTicketInformation;
	////heading
	//std::cout << "\n\n------------------------------------------------------" << std::endl;
	//std::cout << "\tENTER THE WORK TICKET INFORMATION. 2" << std::endl;
	//std::cout << "-----------------------------------------------------" << std::endl;
	//// next object been declared on existing object (the copy constructer also been called)
	//WorkTicket ticket = workTicketInformation;
	//// asking user to enter the info
	//std::cout << "\nEnter the information." << std::endl;
	//// enter(istream >> overal operator)
	//std::cin >> ticket;
	//// new object is equal or not check(equality operator) returs statement along with 0 and 1 to answer the question.
	//std::cout << "\nIs new Object equal to the other object ? :-- " << std::to_string(workTicketInformation == ticket); //// Assigning the existing object to another object
	//std::cout << "\n\nAssignment of one existing object to another object." << std::endl;
	//workTicketInformation = ticket;
	//// outputting the result(ostream overload operator)
	//std::cout << "\n------------------------------------------------------" << std::endl;
	//std::cout << "New Object Result: " << std::endl;
	//std::cout << ticket;
	//std::cout << "\n-----------------------------------------------------------" << std::endl;
	//// printing the result of assigned operater which the works and every thing is assigned from one to another.
	//std::cout << "\nAssigned value of one to another: Result of the first Object. After being succesfully Assigned to other object." << std::endl;
	//std::cout << workTicketInformation << std::endl;
	/* FIX THIS BY IMPLEMENTING A WORKING ExtendedWOrkTicket Class*/
	ExtendedWorkTicket testTicket1;
	ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true); std::cout << std::endl << "As Initialized: " << std::endl;
	testTicket1.ShowWorkTicket();
	testTicket2.ShowWorkTicket();
	if (!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl; std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl; if (!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl; std::cout << std::endl << "Ticket 2: " << testTicket2 << std::endl;
}

