//Sina Lahsaee
//129948162

#include "Utilities.h"
using namespace std;

//external decleration
char Utilities::delimiter = '\0';
ofstream Utilities::logFile;

Utilities::Utilities()
{
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fw)
{
	this->field_width = fw;
}

size_t Utilities::getFieldWidth() const
{
	return this->field_width;
}

const std::string Utilities::nextToken(const std::string & str, size_t & next_pos, bool & more)
{
	size_t tok_size =0;
	size_t tok_endpos = 0;
	string m_str;
	size_t spaces = 0;

	tok_endpos = str.find(delimiter, next_pos); //finds the end position of the first token and stores it into tok_endpos
	size_t tok_pos = tok_endpos - next_pos; //stores the position of the next token to be extracted
	m_str = str.substr(next_pos, tok_pos); //stores the first token into the variable m_str

	next_pos = tok_endpos + 1; //increments next_pos to the begining of the NEXT token

	tok_size = m_str.length(); //stores the size of the token

	if (tok_endpos != string::npos) more = true;
	else if (tok_endpos == string::npos) more = false;

	//removal of whitespaces
	spaces =  m_str.find_first_not_of(' ');  
	
	m_str.erase(0, spaces); //removes whitespace from position 0-->spaces

	spaces = m_str.find_last_not_of(' ');;
	//End removal of whitespaces

	if (string::npos != spaces) m_str.erase(spaces + 1);


	if (this->field_width < tok_size) 
	{
		field_width = tok_size;
	};
	
	return m_str;
}

void Utilities::setDelimiter(const char temp_char)
{
	delimiter = temp_char;
}

void Utilities::setLogFile(const char *f_name)
{
	logFile.open(f_name);
}

std::ofstream & Utilities::getLogFile()
{
	return logFile;// TODO: insert return statement here
}

