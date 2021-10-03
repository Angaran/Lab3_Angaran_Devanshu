#include "ExtendedWorkTicket.h"

ExtendedWorkTicket::ExtendedWorkTicket() : WorkTicket()
{
	//GetTicketNumber();
	//GetClientId();
	//GetDate();
	//GetDescription();
	//SetTicketNumber(0);
	//	SetClientId("");
	//	SetDate(1 ,1, 2000);
	//	SetDescription("");
	SetWorkTicketNumber(5);
	SetClientID("");
	SetIssueDescription("");
	m_isOpen = true;
}

ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen)
{
	SetWorkTicketNumber(ticket_number);
	SetClientID(client_id);
	SetWorkTicketDay(day);
	SetWorkTicketMonth(month);
	SetWorkTicketYear(year);
	m_isOpen = isOpen;
}

bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	const int day, const int year, const std::string& description, bool isOpen)
{
	WorkTicket ticket12;

	ticket12.SetWorkTicket(ticket_number, client_id, month, day, year, description);
	isOpen = true;

	return  true;
}

void ExtendedWorkTicket::CloseTicket()
{
	m_isOpen = false;
}

void ExtendedWorkTicket::ShowWorkTicket()
{
	WorkTicket::ShowWorkTicket();
}

std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& ticket)
{
	out << (WorkTicket)ticket;
	//out << "Ticket is ";

	return  out;
}
