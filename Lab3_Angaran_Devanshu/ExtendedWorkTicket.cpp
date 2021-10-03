#include "ExtendedWorkTicket.h"

#include <iostream>
#include <utility>

bool ExtendedWorkTicket::getOpenValue() const
{
	return m_isOpen;
}

void ExtendedWorkTicket::SetIsOpen(bool isOpen)
{
	m_isOpen = isOpen;
}

ExtendedWorkTicket::ExtendedWorkTicket() 
{
	//GetTicketNumber();
	//GetClientId();
	//GetDate();
	//GetDescription();
	//SetTicketNumber(0);
	//	SetClientId("");
	//	SetDate(1 ,1, 2000);
	//	SetDescription("");
	SetWorkTicketNumber(0);
	SetClientID("");
	SetIssueDescription("");
	SetIsOpen(true);
}


ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen) 
{
	int Day =0;
	int Month=0;
	int Year=0;
	SetWorkTicketNumber(ticket_number);
	SetClientID(client_id);

	SetWorkDate(Day, Month, Year);
	SetIssueDescription(description);
	SetIsOpen(isOpen);
}

bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen = true)
{
	WorkTicket ticket12;

	ticket12.SetWorkTicket(ticket_number, client_id, month, day, year, description);
	/*SetIsOpen(true);*/
	const auto min_year = 2000;
	const auto max_year = 2099;
	auto valid = true; // flag for if parameters are valid

	// check numeric parameters
	if (ticket_number < 0 || year < min_year || year > max_year)
	{
		std::cout << " error";
		valid = false;
	}
	// check string parameters     
	else if (client_id.length() < 1 || description.length() < 1)
	{
		std::cout << " error";
		valid = false;
	}
	else
	{
		try
		{
			// sets the date (may throw an exception even if rules are met)
			SetWorkDate(day, month, year);
		}
		catch (_exception)
		{
			valid = false;
		std:std::cout << "\nError! Try Again Checking the paramaeters ";
		}
	}

	if (valid) // all parameters are valid
	{
		// set the workticket date         
		/*myDate = workingDate;*/

		// set atributes to parameter values
		SetWorkTicketNumber(ticket_number);
		SetClientID(client_id);
		SetIssueDescription(description) ;
	}
	// return true or false based on parameter validity
	return valid;
}

void ExtendedWorkTicket::CloseTicket()
{
	m_isOpen = false;
}

void ExtendedWorkTicket::ShowWorkTicket()
{
	WorkTicket::ShowWorkTicket();

	if(getOpenValue() == 1)
	{
		std::cout << "The Ticket Is " << getOpenValue() << ": True";
	}
	else
	{
		std::cout << "The Ticket Is " <<  getOpenValue() << ": False";
	}

	/*std::cout << "The Ticket is " << getOpenValue() << "/n";*/
}

std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& ticket)
{
	out << (WorkTicket)ticket;
	//out << "Ticket is ";

	return  out;
}
