//Sina Lahsaee
//ID 129948162

#include <iomanip>
#include "Task.h"
#include "Utilities.h"

using namespace std;

size_t Task::field_width = 0;

Task::Task(const std::string &m_str)
{
	slots = '1';
	pNextTask[redirect] = nullptr;
	pNextTask[passed] = nullptr;
	bool m_more = true; //To being reading this boolean must be true
	size_t m_next_pos = 0; //Position where the token begins extraction

	//Constructor creates a utilities object
	Utilities tempobj;

	tempobj.setFieldWidth(field_width); //retrieves field width

	name = tempobj.nextToken(m_str, m_next_pos, m_more);

	if (m_more == true) slots = tempobj.nextToken(m_str, m_next_pos, m_more);
	if (m_more == true) nextTask[passed] = tempobj.nextToken(m_str, m_next_pos, m_more);
	if (m_more == true) nextTask[redirect] = tempobj.nextToken(m_str, m_next_pos, m_more);
	if (tempobj.getFieldWidth() > field_width) field_width = tempobj.getFieldWidth();
}

bool Task::validate(const Task & task)
{
	bool m_tf = false;

	if (task.name == nextTask[passed]) pNextTask[passed] = &task;
	if (task.name == nextTask[redirect]) pNextTask[redirect] = &task;
	m_tf = (nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty() || pNextTask[redirect]);

	return m_tf;
}

const std::string & Task::getName() const
{
	return name;// TODO: insert return statement here
}

unsigned int Task::getSlots() const
{
	return stoi(slots);
}

const Task * Task::getNextTask(Quality quantity) const
{
	if (pNextTask[quantity] == nullptr)throw "*** Validate  [" + nextTask[quantity] + "] @ [" + name + "] ***";
	
	return pNextTask[quantity];
}

void Task::display(std::ostream &os) const
{
	size_t space = field_width + 4;
	os << string("Task Name    : ") << left << setw(space) << string("[" + name + "]") << string("[" + slots + "]")<< endl;

	if (nextTask[passed].empty() == false) 
	{
		os << string(" Continue to : ") << left << setw(space) << string("[" + nextTask[passed] + "]");
		if (pNextTask[passed] == nullptr) 
		{
			os << "*** to be validated ***" << endl;
		}
		else os << endl;
	}
	if (nextTask[redirect].empty() == false)
	{
		os << string(" Redirect to : ") << left << setw(space) << string("[" + nextTask[redirect] + "]");
		if (pNextTask[redirect] == nullptr)
		{
			os << "*** to be validated ***" << endl;
		}
		else os << endl;
	}
}

size_t Task::getFieldWidth()
{
	return field_width;
}

bool operator==(const Task &task_a, const Task &task_b)
{
	if (task_a.getName() == task_b.getName())
	{
		return true;
	}
	else return false;
}
