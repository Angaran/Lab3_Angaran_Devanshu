// including files
#include "WorkTicket.h"

#include <iostream>
#include <sstream>
#include <string>


// default constructor
WorkTicket::WorkTicket()
{

	//This is default inialization
	SetWorkTicketNumber(m_WorkTicketNumber);
	SetClientID(m_clientID);
	SetWorkTicketDay(m_workTicketDay);
	SetWorkTicketMonth(m_workTicketMonth);
	SetWorkTicketYear(m_workTicketYear);
	SetIssueDescription(m_issueDescription);
}


// parametirized constructor
WorkTicket::WorkTicket(int WorkTicketNumber, std::string client_id, int workTicketDate, std::string issueDescription)
{

	// initialization
	m_WorkTicketNumber = WorkTicketNumber;
	m_clientID = client_id;
	m_workTicketDate = workTicketDate;
	m_issueDescription = issueDescription;
	SetWorkTicketNumber(WorkTicketNumber);
}

// copy constructor defination
WorkTicket::WorkTicket(const WorkTicket& another_ticket)
{

	
	m_WorkTicketNumber = another_ticket.m_WorkTicketNumber;
	m_clientID = another_ticket.m_clientID;
	m_workTicketDay = another_ticket.m_workTicketDay;
	m_workTicketMonth = another_ticket.m_workTicketMonth;
	m_workTicketYear = another_ticket.m_workTicketYear;
	m_issueDescription = another_ticket.m_issueDescription;
	std::cout << "\n Work Ticket object was copied \n";
}

/* equaity operator defination
 * check iif one object is equal to another
 */
bool WorkTicket::operator==(const WorkTicket another_ticket)
{
	// if equal then return true
	if(m_WorkTicketNumber == another_ticket.m_WorkTicketNumber && m_workTicketDay == another_ticket.m_workTicketDay && m_workTicketMonth == another_ticket.m_workTicketMonth
		 && m_workTicketYear == another_ticket.m_workTicketYear && m_clientID == another_ticket.m_clientID && m_issueDescription == another_ticket.m_issueDescription)
	{
		std::cout << "\nBoth objects are same. \nAll attributes are same. " <<std::endl;
		return true;
	}
	// else return false with statement
	else
	{
		std::cout << "\nBoth objects are not same.\n All attributes not same. " << std::endl;

		return false;
	}
}
/*
 * Assignment operator defination
 */
WorkTicket WorkTicket::operator=(const WorkTicket& new_ticket)
{
	SetWorkTicketNumber(new_ticket.m_WorkTicketNumber);
	SetWorkTicketDay(new_ticket.m_workTicketDay);
	SetWorkTicketMonth(new_ticket.m_workTicketMonth);
	SetWorkTicketYear(new_ticket.m_workTicketYear);
	SetClientID(new_ticket.m_clientID);
	SetIssueDescription(new_ticket.m_issueDescription);

	std::cout  <<"\n" "Work Ticket Objects were assigned";

	return *this;
}

//Setter(Mutator) for Work Ticket Number
void WorkTicket::SetWorkTicketNumber(int WorkTicketNumber)
{
	m_WorkTicketNumber = WorkTicketNumber;
}
//Setter(Mutator) for client ID
void WorkTicket::SetClientID(const std::string& client_id)
{
	m_clientID = client_id;
}
//Setter(Mutator) for WorkTicketDate
void WorkTicket::SetWorkTicketDay(int workTicketDay)
{
	m_workTicketDay = workTicketDay;
}
//Setter(Mutator) for Work Ticket Month
void WorkTicket::SetWorkTicketMonth(int workTicketMonth)
{
	m_workTicketMonth = workTicketMonth;
}
//Setter(Mutator) for Work Ticket Year
void WorkTicket::SetWorkTicketYear(int workTicketYear)
{
	m_workTicketYear = workTicketYear;
}

