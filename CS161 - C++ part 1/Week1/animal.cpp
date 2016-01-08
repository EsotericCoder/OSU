/********************************************************************************Author: William Kim
*Date:6/26/2015
*Description: this program askes what your favorite animal is and outputs your  *             resonse.
*******************************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;
} 
