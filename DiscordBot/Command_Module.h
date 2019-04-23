#include "Module.h"

class Command_Module: public module
{
	public:
		std::string call(std::string msg);
		std::string get_module_name();
		std::string get_channel_id();
	private:
		std::string commands[1] = { "$test" };
};