//Sina Lahsaee
//129948162
//File includes
#include "OrderManager.h"
#include "ItemManager.h"
#include "CustomerOrder.h"
//include libraries
#include <algorithm>
using namespace std;
CustomerOrder && OrderManager::extract()
{
	CustomerOrder temp = move(this->back()); //moves customer order from the back of the STL container
	return move(temp); //returns the moved order that we stored inside temp.
}

void OrderManager::validate(const ItemManager &itemManager, std::ostream &os)
{
	vector<CustomerOrder>::const_iterator counter;
	int cnt = 0;

	for (counter = begin(); counter != end(); counter++)
	{
		for (cnt = 0; cnt < counter->noOrders(); cnt++)
		{
			

			auto request = [&](const Item& temp) //lambda function that returns a reference to Item
			{
				return temp.getName() == (*counter)[cnt];
			};

			if (find_if(itemManager.begin(), itemManager.cend(), request) == itemManager.cend())
			{
				os << (*counter)[cnt] << " is unavailable" << endl;
			}
		}
	}
}

void OrderManager::display(std::ostream &os) const //outputs description of customer order
{
	for (auto& temp : *this) temp.display(os);
}
