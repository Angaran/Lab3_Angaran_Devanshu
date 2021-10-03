#pragma once
#include "WorkTicket.h"
class ExtendedWorkTicket :
    public WorkTicket
{
private:
	bool m_isOpen;

public:
	/*bool SetIsOpen(bool isOpen);*/
	virtual ~ExtendedWorkTicket() = default;
	bool getOpenValue() const;

	ExtendedWorkTicket();

	ExtendedWorkTicket(const int ticket_number, const std::string & client_id, const int month, const int day, const int year, const std::string & description, bool isOpen);

	bool SetWorkTicket(const int ticket_number, const std::string & client_id, const int month, const int day, const int year, const std::string & description, bool isOpen);

	//void ShowWorkTicket() const override;
	void CloseTicket();
	void ShowWorkTicket() override;

	friend std::ostream& operator<<(std::ostream & out, const ExtendedWorkTicket & ticket);


};


