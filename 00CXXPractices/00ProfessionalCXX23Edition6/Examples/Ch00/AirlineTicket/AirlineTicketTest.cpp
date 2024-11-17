import <iostream>;
import airline_ticket;
#include <iostream>
#include <string>



int main()
{
	AirlineTicket myTicket;  // Stack-based AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost{ myTicket.calculatePriceInDollars() };
	std::cout << "This ticket will cost $" << cost << std::endl;

	return 0;
} 
