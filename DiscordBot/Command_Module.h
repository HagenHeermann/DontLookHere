#include "Module.h"

class Command_Module: public module
{
	public:
		std::string call(Bot::DiscordBot bot, std::string msg);
		std::string get_module_name();
	private:
		std::string commands[1] = { "$test" };
};