//Sina Lahsaee
//129948162
#include "ItemManager.h"
void ItemManager::display(std::ostream &os, bool desc) const
{
	for (auto& temp : *this) temp.display(os, desc);
}
