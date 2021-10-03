#pragma once

#ifndef __WORKTICKET__
#define __WORKTICKET__
#include <string>

class WorkTicket
{
private:

	// Private Attributes of WorkTicket class.
	int m_WorkTicketNumber;
	std::string m_clientID;
	int m_workTicketDate;
	int m_workTicketDay;
	int m_workTicketMonth;
	int m_workTicketYear;
	std::string m_issueDescription;
public:

	// Default Constructor
	WorkTicket();
	// parameterized Constructor.
	WorkTicket(int WorkTicketNumber, std::string client_id, int workTicketDate, std::string issueDescription);



	// Copy Constructor.
	WorkTicket(const WorkTicket& another_ticket);
	//equality operato declaration - overload
	bool operator==(const WorkTicket another_ticket);

	// assingment operator declaration - overload
	WorkTicket operator=(const WorkTicket& new_ticket) ;
	// setter for workTicketNumber Attribute.
	void SetWorkTicketNumber(int workTicketNumber);
	// setter for client ID attribute.
	void SetClientID(const std::string& client_id);
	// setter for workTicketDate Attribute.
	void SetWorkTicketDay(int workTicketDay);
	void SetWorkTicketMonth(int workTicketMonth);
	void SetWorkTicketYear(int workTicketYear);

	// setter for issueDescription
	void SetIssueDescription(const std::string& issueDescription);

	// getter(accessors) for workTicketNumber
	int GetWorkTicketNumber();
	//getter for client id
	std::string GetClientID();
	//getter for workTicketDafte
	int GetWorkTicketDay();
	int GetWorkTicketMonth();
	int GetWorkTicketYear();
	//friend function for both output and input (isstream and ostream) declared
	friend std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket_info);
	friend std::istream& operator>>(std::istream& in, WorkTicket& ticket_info);

	// getter for issue_Description
	std::string GetIssueDescrption();
	// declaration of which converts object to a string
	std::string ToString() const;

	// Mutator method to set all the attributes -- SetWorkTicket();
	void SetWorkTicket(int WorkTicketNumber, std::string clientID, int workTicketDay, int workTicketMonth,
	                         int workTicketYear, std::string
	                         issueDescription);
	//Mutator method to show all attributes -- ShowWorkTicket();
	virtual void ShowWorkTicket();

};

#endif


