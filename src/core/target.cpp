#include "sentinel_dbg/core/target.hpp"

#include <iostream>

namespace sentinel::core
{

void Target::attach()
{
    if(attached_)
    {
        std::cout << "Target already attached: " << name_ << "\n";
        return;
    }
    attached_ = true;
    std::cout << "Attached to target: " << name_ << "\n";
}

void Target::detach()
{
    if(!attached_)
    {
        return;
    }
    attached_ = false;
    std::cout << "Detached from target: " << name_ << "\n";
}

} // namespace sentinel::core
