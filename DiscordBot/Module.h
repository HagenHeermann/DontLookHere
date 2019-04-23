#include <string>
#include "Bot.h"

class module
{
	public:
		 std::string call(std::string msg);
		 std::string get_module_name();
		 std::string get_channel_id();
};