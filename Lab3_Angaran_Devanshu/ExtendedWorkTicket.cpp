//Include ExtendedWorkTicket.h file
#include "ExtendedWorkTicket.h"

#include <iostream>
#include <utility>
//Getter for ExtendedWorkTicket class to getIsOpen
bool ExtendedWorkTicket::getIsOpen() const
{
	//Return isOpen value
	return m_isOpen;
}
//Setter(Mutator) for IsOpen 
void ExtendedWorkTicket::SetIsOpen(bool isOpen)
{
	// setting isOpen Value 
	m_isOpen = isOpen;
}
// Default construtor of derived class
ExtendedWorkTicket::ExtendedWorkTicket() 
{

		// initialization
	SetWorkTicketNumber(0);
	SetClientID("");
	SetWorkDate(1, 1, 2020);
	SetIssueDescription("");
	SetIsOpen(true);
}

// Parameterized constructor.
ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen) : WorkTicket(ticket_number,client_id,day,month,year,description)
{
	////Variable for Day

	SetWorkTicketNumber(ticket_number);
	//SetClientID
	SetClientID(client_id);
	//SetWorkDate
	SetWorkDate(day, month, year);
	//SetIssueDescription
	SetIssueDescription(description);
	//SetIsOpen
	SetIsOpen(isOpen);
}

// overlading of SetWorkTicket() method 
bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen = true)
{
	// base class and the object has been declared/
	WorkTicket ticket12;
	// call of the base class version to set all the attributes
	ticket12.SetWorkTicket(ticket_number, client_id, month, day, year, description);
	/*SetIsOpen(true);*/
	//set min_year to 2000
	const auto min_year = 2000;
	//Set max_year to 2099
	const auto max_year = 2099;
	auto valid = true; // flag for if parameters are valid

	// check numeric parameters
	if (ticket_number < 0 || year < min_year || year > max_year)
	{
		//output to the console "error"
		std::cout << " error";
		//set valid to false
		valid = false;
	}
	// check string parameters     
	else if (client_id.length() < 1 || description.length() < 1)
	{

		//set valid to false
		valid = false;
	}
	//else enter try and catch
	else
	{
		try
		{
			// sets the date (may throw an exception even if rules are met)
			SetWorkDate(day, month, year);
		}
		catch (_exception)
		{
			//Set Valid variable to false
			valid = false;
			//Output to the user "Error Try Again Checking the parameters"
		std::cout << "\nError! Try Again Checking the paramaeters ";
		}
	}

	if (valid) // if all parameters are valid
	{
		

		// set atributes to parameter values
		SetWorkTicketNumber(ticket_number);
		SetClientID(client_id);
		SetWorkDate(day, month, year);
		SetIssueDescription(description) ;
	}
	// return true or false based on parameter validity
	return valid;
}

// Mutator for CloseTicket() which makes ticket open to closed.
void ExtendedWorkTicket::CloseTicket()
{
	//Set m_isOpen to false
	m_isOpen = false;
}
// overrided show Work Ticket to display the  ingherited attributes and ticket open or closed part.
void ExtendedWorkTicket::ShowWorkTicket()
{
	// calling the base class version of ShowWorkTicket()
	WorkTicket::ShowWorkTicket();
	// to display ticket is open or not. if Accesor isOpen Returns 1 display then open  if not then closed.
	//The Ticket is OPEN
	if(getIsOpen() == 1)
	{
		std::cout << "The Ticket Is " << getIsOpen() << ": OPEN";
	}
	//else print The Ticket is Closed
	else
	{
		std::cout << "The Ticket Is " <<  getIsOpen() << ": CLOSED";
	}
}


//Ostream operatir being overloaded to display all the objects attributes on the console,
std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& ticket)
{
	
	// calling the base class versiobn
	out << (WorkTicket)ticket;
	//  calling the accesor to display ticket open or closed
	ticket.getIsOpen();


	
	//If ticket.getIsOpen(returns true value) is equaled to true the print "Ticket: OPEN"
	if (ticket.getIsOpen() == true)
	{
		out << "Ticket"  << ": OPEN";
	}
	//else print The Ticket : CLOSED
	else
	{
		std::cout << "The Ticket" << ": CLOSED";
	}
	//return out		
	return  out;
}