//Setter(Mutator) for Issue Description
void WorkTicket::SetIssueDescription(const std::string& issueDescription)
{
	m_issueDescription = issueDescription;
}
//Getter for WorkTicketNumber
int WorkTicket::GetWorkTicketNumber()
{
	return m_WorkTicketNumber;
}
//Getter for ClientID
std::string WorkTicket::GetClientID()
{
	return m_clientID;
}
//Getter for TicketDate
int WorkTicket::GetWorkTicketDay()
{
	return m_workTicketDay;
}
//Getter for Ticket Month
int WorkTicket::GetWorkTicketMonth()
{
	return m_workTicketMonth;
}
//Getter for Ticket Year
int WorkTicket::GetWorkTicketYear()
{
	return m_workTicketYear;
}

//Getter for Issue Description
std::string WorkTicket::GetIssueDescrption()
{
	return m_issueDescription;
}
/** ToString Method
 *This Method is to converting an object to a string and return an converted string.
*/
//ToString Method
std::string WorkTicket::ToString() const
{
	// declaration of stringstream object as output
	std::stringstream output;
	// string 
	output << "\nWorkTicket Number # " << m_WorkTicketNumber << " - " << m_clientID << "(" << m_workTicketDay << "/" << m_workTicketMonth << "/" << m_workTicketYear << "):" << m_issueDescription;
	// return the string
	return output.str();
}

//This is a setter for SetWorkTicket which means this is a mutator.
void WorkTicket::SetWorkTicket(int WorkTicketNumber, std::string clientID, int workTicketDay, int workTicketMonth,
                                     int workTicketYear, std::string issueDescription)
{
	// int data type named as inputValid variable used for validation
	int inputValid;
	// object defination
	WorkTicket destination;
	//Prompt user to Enter your work ticket number
	std::cout << "\nEnter Your Work Ticket Number: ";
	//do while loop where we asked user for input for the work ticket number as well as stored the value in variable WorkTicketNumber
	do
	{	//Input Valid Variable to enter loops
		inputValid = 1;
		
		//Taking input for WorkTicketNumber
		std::cin >>  WorkTicketNumber;

		//if validation fails then enter this IF statement
		
		if ( std::cin.fail())
		{
			//Output to the user "Work TIcket must be a numeric number""
			std::cout << "\nWork Ticket Number must be a numeric number. Please Try Again:- ";
			//clear input and ignore input
			std::cin.clear();
			std::cin.ignore(156,'\n');

			inputValid = 0;

		}
		//else if the workTicket number is less than or equal to 0 output to the user your ticket number should not be zero
		else if (WorkTicketNumber <= 0)
		{
			//Output to the user Your Ticker Number should not be zero
			std::cout << "Your ticket number should not be zero or less than zero: ";
			inputValid = 0;
		}
		//else set WorldTicketNumber to m_worldTicketNumber
		else
		{
			m_WorkTicketNumber = WorkTicketNumber;
			destination.SetWorkTicketNumber(WorkTicketNumber);
			//Output The ticket number that has been stored
			std::cout << "The Ticket number has been stored  which was - " << GetWorkTicketNumber() << std::endl;

		}
	} while (inputValid != 1);

	// do while loop for the validation for the work ticket date
	do
	{
		//Ask the usewr for the work ticket date in days months and years.
		inputValid = 1;
		std::cout << "\nEnter your work ticket date (DAY:MONTH:YEAR)" << std::endl;
		//take the users input for each of the variables and store them in the respective variables
		std::cin >> workTicketDay >> workTicketMonth >> workTicketYear;

		//if workTicket is less and one or greater
		if (!(std::cin.fail()))
		{

			// checking if day is less than 1 or greater than 31
			if (workTicketDay < 1 || workTicketDay > 31) {
				inputValid = 0;
				//If user input is not valid then output that Day must be between 1 and 31
				std::cout << "Day must be between 1 and 31" << std::endl;

			}
			// checking for month between 1 and 12
			else if (workTicketMonth < 1 || workTicketMonth >12) {
				inputValid = 0;
				//If user input is not valid then output that Day must be between 1 and 12
				std::cout << "Month must be between 1 and 12" << std::endl;

			}
			// checking for year between 2000 and 2099
			else if (workTicketYear < 2000 || workTicketYear > 2099) {
				inputValid = 0;
				//If user input is not valid then output that Day must be between 2000 and 2099
				std::cout << "Year must be between 2000 and 2099" << std::endl;
				std::cin.clear();
			  std::cin.ignore();
			}
			// correct then set to the mutators
			else
			{
				m_workTicketDay = workTicketDay;
				m_workTicketMonth = workTicketMonth;
				m_workTicketYear = workTicketYear;

				destination.SetWorkTicketDay(workTicketDay);
				destination.SetWorkTicketMonth(workTicketMonth);
				destination.SetWorkTicketYear(workTicketYear);
				std::cin.clear();
				std::cin.ignore();
				// print the succesfull statement
				std::cout << "The Date has been stored  which was - " << GetWorkTicketDay() << "/" << GetWorkTicketMonth() << "/" << GetWorkTicketYear() << std::endl;

			}
		}
		// else if user enters the non numeric value
		else {
			// clear the input stream
			std::cin.clear();
			// validation to false
			inputValid = 0;
			std::cout << "Error! Please Try again to enter a numeric value for date.:- ";
			// ignore
			std::cin.ignore(156, '\n');
			std::cin.clear();
		}

	} while (inputValid != 1);
	//do while loop to setup input and output for the Client ID
	//do while loop for getting input and validation for client_id
	do
	{
		//Client ID being initalized
		SetClientID(m_clientID);
		//input valid variable to enter the loop
		inputValid = 1;
		//Prompting the User to enter their client ID
		std::cout << "\nEnter your client ID : ";
		//Storing the users input in the clientID variable
		std::getline(std::cin, clientID);
		//std::cin >> clientID;
		m_clientID = clientID;
		//if the clientID's length is less than 1 or empty'
		if (clientID.length() == 0 || clientID.empty())
		{
			//output to the user that the ClientID must be atleast one character
			std::cout << "The clientID  must be of one character";
			inputValid = 0;
			std::cin.clear();
			//std::cin.ignore(100,'\n');
			//std::cin.clear();
			
		}
		//else set clientID to m_clientID
		else
		{
			m_clientID = clientID;
			destination.SetClientID(clientID);
			std::cout << "The client ID has been stored has " << GetClientID() << std::endl;

		}


	} while (inputValid != 1);
	
	//do while loop for getting input and validation for description
	do
	{
		inputValid = 1;
		//Prompting user to enter their issues description
		std::cout << "\nEnter your description:- ";
		//storing their input in a variable names issueDescription
		std::getline(std::cin, issueDescription);
		//std::cin >> issueDescription;
		//If issueDescription's length is greater than 1 then store that in the m_issueDescription variable
		if (issueDescription.length() == 0)
		{
			//The description must be greater than 1
			inputValid = -1;
			std::cout << "The description must be greater than 1";
			std::cin.clear();
			std::cin.sync();
		}
		else
		{
			m_issueDescription = issueDescription;
			destination.SetIssueDescription(issueDescription);
			std::cout << "The issue description had been stored as " << GetIssueDescrption() << std::endl;
		}
		//else if issueDescription is less than one then output to the user



	} while (inputValid != 1);

}



