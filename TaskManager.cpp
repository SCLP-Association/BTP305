//Sina Lahsaee
//129948162
//File includes
#include "TaskManager.h"
#include "ItemManager.h"
#include "Task.h"
#include "Item.h"
//Library decleration
#include <algorithm>

using namespace std;
//vailating each task against one another and if an unvalidated task exists. it outputs it.
void TaskManager::validate(std::ostream &os)
{
	bool yes = true, no = true;
	vector<Task>::iterator temp, solid;

	//Bubblesort with iterators. To compare task by task
	for (temp = begin(); temp != end(); temp++)
	{
		no = true;

		for (solid = begin(); solid != end(); solid++)
		{
			if (temp->validate(*solid))
			{
				no = false;
			}
		}
		yes = !no;
	}

	//the if statement below prints out the error incase tasks are left unvalidated
	if (yes == false)
	{
		os << "*** Certain Tasks need to be validated ***" << endl;
	}
}

void TaskManager::validate(const ItemManager &itemManager, std::ostream &os)
{
	vector<Item>::const_iterator tempI;
	
	for (tempI = itemManager.begin(); tempI != itemManager.end(); tempI++)
	{

		const auto& rands = *tempI;

		//checks to see if task assigned is inside the container. lambda function that translates to bool (returns a bool)
		auto fill = [&](const Task& a)->bool
		{
			if (a.getName() == rands.getFiller())
			{
				return true;
			}
			else return false;
		};


		//checks to see if the task assigned is inside the container using the remover function
		auto rem = [&](const Task& a)->bool
		{
			if (a.getName() == rands.getRemover())
			{
				return true;
			}
			else return false;
		};

		//the following two if statements will insert a message into the OS stream saying that task is unavailable
		if (find_if(begin(), end(), fill) == this->end()) os << rands.getFiller() << " is unavailable" << endl;
		if (find_if(begin(), end(), rem) == this->end()) os << rands.getRemover() << " is unavailable" << endl;
	}
}
//displays the taskmanager object
void TaskManager::display(std::ostream &os) const
{
	for (auto& temp : *this) 
	{
		temp.display(os);
	};
}
