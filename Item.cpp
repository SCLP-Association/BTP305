//Sina Lahsaee
//129948162

#include "Item.h"
#include "Utilities.h"
#include <iomanip>

using namespace std;
//external declarations
size_t Item::field_width = 0;

Item::Item(const std::string &m_tempstr)
{
	size_t position = 0;
	bool m = true;
	description = "no detailed description";
	name = "";
	filler = "";
	remover = "";
	code = 1;
	Utilities temp;
	
	name = temp.nextToken(m_tempstr, position, m);

	if (name.empty()) throw "no name specified";
	else if (!name.empty())
	{
		field_width = temp.getFieldWidth(); //resets the fieldwidth to the width of the name of the current object

		if (m == true)
		{
			filler = temp.nextToken(m_tempstr, position, m);
			if (filler.empty())
			{
				throw "Filler is empty";
			}
		}

		if (m == true)
		{
			remover = temp.nextToken(m_tempstr, position, m);
			if (remover.empty())
			{
				throw "Remover task is empty";
			}
		}

		if (m == true)
		{
			code = stoi(temp.nextToken(m_tempstr, position, m));
		}

		if (m == true) 
		{
			description = temp.nextToken(m_tempstr, position, m);
		}
	}
}

bool Item::empty() const
{
	return name.empty();
}

int Item::operator++(int m_code)
{
	m_code = code;// TODO: insert return statement here
	code++;
	return m_code;
	
}

unsigned int Item::getCode() const
{
	return code;
}

const std::string & Item::getName() const
{
	return name;// TODO: insert return statement here
}

const std::string & Item::getFiller() const
{
	return filler;// TODO: insert return statement here
}

const std::string & Item::getRemover() const
{
	return remover;// TODO: insert return statement here
}

void Item::display(std::ostream &os, bool full) const
{
	os << left << setw(field_width) << name;
	os << " [" << right << setw(CODE_WIDTH) << setfill('0') << code << "]" << left << setfill(' ');

	if (full == true) {
		os << "From " << left << setw(field_width) << filler;
		os << "To " << left << setw(field_width) << remover << endl;
		os << left << setw(field_width + CODE_WIDTH + 4) << ": "<< description;
	}
	os << endl;
}
