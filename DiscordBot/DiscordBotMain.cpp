#include <windows.h> 
#include <fstream>
#include <iostream>
#include <iostream>
#include <json.hpp>
#include <curl/curl.h>
#include "Bot.h"

using namespace Bot;
using namespace nlohmann;

/*
	Global Variables
*/
Bot::DiscordBot running_bot;


BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	switch(fdwCtrlType)
	{
		case CTRL_C_EVENT:
			std::cout << "Trying shut down of Bot" << std::endl;
			running_bot.shut_down();
			return TRUE;
	}
}

int main()
{
	//Config init
	std::ifstream confreader;
	confreader.open("config.json");
	if (!confreader) 
	{
		// Config fail
		std::cout << "Failed to read config" << std::endl;
		return 1;
	}
	else
	{
		json configs;
		confreader >> configs;
		std::cout << configs["name"] << std::endl;
		
		if(SetConsoleCtrlHandler(CtrlHandler,TRUE))
		{
			
		}
		else
		{
			std::cout << "Failed to set control handler" << std::endl;
			return 1;
		}

		// curl global init
		//curl_global_init(CURL_GLOBAL_ALL);

		//Bot::DiscordBot bot(1,"pog");
		//bot.bot_main();
		
		curl_global_cleanup();
		return 0;
	}

}