//Show Work Ticket function 
void  WorkTicket::ShowWorkTicket()
{

	// printing cout 
	std::cout << "The work Ticket Number is " <<(GetWorkTicketNumber()) << std::endl << "The client ID is " << m_clientID << std::endl
		<< "The Work Ticket Date is " << GetWorkTicketDay() << GetWorkTicketMonth() << GetWorkTicketYear() << std::endl << "The issue Description is " << m_issueDescription << std::endl;


}

// ostream operator overload defination
std::ostream& operator<<(std::ostream& out, const WorkTicket& ticket_info)
{
	out << ticket_info.ToString();
	return  out;
}

// istream operator overload defination
std::istream& operator>>(std::istream& in, WorkTicket& ticket_info)
{
	//Ask the user to enter the work ticket number
	std::cout << "\nEnter the Work Ticket Number." << std::endl;
	// input
	std::cin >> ticket_info.m_WorkTicketNumber;
	// if input is failed then enter the while loop with non numeric number
	while(std::cin.fail())
	{
		// error message
		std::cout << "Try Again to enter an numeric number. " << std::endl;
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore(100,'\n');
		std::cin >> ticket_info.m_WorkTicketNumber;
		
	}
	//output to the user enter your work ticket date
	std::cout << "\nEnter your work ticket date (DAY:MONTH:YEAR)" << std::endl;
	//output to the user enter the day
	std::cout << "Enter the Day: " << std::endl;

	//in >> ticket_info.m_workTicketDay;
	int  input = 1;
	//if input is not equal to 0 then enter loop
	while (!(input ==0))
	{
		/*input = 0;*/
		//std::cin.clear();
		//std::cin.ignore();
		in >> ticket_info.m_workTicketDay;
		//if the user input fails the enter this statement
		if(std::cin.fail())
		{
			//The day must be a numeric number Try again 
			std::cout << "The Day must be an numeric Number:  Try Again: ";
			std::cin.clear();
			std::cin.ignore(100,'\n');

		}
		//else if the day is less than 1 and greater than 31 then enter this statement
		else if(ticket_info.m_workTicketDay < 1 || ticket_info.m_workTicketDay >31)
		{
			//output the day must be between 1 and 31 please try again
			std::cout << "Day must be between 1 or 31. Please Try Again.: ";
			std::cin.clear();
			std::cin.ignore(100,'\n');
			input = 1;


		}
		//else output to the user that the input is correct
		else
		{

			std::cout << "Correct " << std::endl;
			input = 0;

		}
		
	}
	//Ask the user to enter the month 
	std::cout << "\nEnter the Month. " << std::endl;
	input = 1;
	//if input is not equal to 0 then enter the loop
	while(!(input == 0))
	{
		// input
		in >> ticket_info.m_workTicketMonth;
		//  if user enters the non numeric value
		if(std::cin.fail())
		{
			// error message
			std::cout << " The Entered  Month must be numeric.  Please Try Again. ";
			// clear and ignore input stream
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
		// validating range
		else if( ticket_info.m_workTicketMonth < 1 || ticket_info.m_workTicketMonth > 12 )
		{
			std::cout << "Month Should be between 1 and 12. Please Try again: ";
			std::cin.clear();
			std::cin.ignore(100,'\n');

		}
		// correct input
		else
		{;
			input = 0;
		}
	}
	//Ask the user to enter a year input
	std::cout << "\nEnter the Year " << std::endl;
	input = 1;
	//if inpht is not equal to 0 then enterloop
	while(!(input == 0))
	{

		in >> ticket_info.m_workTicketYear;
		//if input fails output the entered year should enter non numeric statement
		// if user enters the non numeric value
		if(std::cin.fail())
		{
			// errr message
			std::cout << " The Entered Year should be a numeric. " << std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');

		}
		// range validation
		else if (ticket_info.m_workTicketYear < 2000 || ticket_info.m_workTicketYear > 2099)
		{
			// erro message
			std::cout << "Year Should be between 2000 and 2099";
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
		// correct input
		else
		{
			input = 0;
			std::cin.clear();
			std::cin.ignore();
			
		}
	}
	//Ask user for for the client ID
	std::cout << "\nEnter the Client ID." << std::endl;
	input = 1;
	//Enter the loop if the input variable is not eqaul to 0
	while (!(input == 0))
	{
		//in >> ticket_info.m_clientID;
		std::getline(std::cin, ticket_info.m_clientID);
		//if the client id length is less than one or the client id is empty
		if (ticket_info.m_clientID.length() == 0 || ticket_info.m_clientID.empty())
		{
			//Output the client ID must be at least one character long
			std::cout << "The client ID must be atleast one character long ";
			std::cin.clear();
			//std::cin.ignore(100,'\n');
		}
		// correct input
		else
		{
			input = 0;
			//std::cin.ignore(100,'\n');
		}
	}

	// asking to enter for issue description
	std::cout << "\nEnter the Issue Description." << std::endl;
	input = 1;
	// while loop for validation
	while (!(input == 0))
	{
		// input
		std::getline(std::cin, ticket_info.m_issueDescription );
		//checking for validation if user enters less than 1 char means 0 
		if (ticket_info.m_issueDescription.length() == 0 || ticket_info.m_issueDescription.empty())
		{
			std::cout << "The issue Description must not be less than one character or empty. Try Again. :- ";
			std::cin.clear();
			std::cin.sync();
		}
		// correct input
		else
		{
			input = 0;
		}
	}

	// return in
	return in;
}
