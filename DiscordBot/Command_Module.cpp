#include "Command_Module.h"

std::string Command_Module::call( std::string msg)
{
	for(std::string command : commands)
	{
		if(msg == command)
		{
			if(command == "$test")
			{
				std::string res = "Test Message";
				return res;
			}
		}
		return "";
	}
	
}

std::string Command_Module::get_module_name()
{
	return "Command_Module";
}

std::string Command_Module::get_channel_id()
{
	return "493843755015864330";
}