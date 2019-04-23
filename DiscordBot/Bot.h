#pragma once
#ifndef DISCORDBOT_H
#define DISCORDBOT_H

#include <string>
#include <vector>
#include "Module.h"


namespace Bot 
{
	struct addr
	{
		int port;
		std::string url;
	};

	class DiscordBot 
	{
		public:
			void bot_main();
			DiscordBot();
			DiscordBot(int server_port, std::string server_addr);
			DiscordBot(std::string base_addr, std::string bot_secret, std::string server_id, std::vector<std::string>mon_channel,std::vector<module>used_modules);
			void test();
			int send_message(std::string channel_id, std::string msg);
			void shut_down();
		private:
			bool running;
			addr server_addr;
			std::string bot_secret;
			std::string base_url;
			std::string server_id;
			std::vector<std::string> monitored_channels;
			std::vector<module> modules;
			
	};
}
#endif // !DiscordBot