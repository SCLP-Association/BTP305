//Sina Lahsaee
//129948162
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"
#include <vector>
#include <iomanip>

using namespace std;
//external declarations
size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string &temp_order)
{
	nOrders = 0;
	order = nullptr;
	name = "";
	product = "";
	Utilities temp;
	size_t position = 0;
	bool m = true;
	vector<string> contain;
	string st_temp = "";

	temp.setFieldWidth(field_width); //sets utilities objects field width

	name = temp.nextToken(temp_order, position, m);//removes first token and equates puts it into name variable.

	if (name.empty() == true) throw string("No name found");
	else if (name.empty() == false)
	{
		if (m == true)
		{
			product = temp.nextToken(temp_order, position, m);
		}
		if (product.empty() == true) throw string("No product found");



		while (m == true)
		{
			st_temp = temp.nextToken(temp_order,position,m); //Extracts token and places into st_temp (a temporary string)
			
			if (st_temp.size() > 0)
			{
				contain.push_back(st_temp); //places strings into STL container
			}
		}
		nOrders = contain.size(); //counts the size of the countainer
		order = new CustomerItem[nOrders]; //creates a new dynamic array of type CustomerItem with the size nOrders
		
		
		for (int j = 0; j < nOrders; j++)
		{
			order[j] = CustomerItem(contain[j]); //places
		}

		if (temp.getFieldWidth() > field_width)  // extracts the field width from the Utilities object and updates the field_width class variable if that field width is greater than the class variable's current value. 
		{
			field_width = temp.getFieldWidth(); 
		}
	}
}


CustomerOrder::CustomerOrder(const CustomerOrder &src)
{
	throw string("The Copy Constructor Should Never Be Called");
}

CustomerOrder::CustomerOrder(CustomerOrder&&src) noexcept
{
	*this = move(src);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&&src) noexcept
{
	if (this != &src)
	{
		
		//moving everything from src object to their respective variables
		order = src.order;
		name = src.name;
		product = src.product;
		nOrders = src.nOrders;
		field_width = src.field_width;
		//Clearing src object
		src.order = nullptr;
		src.name = "";
		src.product = "";
		src.nOrders = 0;
		src.field_width = 0;
	}
	return std::move(*this);
}

CustomerOrder::~CustomerOrder()
{
	delete[] order;
	order = nullptr;
}

unsigned int CustomerOrder::noOrders() const
{
	return nOrders;
}

const std::string & CustomerOrder::operator[](unsigned int i) const
{
	if (i > nOrders)
		throw string("Out of Bounds");// TODO: insert return statement here
	else
	{
		return order[i].getName();
	}
}

void CustomerOrder::fill(Item &item)
{
	for (int j = 0; j < nOrders; j++)
	{
		//searching through the Customer Order to find a matching Item in your Item list. 
		if (item.getName() == order[j].getName())
		{
			order[j].fill(item.getCode());
			item++; //increments item as requested
		}
	}
}

void CustomerOrder::remove(Item &item)
{
	for (int j = 0; j < nOrders; j++)
	{
		if (order[j].getName() == item.getName())
		{
			order[j].clear(); //clears items from order
		}
	}
}

bool CustomerOrder::empty() const
{
	return name.empty(); //returns bool value if name is empty or not
}

void CustomerOrder::display(std::ostream &os) const
{
	os << left << setw(field_width) << name << "  : ";
	os << left << setw(field_width) << product << endl;
	
	for (int j = 0; j < nOrders; j++)
	{
		order[j].display(os);
	}
}
