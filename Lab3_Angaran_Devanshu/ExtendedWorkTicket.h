// Inherited class  ExtendedWorkTicket from the base class WorkTicekt.
#pragma once
#include "WorkTicket.h"
// inherteD class
class ExtendedWorkTicket :
    public WorkTicket
{
// private members
private:
	// m_isOpen with a bool has been declared here 
	bool m_isOpen;
// public members
public:
	
	// declaration of the accessor IsOpen.
	bool getIsOpen() const;
	void SetIsOpen(bool isOpen);
	ExtendedWorkTicket();


	ExtendedWorkTicket(const int ticket_number, const std::string& client_id, const int month,
	                   const int day, const int year, const std::string& description, bool isOpen);

	bool SetWorkTicket(const int ticket_number, const std::string & client_id, const int month, const int day, const int year, const std::string & description, bool isOpen);

	//void ShowWorkTicket() const override;
	void CloseTicket();
	void ShowWorkTicket() override;

	friend std::ostream& operator<<(std::ostream & out, const ExtendedWorkTicket & ticket);


};


