//Sina Lahsaee
//129948162
#include "CustomerItem.h"
#include "Item.h"
#include <iomanip>
using namespace std;

CustomerItem::CustomerItem(const std::string &m_tempstr)
{
	filled = false;
	code = 0;
	name = m_tempstr;
}

bool CustomerItem::asksFor(const Item &item) const
{
	return false;
}

bool CustomerItem::isFilled() const
{
	return filled;
}

void CustomerItem::fill(const unsigned int c)
{
	code = c;
	filled = true;
}

void CustomerItem::clear()
{
	code = 0;
	filled = false;
}

const std::string & CustomerItem::getName() const
{
	return name;// TODO: insert return statement here
}

void CustomerItem::display(std::ostream &os) const
{

	if (filled == true)
	{
		os << "+" << " [" <<right << setw(CODE_WIDTH) << setfill('0') << code << setfill(' ') << "] " <<name << endl;
	}
	else if (filled == false)
	{
		os << "-" << " [" << right << setw(CODE_WIDTH) << setfill('0') << code << setfill(' ') << "] " << name << endl;
	}
}
