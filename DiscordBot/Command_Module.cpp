#include "Command_Module.h"

std::string Command_Module::call(Bot::DiscordBot bot, std::string msg)
{
	for(std::string command : commands)
	{
		if(msg == command)
		{
			if(command == "$test")
			{
				bot.send_message("493843755015864330", "test");
			}
		}
	}
	
}